#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int ac, char** av) {
	if (ac != 4) return 1;
	// Init vars and board
	int x = 0, y = 0, is_writing = 0;
	int w = atoi(av[1]), h = atoi(av[2]), iters = atoi(av[3]);
	int board[h][w], next[h][w];
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			board[y][x] = 0;
		}
	}
	// Read input
	char c;
	while (read(0, &c, 1) > 0) {
		if (c == 'w' && y > 0) y--;
		else if (c == 'a' && x > 0) x--;
		else if (c == 's' && y < h-1) y++;
		else if (c == 'd' && x < w-1) x++;
		else if (c == 'x') is_writing = !is_writing;
		else if (c != '\n') return 1;
		if (is_writing) board[y][x] = 1;
	}
	// Iterations
	for (int i = 0; i < iters; i++) {
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				int n = 0;
				for (int dy = -1; dy <= 1; dy++) {
					for (int dx = -1; dx <= 1; dx++) {
						n += (dy || dx) && (y + dy >= 0) && (x + dx >= 0) && (y + dy < h) && (x + dx < w) && board[y + dy][x + dx];
					}
				}
				next[y][x] = (board[y][x] && (n == 2 || n == 3)) || (!board[y][x] && n == 3); 
			}
		}
		// Copy next on board
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				board[y][x] = next[y][x];
			}
		}
	}
	// Print result
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			putchar(board[y][x] ? '0': ' ');
		}
		putchar('\n');
	}
	return 0;
}
