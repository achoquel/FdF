/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 10:20:39 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/21 09:56:17 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	move_handler(int key, t_env *env)
{
	if (key == 1)
		env->ycam += 10;
	if (key == 13)
		env->ycam -= 10;
	if (key == 2)
		env->xcam += 10;
	if (key == 0)
		env->xcam -= 10;
	if (key == 69)
		env->zoom += 1;
	if (key == 78)
		env->zoom -= 1;
	reset_status(env);
	reset_main(env);
}

void	rotation_handler(int key, t_env *env)
{
	if (key == 123)
	{
		if (env->rot == 0)
			env->rot = 355;
		else
			env->rot -= 5;
	}
	if (key == 124)
	{
		if (env->rot == 355)
			env->rot = 0;
		else
			env->rot += 5;
	}
	reset_status(env);
	reset_main(env);
}

void	altitude_handler(int key, t_env *env)
{
	if (key == 126)
		env->alt -= 5;
	if (key == 125)
		env->alt += 5;
	reset_status(env);
	reset_main(env);
}
