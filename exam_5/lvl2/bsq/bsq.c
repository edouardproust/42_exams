#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int		rows, cols;
	char	empt, obst, full;
	char**	grid;
} Map;

void	ft_error(char* msg) {
	fprintf(stderr, "%s\n", msg);
}

void	ft_close(FILE* f) {
	if (f != stdin && f != stdout && f != stderr) fclose(f);
}

int	ft_min3(int a, int b, int c) {
	return a < b ? a : (b < c ? b : c);
}

void	free_grid_char(char** grid, int n) {
	if (!grid) return;
	for (int i = 0; i < n; i++) {
		if (grid[i]) free(grid[i]);
	}
	free(grid);
}

void	free_grid_int(int** grid, int n) {
	if (!grid) return;
	for (int i = 0; i < n; i++) {
		if (grid[i]) free(grid[i]);
	}
	free(grid);
}

int	check_line(char* line, Map* m, size_t len) {
	int i = 0;
	while (line[i]) {
		char c = line[i];
		if (c != m->empt && c != m->obst) return 0;
		i++;
	}
	if (len != (size_t)m->cols) return 0;
	return 1;
}

char**	parse_grid(FILE* f, Map* m) {
	char** grid = malloc(m->rows * sizeof(char*)); // TODO failure check
	int y = 0;
	while (y < m->rows) {
		char* line = NULL;
		size_t n = 0;
		size_t len = getline(&line, &n, f); // TODO failure check
		if (line[len - 1] == '\n') {
			len--;
			line[len] = '\0';
		}
		if (y == 0) m->cols = len;
		if (!check_line(line, m, len)) {
			free(line);
			free_grid_char(grid, y);
			return NULL;
		}
		grid[y++] = line;
	}
	if (y != m->rows) {
		free_grid_char(grid, m->rows);
		return NULL;
	}
	return grid;
}

Map*	parse_map(FILE* f) {
	Map* m = calloc(1, sizeof(Map)); // TODO failure check
	if ((fscanf(f, "%d %c %c %c\n", &m->rows, &m->empt, &m->obst, &m->full) != 4)
		|| (m->empt == m->obst || m->empt == m->full || m->obst == m->full)) {
		free(m);
		return NULL;
	}
	m->grid = parse_grid(f, m);
	if (!m->grid) {
		free(m);
		return NULL;
	}
	return m;
}

void	solve_bsq(Map* m) {
	int** tmp = malloc(m->rows * sizeof(int*)); // TODO failure check
	int side_len = 0, start_x = 0, start_y = 0;
	for (int y = 0; y < m->rows; y++) {
		tmp[y] = calloc(m->cols, sizeof(int)); // TODO failure check
		for (int x = 0; x < m->cols; x++) {
			if (m->grid[y][x] == m->obst) tmp[y][x] = 0;
			else if (y == 0 || x == 0) tmp[y][x] = 1;
			else tmp[y][x] = ft_min3(tmp[y-1][x], tmp[y][x-1], tmp[y-1][x-1]) + 1;
			if (tmp[y][x] > side_len) {
				side_len = tmp[y][x];
				start_x = x - side_len + 1;
				start_y = y - side_len + 1;
			}
		}
	}
	// Draw square on map
	for (int y = start_y; y < start_y + side_len; y++) {
		for (int x = start_x; x < start_x + side_len; x++) {
			m->grid[y][x] = m->full;
		}
	}
	// Cleanup
	free_grid_int(tmp, m->rows);
}

void	print_bsq(Map* m) {
	for (int y = 0; y < m->rows; y++) {
		fprintf(stdout, "%s\n", m->grid[y]);
	}
}

void process_file(char* filename) {
	FILE* f = filename ? fopen(filename, "r") : stdin;
	if (!f) {
		ft_error("map error");
		return;
	}
	Map* m = parse_map(f);
	if (!m) {
		ft_error("map error");
		ft_close(f);
		return;
	}
	solve_bsq(m);
	print_bsq(m);
	// Cleanup
	free_grid_char(m->grid, m->rows);
	free(m);
	ft_close(f);	
}

int	main(int ac, char** av) {
	if (ac == 1) {
		process_file(NULL);
	} else {
		for (int i = 1; i < ac; i++) {
			process_file(av[i]);
		}
	}
}
