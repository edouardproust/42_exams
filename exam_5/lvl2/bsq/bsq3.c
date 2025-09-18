#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int		rows, cols;
	char	empt, obst, full;
	char**	grid;
} Map;

void	ft_close(FILE* f) {
	if (f != stdin && f != stderr && f != stdout)
		fclose(f);
}

int	ft_min3(int a, int b, int c) {
	return a < b ? a : (b < c ? b : c);
}

void	free_grid_char(char** grid, int n) {
	if (!grid) return;
	for (int i = 0; i < n; i++) {
		free(grid[i]);
	}
	free(grid);
}

void	free_grid_int(int** grid, int n) {
	if (!grid) return;
	for (int i = 0; i < n; i++) {
		free(grid[i]);
	}
	free(grid);
}

void	map_error() {
	fprintf(stderr, "map error\n");
}

int	check_line_chars(char* line, ssize_t len, Map* m) {
	for (int i = 0; i < len; i++) {
		if (line[i] != m->empt && line[i] != m->obst) return 0;
	}
	return 1;
}

char**	parse_grid(FILE* f, Map* m) {
	char** grid = malloc(m->rows * sizeof(char*)); // TODO failure check
	int i = 0;
	while (i < m->rows) {
		char* line = NULL;
		size_t	n = 0;
		ssize_t len;
		if ((len = getline(&line, &n, f)) == -1) // check m->rows == grid lines
			return (free(line), free_grid_char(grid, i), NULL);
		if (len == -1) break;
		if (line[len - 1] == '\n') {
			len--;
			line[len] = '\0'; 
		}
		if (i == 0) m->cols = len;
		else if (len != m->cols)
			return (free(line), free_grid_char(grid, i), NULL);
		if (!check_line_chars(line, len, m))
			return (free(line), free_grid_char(grid, i), NULL);
		grid[i++] = line;
	}
	if (i == 0 || m->cols == 0) {
		printf("DEBUG: %d %d\n", i, m->rows);
		return (free_grid_char(grid, i), NULL);
	}
	return grid;
}

Map*	parse_map(FILE* f) {
	Map* m = calloc(1, sizeof(Map)); // TODO failure check
	if (fscanf(f, "%d %c %c %c\n", &m->rows, &m->empt, &m->obst, &m->full) != 4
		|| m->empt == m->obst || m->empt == m->full || m->obst == m->full) {
		return (free(m), NULL);
	}
	m->grid = parse_grid(f, m);
	if (!m->grid) {
		return (free(m), NULL);
	}
	return m;
}

void	solve_bsq(Map* m) {
	int** tmp = malloc(m->rows * sizeof(int*)); // TODO failure check
	int side = 0, start_y = 0, start_x = 0;
	for (int y = 0; y < m->rows; y++) {
		tmp[y] = calloc(m->cols, sizeof(int)); // TODO failure check
		for (int x = 0; x < m->cols; x++) {
			if (m->grid[y][x] == m->obst) tmp[y][x] = 0;
			else if (y == 0 || x == 0) tmp[y][x] = 1;
			else tmp[y][x] = ft_min3(tmp[y-1][x], tmp[y][x-1], tmp[y-1][x-1]) + 1;
			if (tmp[y][x] > side) {
				side = tmp[y][x];
				start_y = y - side + 1;
				start_x = x - side + 1;
			}
		}
	}
	// Update map with square
	for (int y = start_y; y < start_y + side; y++) {
		for (int x = start_x; x < start_x + side; x++) {
			m->grid[y][x] = m->full;
		}
	}
	// free
	free_grid_int(tmp, m->rows);
}

void	print_result(Map* m) {
	for (int y = 0; y < m->rows; y++) {
		fprintf(stdout, "%s\n", m->grid[y]);
	}
}

void	process_file(char* filename) {
	FILE* f = filename ? fopen(filename, "r"): stdin;
	if (!f) return map_error();
	Map* m = parse_map(f);
	if (!m) return (ft_close(f), map_error());
	solve_bsq(m);
	print_result(m);
	ft_close(f);
	free_grid_char(m->grid, m->rows);
	free(m);
}

int main(int ac, char** av) {
	if (ac == 1) {
		process_file(NULL);
	} else {
		for (int i = 1; i < ac; i++) {
			process_file(av[i]);
		}
	}
	return 0;
}
