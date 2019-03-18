/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:13:53 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/24 14:36:16 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	rotation(t_env *env)
{
	float	rad;

	rad = env->rot * PI / 180;
	if (env->perspective == 0 || env->perspective == 1)
	{
		env->x = (env->x * cos(rad)) - (env->y * sin(rad));
		env->y = (env->x * sin(rad)) + (env->y * cos(rad));
		env->x2 = (env->x2 * cos(rad)) - (env->y2 * sin(rad));
		env->y2 = (env->x2 * sin(rad)) + (env->y2 * cos(rad));
	}
	else
	{
		env->x = (env->x * cos(rad)) + (env->z * sin(rad));
		env->z = (env->x * (-sin(rad))) + (env->z * cos(rad));
		env->x2 = (env->x2 * cos(rad)) + (env->z2 * sin(rad));
		env->z2 = (env->x2 * (-sin(rad))) + (env->z2 * cos(rad));
	}
}

void	perspective(t_env *env)
{
	if (env->perspective == 1 || env->perspective == 3)
	{
		env->z *= -1;
		env->z2 *= -1;
	}
	if (env->perspective == 0 || env->perspective == 1)
	{
		env->x = 0.70710678118 * (env->x - env->y);
		env->y = 0.40824829046 * (env->x + env->y) + 0.81649658092 * env->z;
		env->x2 = 0.70710678118 * (env->x2 - env->y2);
		env->y2 = 0.40824829046 * (env->x2 + env->y2) + 0.81649658092 * env->z2;
	}
	else
	{
		env->x = env->x + 0.3 * cos(PI / 4) * env->z;
		env->y = env->y + 0.3 * sin(PI / 4) * env->z;
		env->x2 = env->x2 + 0.3 * cos(PI / 4) * env->z2;
		env->y2 = env->y2 + 0.3 * sin(PI / 4) * env->z2;
	}
}

void	draw(t_env *env)
{
	if (env->z < 0)
		env->z += env->alt;
	if (env->z2 < 0)
		env->z2 += env->alt;
	rotation(env);
	perspective(env);
	color_master(env);
	line(env);
}

void	draw_lines(t_env *env)
{
	int	l;
	int	c;
	int	i;

	l = 0;
	i = 0;
	c = 0;
	while (l != env->ymax)
	{
		while (c != env->xmax - 1)
		{
			env->x = env->xcam + (env->zoom) * c;
			env->y = env->ycam + (env->zoom) * l;
			env->z = -ft_atoi(env->fmap[i]) * env->zoom;
			++c;
			++i;
			env->x2 = env->xcam + (env->zoom) * c;
			env->y2 = env->ycam + (env->zoom) * l;
			env->z2 = -ft_atoi(env->fmap[i]) * env->zoom;
			draw(env);
		}
		c = 0;
		++l;
		++i;
	}
}

void	draw_collumns(t_env *env)
{
	int	c;
	int	l;
	int	i;

	c = 0;
	l = 0;
	i = 0;
	while (l != env->xmax)
	{
		while (i + env->xmax < env->ymax * env->xmax)
		{
			env->x = env->xcam + env->zoom * l;
			env->y = env->ycam + env->zoom * c;
			env->z = -ft_atoi(env->fmap[i]) * env->zoom;
			i += env->xmax;
			++c;
			env->x2 = env->xcam + env->zoom * l;
			env->y2 = env->ycam + env->zoom * c;
			env->z2 = -ft_atoi(env->fmap[i]) * env->zoom;
			draw(env);
		}
		c = 0;
		++l;
		i = l;
	}
}
