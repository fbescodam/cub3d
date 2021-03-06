/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   window.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fbes <fbes@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/03/29 20:24:02 by fbes          #+#    #+#                 */
/*   Updated: 2021/05/27 17:39:12 by fbes          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "c3d.h"
#include "mlx.h"

static void	create_img(t_mlx_ctx *ctx, t_map *map)
{
	ctx->img.img_ptr = mlx_new_image(ctx->core, map->res_x, map->res_y);
	ctx->img.address = mlx_get_data_addr(ctx->img.img_ptr,
			&ctx->img.bits_per_pixel, &ctx->img.line_size, &ctx->img.endian);
}

static void	catch_max_res_exception(t_map *map, void *mlx_ptr)
{
	int		scr_x;
	int		scr_y;

	mlx_get_screen_size(mlx_ptr, &scr_x, &scr_y);
	if (map->res_x > scr_x)
		map->res_x = scr_x;
	if (map->res_y > scr_y)
		map->res_y = scr_y;
}

void	*free_mlx_context(t_mlx_ctx *ctx)
{
	if (ctx->img.img_ptr)
		mlx_destroy_image(ctx->core, ctx->img.img_ptr);
	if (ctx->win)
		mlx_destroy_window(ctx->core, ctx->win);
	ft_free(ctx);
	return (NULL);
}

t_mlx_ctx	*get_mlx_context(t_map *map)
{
	t_mlx_ctx	*mlx_ctx;

	mlx_ctx = (t_mlx_ctx *)malloc(sizeof(t_mlx_ctx));
	if (mlx_ctx)
	{
		mlx_ctx->core = mlx_init();
		if (!mlx_ctx->core)
			return (free_mlx_context(mlx_ctx));
		mlx_ctx->win = NULL;
		create_img(mlx_ctx, map);
		if (!mlx_ctx->img.img_ptr)
			return (free_mlx_context(mlx_ctx));
	}
	return (mlx_ctx);
}

int	create_win(t_game *game, char *win_title)
{
	catch_max_res_exception(game->map, game->mlx->core);
	game->mlx->win = mlx_new_window(game->mlx->core,
			game->map->res_x, game->map->res_y, win_title);
	if (!game->mlx->win)
		return (-1);
	return (0);
}
