/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <achoquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:28:05 by achoquel          #+#    #+#             */
/*   Updated: 2019/03/18 12:47:07 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	cam_center(t_env *env)
{
	if (env->perspective == 1 || env->perspective == 0)
	{
		env->xcam = (1.2 * (env->zoom + 1920 / 2) - env->zoom / 2);
		env->ycam = (-0.2 * (env->zoom + 1080 / 2) - env->zoom / 2);
	}
	else
	{
		env->xcam = 0.5 * (1920 - env->xmax * env->zoom);
		env->ycam = 0.5 * (1080 - env->ymax * env->zoom);
	}
}

void	draw_fdf(t_env *env)
{
	env->img.img_id = mlx_new_image(env->mlx_id, env->mx, env->my);
	env->img.data = (int *)mlx_get_data_addr(env->img.img_id, &env->img.bpp, \
	&env->img.size_l, &env->img.endian);
	draw_collumns(env);
	draw_lines(env);
	mlx_put_image_to_window(env->mlx_id, env->win_main, env->img.img_id, 0, 0);
	mlx_destroy_image(env->mlx_id, env->img.img_id);
}

void	vars_init(t_env *env, char *argv)
{
	env->mx = 1920;
	env->my = 1080;
	env->hx = 500;
	env->hy = 930;
	env->sx = 500;
	env->sy = 425;
	env->rot = 0;
	env->zoom = 10;
	env->alt = 0;
	env->r = 255;
	env->g = 255;
	env->b = 255;
	env->perspective = 0;
	env->map = argv;
	env->color = rgb_to_hex(env);
	env->theme = 0;
	cam_center(env);
}

int		env_init(t_env *env, char *argv)
{
	if (fdf_parser(env) == 1)
		return (1);
	env->mlx_id = mlx_init();
	vars_init(env, argv);
	env->win_main = mlx_new_window(env->mlx_id, env->mx, env->my, "FdF");
	waiting_screen(env);
	mlx_key_hook(env->win_main, main_hooks, env);
	mlx_loop(env->mlx_id);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	env;
	int		fd;

	if (argc != 2)
		return (error(0));
	if ((fd = open(argv[1], O_RDONLY)) < 2)
		return (error(1));
	env.fd = fd;
	if (env_init(&env, argv[1]) == 1)
		return (1);
	return (0);
}
