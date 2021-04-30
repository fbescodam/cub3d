/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printer.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/31 15:31:47 by fbes          #+#    #+#                 */
/*   Updated: 2021/04/30 17:37:37 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	print_error(char *msg)
{
	printf("Error\n%s\n", msg);
	strerror(errno);
	return (-1);
}

void	print_color(t_col_rgba color)
{
	printf("R%i, G%i, B%i, A%i\n", (int)color.r, (int)color.g,
		(int)color.b, (int)color.a);
}

void	print_level(t_map map, char **lvl)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!lvl)
		lvl = map.lvl;
	while (i < map.lvl_h)
	{
		j = 0;
		while (j < map.lvl_w)
		{
			printf("%c", lvl[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	print_map(t_map map, char **lvl)
{
	printf("res_x: %i\nres_y: %i\n", (int)map.res_x, (int)map.res_y);
	printf("tex_no: %s\ntex_so: %s\n", map.tex_no->file_path, map.tex_so->file_path);
	printf("tex_we: %s\ntex_ea: %s\n", map.tex_we->file_path, map.tex_ea->file_path);
	printf("tex_sprite: %s\ncol_floor: 0x%X", map.tex_sprite->file_path, map.col_floor);
	printf("\ncol_ceiling: 0x%X\n\n", map.col_ceiling);
	printf("lvl_w: %zu, lvl_h: %zu\n", map.lvl_w, map.lvl_h);
	print_level(map, lvl);
}
