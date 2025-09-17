#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_putstr(char* s) {
	for (int i = 0; s[i]; i++) {
		putchar(s[i]);
	}
	putchar('\n');
}

int	main(int ac, char** av) {
	if (ac != 4) {
		ft_putstr("error");
		return 1;
	}
	int w = atoi(av[1]), h = atoi(av[2]), iter = atoi(av[3]);
	// Init boards
	int board[h][w], next[h][w];
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++)
			board[y][x] = 0;
	}
	// Read input
	char c;
	int x = 0, y = 0, is_writing = 0;
	while (read(0, &c, 1) == 1) {
		if (c == 'w' && y > 0) y--;
		else if (c == 'a' && x > 0) x--;
		else if (c == 's' && y < h-1) y++;
		else if (c == 'd' && x < w-1) x++;
		else if (c == 'x') is_writing = !is_writing;
		if (is_writing) {
			board[y][x] = 1;
		}
	}
	// Iterations
	for (int i = 0; i < iter; i++) {
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < h; x++) {
				// Calc lives
				int lives = 0;
				for (int dy = -1; dy <= 1; dy++) {
					for (int dx = -1; dx <= 1; dx++) {
						if ((dy || dx) && (y + dy >= 0) && (y + dy < h) && (x + dx >= 0) && (x + dx < w)) {
							if (board[y + dy][x + dx] == 1) lives++;
						}
					}
				}
				// Set next based on lives
				next[y][x] = (board[y][x] && (lives == 2 || lives == 3))
					|| (!board[y][x] && lives == 3);
			}
		}
		// Copy board from next
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				board[y][x] = next[y][x];
			}
		}	
	}
	// Print result
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			putchar(board[y][x] ? '0' : ' ');
		}
		putchar('\n');
	}
	return 0;
}

