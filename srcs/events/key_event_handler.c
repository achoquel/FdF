/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 09:53:40 by achoquel          #+#    #+#             */
/*   Updated: 2019/03/18 12:46:03 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	reset_status(t_env *env)
{
	mlx_clear_window(env->mlx_id, env->win_status);
	status_init(env);
}

void	reset_main(t_env *env)
{
	mlx_clear_window(env->mlx_id, env->win_main);
	draw_fdf(env);
}

void	state1(int key, t_env *env)
{
	if (key == 13 || key == 1 || key == 0 || key == 2 || key == 69 || key == 78)
		move_handler(key, env);
	if (key == 123 || key == 124)
		rotation_handler(key, env);
	if (key == 126 || key == 125)
		altitude_handler(key, env);
	if (key == 15 || key == 5 || key == 11 || key == 80)
		color_handler(key, env);
	if (key == 35)
		perspective_handler(env);
	if (key == 17)
		theme_handler(env);
}

void	start(t_env *env)
{
	env->state = 1;
	cam_center(env);
	reset_main(env);
	env->win_help = mlx_new_window(env->mlx_id, env->hx, env->hy, "FdF - Help");
	help_init(env);
	env->win_status = mlx_new_window(env->mlx_id, env->sx, env->sy, \
	"FdF - Status");
	status_init(env);
}

int		main_hooks(int key, t_env *env)
{
	if (key == 53)
		esc_handler(env);
	if (env->state == 1)
	{
		if (key == 13 || key == 1 || key == 0 || key == 2 || key == 69
		|| key == 78 || key == 123 || key == 124 || key == 126 || key == 125
		|| key == 15 || key == 5 || key == 11 || key == 80 || key == 35
		|| key == 17)
			state1(key, env);
	}
	else
	{
		if (key == 49)
			start(env);
	}
	return (0);
}
