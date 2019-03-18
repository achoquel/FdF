/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:25:22 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/30 09:29:49 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	esc_handler(t_env *env)
{
	if (env->state == 1)
	{
		if (!env->win_help)
			mlx_destroy_window(env->mlx_id, env->win_help);
		if (!env->win_status)
			mlx_destroy_window(env->mlx_id, env->win_status);
	}
	mlx_destroy_window(env->mlx_id, env->win_main);
	close(env->fd);
	exit(0);
}

void	color_handler(int key, t_env *env)
{
	if (key == 15)
	{
		if (env->r == 0)
			env->r = 255;
		else
			env->r -= 5;
	}
	if (key == 5)
	{
		if (env->g == 0)
			env->g = 255;
		else
			env->g -= 5;
	}
	if (key == 11)
	{
		if (env->b == 0)
			env->b = 255;
		else
			env->b -= 5;
	}
	env->color = rgb_to_hex(env);
	reset_status(env);
	reset_main(env);
}

void	perspective_handler(t_env *env)
{
	if (env->perspective == 3)
		env->perspective = 0;
	else
		++env->perspective;
	cam_center(env);
	reset_main(env);
	reset_status(env);
}

void	theme_handler(t_env *env)
{
	if (env->theme == 5)
		env->theme = 0;
	else
		++env->theme;
	reset_main(env);
	reset_status(env);
}
