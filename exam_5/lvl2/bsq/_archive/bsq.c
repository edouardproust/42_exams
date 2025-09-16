#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int 	rows, cols;
	char	empty, obstacle, full;
	char**	grid;
} Map;

int	ft_strlen(char* s) {
	int i = 0;
	while (s[i] != 0) i++;
	return i;
}

void	free_map(Map* map, int max_rows, FILE* file) {
	if (stdin != file) fclose(file);
	if (!map) return;
	for (int i = 0; i < map->rows; i++) {
		if (i == max_rows) break;
		free(map->grid[i]);		
	}
	free(map->grid);
	free(map);
	return;
}

Map*	read_file(FILE* file) {
	Map* map = malloc(sizeof(Map));
	if (4 != fscanf(file, "%d %c %c %c\n", &map->rows, &map->empty, &map->obstacle, &map->full)) {
		return (free_map(map, 0, file), NULL);
	}
	for (int i = 0; i < map->rows; i++) {
		char *line = NULL;
		size_t n = 0;
		if (getline(&line, &n, file) != -1) {
			return (free_map(map, i, file), NULL);
		}
		// TODO remove newline
		int len = ft_strlen(line);
		if (i == 0) {
			map->cols = len;
		} else if (len != map->cols) {
			return (free_map(map, i, file), NULL);
		}
		map->grid[i] = line;
	}
	return map;
}

int	validate_map(Map* map) {
	if (!map) {
		return 0;
	}
	return 1;
}


void	process_file(char *filename) {
	FILE* file = filename ? fopen(filename, "r") : stdin;
	if (!file) {
		//TODO
	}
	Map* map = read_file(file);
	if (!validate_map(map)) {
		fprintf(stderr, "map error\n");
		return free_map(map, 0, file);
	}
	// DEBUG
	fprintf(stdout, "%d, %c, %c, %c\n", map->rows, map->empty, map->obstacle, map->full);
	for (int i = 0; i < map->rows; i++) {
		fprintf(stdout, "%s\n", map->grid[i]);
	}
}

int main(int ac, char**av) {
	if (ac  == 1) {
		process_file(NULL);
	} else {
		for (int i = 1; i < ac; i++) {
			process_file(av[i]);
		}
	}
	return 0;
}
