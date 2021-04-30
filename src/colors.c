/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/31 15:50:54 by fbes          #+#    #+#                 */
/*   Updated: 2021/04/30 16:37:08 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// the << operator below is a bite shift operator.
// 11100101 << 1 would produce 11001010, as all bits
// are shifted to the left by 1 bit. The blank spaces
// at the end are filled by zeroes. The | is an OR operator.
// see https://en.wikipedia.org/wiki/Bitwise_operations_in_C

unsigned int	color_to_uint(t_col_rgba *color)
{
	return (color->a << 24 | color->r << 16 | color->g << 8 | color->b);
}

t_col_rgba	uint_to_color(unsigned int color)
{
	t_col_rgba	tcol;

	tcol.a = 0xFF & (color >> 24);
	tcol.r = 0xFF & (color >> 16);
	tcol.g = 0xFF & (color >> 8);
	tcol.b = 0xFF & (color);
	return (tcol);
}

// below function is quite slow when using it for every pixel in a frame

unsigned int	brighten(unsigned int color)
{
	unsigned int	saturate;

	saturate = ((color & 0x80808080) >> 7) * 255;
	return (((color & 0x7F7F7F7F) << 1) | saturate | 0x01010101);
}

unsigned int	darken(unsigned int color)
{
	return ((color >> 1) & 8355711);
}
