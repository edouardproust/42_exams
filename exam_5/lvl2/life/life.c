#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_error() {
	char* msg = "error\n";
	for (int i = 0; msg[i]; i++) {
		putchar(msg[i]);
	}
	return 1;
}

int main(int ac, char** av) {
	if (ac != 4) {
		return ft_error();
	}
	int w = atoi(av[1]), h = atoi(av[2]), iter = atoi(av[3]);
	int board[h][w], next[h][w];
	// Init board
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			board[y][x] = 0;
		}
	}

	// Read input
	char buf[1024];
	int bytes_read, y = 0, x = 0, is_writing = 0;
	while ((bytes_read = read(0, buf, 1024)) > 0) {
		for (int i = 0; i < bytes_read; i++) {
			if (buf[i] == 'w' && y > 0) y--;
			else if (buf[i] == 'a' && x > 0) x--;
			else if (buf[i] == 's' && y < h - 1) y++;
			else if (buf[i] == 'd' && x < w - 1) x++;
			else if (buf[i] == 'x') is_writing = !is_writing;
			if (is_writing) board[y][x] = 1;
		}
	}
	// Iterations
	for (int i = 0; i < iter; i++) {
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				int n = 0;
				for (int dy = -1; dy <= 1; dy++) {
					for (int dx = -1; dx <= 1; dx++) {
						if ((x + dx >= 0) && (x + dx < w) && (y + dy >= 0) && (y + dy < h)) {
							if (board[y + dy][x + dx] == 1) n++;	
						}
					}
				}
				// Life conditions
				if (board[y][x] == 1) {
					n--; // important
					if (n == 2 || n == 3) next[y][x] = 1;
					else next[y][x] = 0;	
				} else if (n == 3) {
					next[y][x] = 1;
				} else {
					next[y][x] = 0;
				}
			}
		}
		// Copy next on board
		for (int y = 0; y < h; y++) {
			for (int x = 0; x < w; x++) {
				board[y][x] = next[y][x];
			}
		}
	}
	// print result
	for (int y = 0; y < h; y++) {
		for (int x = 0; x < w; x++) {
			if (board[y][x] == 0) putchar(' ');
			else if (board[y][x] == 1) putchar('0');
		}
		putchar('\n');
	}

	return 0;
}
