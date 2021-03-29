/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 20:24:02 by fbes          #+#    #+#                 */
/*   Updated: 2021/03/29 21:08:39 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

static void	create_img(t_mlx_ctx *ctx, t_map *map)
{
	ctx->img = (t_img *)malloc(sizeof(t_img));
	ctx->img->img_ptr = mlx_new_image(ctx->core, map->res_x, map->res_y);
	ctx->img->address = mlx_get_data_addr(ctx->img->img_ptr,
			&ctx->img->bits_per_pixel, &ctx->img->line_size, &ctx->img->endian);
}

void	*free_mlx_context(t_mlx_ctx *ctx)
{
	if (ctx->win)
		mlx_destroy_window(ctx->core, ctx->win);
	if (ctx->img)
	{
		if (ctx->img->img_ptr)
			mlx_destroy_image(ctx->core, ctx->img->img_ptr);
		free(ctx->img);
	}
	free(ctx);
	return (NULL);
}

t_mlx_ctx	*get_mlx_context(t_map *map, char *win_title)
{
	t_mlx_ctx	*mlx_ctx;

	mlx_ctx = (t_mlx_ctx *)malloc(sizeof(t_mlx_ctx));
	if (mlx_ctx)
	{
		mlx_ctx->core = mlx_init();
		if (!mlx_ctx->core)
			return (free_mlx_context(mlx_ctx));
		mlx_ctx->win = mlx_new_window(mlx_ctx->core,
				map->res_x, map->res_y, win_title);
		if (!mlx_ctx->win)
			return (free_mlx_context(mlx_ctx));
		create_img(mlx_ctx, map);
		if (!mlx_ctx->img || !mlx_ctx->img->img_ptr)
			return (free_mlx_context(mlx_ctx));
	}
	return (mlx_ctx);
}
