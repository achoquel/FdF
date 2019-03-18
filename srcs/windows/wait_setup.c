/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 10:46:12 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/24 10:30:50 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	background(t_env *env)
{
	int	x;
	int	y;

	y = -1;
	env->state = 0;
	while (++y < env->my)
	{
		x = -1;
		while (++x < env->mx)
			env->img.data[y * env->mx + x] = 0x4181DB;
	}
}

void	draw_circle(t_circle *circle, t_env *env)
{
	env->img.data[circle->xc + circle->x + (circle->yc + circle->y) * \
	env->mx] = WHITE;
	env->img.data[circle->xc - circle->x + (circle->yc + circle->y) * \
	env->mx] = WHITE;
	env->img.data[circle->xc + circle->x + (circle->yc - circle->y) * \
	env->mx] = WHITE;
	env->img.data[circle->xc - circle->x + (circle->yc - circle->y) * \
	env->mx] = WHITE;
	env->img.data[circle->xc + circle->y + (circle->yc + circle->x) * \
	env->mx] = WHITE;
	env->img.data[circle->xc - circle->y + (circle->yc + circle->x) * \
	env->mx] = WHITE;
	env->img.data[circle->xc + circle->y + (circle->yc - circle->x) * \
	env->mx] = WHITE;
	env->img.data[circle->xc - circle->y + (circle->yc - circle->x) * \
	env->mx] = WHITE;
}

void	bres_circle(int xc, int yc, int r, t_env *env)
{
	t_circle	circle;
	int			d;

	circle.x = 0;
	circle.y = r;
	circle.yc = yc;
	circle.xc = xc;
	d = 3 - 2 * r;
	draw_circle(&circle, env);
	while (circle.y >= circle.x)
	{
		circle.x++;
		if (d > 0)
		{
			circle.y--;
			d = d + 4 * (circle.x - circle.y) + 10;
		}
		else
			d = d + 4 * circle.x + 6;
		draw_circle(&circle, env);
	}
}

void	federation(t_env *env)
{
	bres_circle(960, 540, 300, env);
	env->x = 960 - 325;
	env->y = 540 - 250;
	env->x2 = 960 + 325;
	env->y2 = 540 - 250;
	line(env);
	env->x = 960;
	env->y = 540 + 375;
	line(env);
	env->x = 960 - 325;
	env->y = 540 - 250;
	env->x2 = 960;
	env->y2 = 540 + 375;
	line(env);
}

void	waiting_screen(t_env *env)
{
	env->img.img_id = mlx_new_image(env->mlx_id, 1920, 1080);
	env->img.data = (int *)mlx_get_data_addr(env->img.img_id, &env->img.bpp, \
	&env->img.size_l, &env->img.endian);
	background(env);
	federation(env);
	mlx_put_image_to_window(env->mlx_id, env->win_main, env->img.img_id, 0, 0);
	mlx_string_put(env->mlx_id, env->win_main, 865, 960, env->color, \
	"PRESS SPACE TO START");
}
