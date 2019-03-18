/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:48:40 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/21 12:48:21 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	draw_rectangle(void *mlx_id, void *win_id, t_pos *pos, t_size *size)
{
	int	i;

	i = 0;
	while (i <= size->w)
	{
		mlx_pixel_put(mlx_id, win_id, pos->x + i, pos->y, 0x9adaf9);
		mlx_pixel_put(mlx_id, win_id, pos->x + i, pos->y + size->h, 0x9adaf9);
		++i;
	}
	i = 0;
	while (i <= size->h)
	{
		mlx_pixel_put(mlx_id, win_id, pos->x, pos->y + i, 0x9adaf9);
		mlx_pixel_put(mlx_id, win_id, pos->x + size->w, pos->y + i, 0x9adaf9);
		++i;
	}
}

void	draw_overlay1(void *mlx_id, void *win_id, int wx, int wy)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 6)
	{
		while (x != wx)
		{
			mlx_pixel_put(mlx_id, win_id, x, i, 0x42b9f4);
			mlx_pixel_put(mlx_id, win_id, x, wy - i, 0x42b9f4);
			++x;
		}
		x = 0;
		while (y != wy)
		{
			mlx_pixel_put(mlx_id, win_id, i, y, 0x42b9f4);
			mlx_pixel_put(mlx_id, win_id, wx - i, y, 0x42b9f4);
			++y;
		}
		y = 0;
		++i;
	}
}

void	draw_overlay2(void *mlx_id, void *win_id, int wx, int wy)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 6)
	{
		while (x != wx)
		{
			mlx_pixel_put(mlx_id, win_id, x, i, 0xfc0740);
			mlx_pixel_put(mlx_id, win_id, x, wy - i, 0xfc0740);
			++x;
		}
		x = 0;
		while (y != wy)
		{
			mlx_pixel_put(mlx_id, win_id, i, y, 0xfc0740);
			mlx_pixel_put(mlx_id, win_id, wx - i, y, 0xfc0740);
			++y;
		}
		y = 0;
		++i;
	}
}

int		rgb_to_hex(t_env *env)
{
	return ((env->r << 16) | (env->g << 8) | env->b);
}

void	line(t_env *env)
{
	env->dx = abs(env->x2 - env->x);
	env->xincr = env->x < env->x2 ? 1 : -1;
	env->dy = abs(env->y2 - env->y);
	env->yincr = env->y < env->y2 ? 1 : -1;
	env->err = (env->dx > env->dy ? env->dx : -env->dy) / 2;
	while (1)
	{
		if ((env->x > 0 && env->x < 1920 && env->y > 0 && env->y < 1080) \
			&& (env->y * env->mx + env->x < 1920 * 1080))
			env->img.data[env->y * env->mx + env->x] = env->color;
		if (env->x == env->x2 && env->y == env->y2)
			break ;
		env->tmperr = env->err;
		if (env->tmperr > -env->dx)
		{
			env->err -= env->dy;
			env->x += env->xincr;
		}
		if (env->tmperr < env->dy)
		{
			env->err += env->dx;
			env->y += env->yincr;
		}
	}
}
