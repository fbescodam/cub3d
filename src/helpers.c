/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/05/07 16:35:40 by fbes          #+#    #+#                 */
/*   Updated: 2021/05/27 16:02:08 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"

void	item_free_simple(void *content)
{
	if (content)
		free(content);
}

char	*skip_spaces(char *c)
{
	while (*c && ft_iswhitespace(*c))
		c++;
	return (c);
}

char	*skip_non_spaces(char *c)
{
	while (*c && !ft_iswhitespace(*c))
		c++;
	return (c);
}

void	free_lines(char **lines)
{
	size_t	i;

	i = 0;
	while (lines[i])
	{
		if (lines[i])
			ft_free(lines[i]);
		i++;
	}
	ft_free(lines);
}

t_coords	*new_coords(int x, int y)
{
	t_coords	*coords;

	coords = (t_coords *)malloc(sizeof(t_coords));
	if (coords)
	{
		coords->x = x;
		coords->y = y;
	}
	return (coords);
}
