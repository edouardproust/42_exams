/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eproust <contact@edouardproust.dev>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:37:58 by eproust           #+#    #+#             */
/*   Updated: 2024/11/14 16:01:03 by eproust          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct	s_point
{
	int	x;
	int	y;
}	t_point;

/*
 * Depth First Search algorythm 
 * applied to all 4 directions: down, up, left, right
 */
static void	dfs(char **area, int r, int c, int c_max, int r_max, char character)
{
	// Exit cases: be outside of the area, or be on another character
	if (r < 0 || r > r_max || c < 0 || c > c_max || area[r][c] != character)
		return ;
	area[r][c] = 'F'; // flood pixel
	dfs(area, r - 1, c, c_max, r_max, character); // move down
	dfs(area, r + 1, c, c_max, r_max, character); // move up
	dfs(area, r, c - 1, c_max, r_max, character); // move left
	dfs(area, r, c + 1, c_max, r_max, character); // move right
}

/*
 * 'r' stands for 'row'
 * 'c' stands for 'column'
 */
void	flood_fill(char **area, t_point size, t_point begin)
{
	int	c = begin.x;
	int	r = begin.y;
	int	c_max = size.x - 1;
	int	r_max = size.y - 1;
`
	dfs(area, r, c, c_max, r_max, area[r][c]);
}

#include <stdlib.h>
#include <stdio.h>

char** make_area(char **zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

/*
int main(void)
{
	t_point size = {8, 5};
	t_point begin = {3, 3};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11000001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
*/
