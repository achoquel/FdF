/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_themes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 13:24:03 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/17 14:46:21 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

int		hex_reverted(t_env *env)
{
	return ((env->color & 0xFF000000) | (~env->color & 0x00FFFFFF));
}

void	color1(t_env *env)
{
	if (env->theme == 0)
	{
		env->color = rgb_to_hex(env);
	}
	else if (env->theme == 1)
	{
		env->color = rgb_to_hex(env);
		if (env->z != 0 || env->z2 != 0)
			env->color = hex_reverted(env);
	}
	else if (env->theme == 2)
	{
		env->color = rgb_to_hex(env);
		env->color = hex_reverted(env);
		if (env->z != 0 || env->z2 != 0)
			env->color = rgb_to_hex(env);
	}
	if (env->theme == 3)
	{
		env->color = 0xffcc00;
		if (env->z != 0 || env->z2 != 0)
			env->color = 0x9900cc;
	}
}

void	color_master(t_env *env)
{
	color1(env);
	if (env->theme == 4)
	{
		env->color = 0x6eeb9b;
		if (env->z != 0 || env->z2 != 0)
			env->color = 0x911464;
	}
	else if (env->theme == 5)
	{
		if (env->z >= 0 || env->z2 >= 0)
			env->color = 0xa2bef0;
		else if ((env->z < 0 && env->z > -60)
				|| (env->z2 < 0 && env->z2 > -60))
			env->color = 0x2b6b48;
		else if ((env->z < -60 && env->z > -100)
				|| (env->z2 < -60 && env->z2 > -100))
			env->color = 0xf3e288;
		else if ((env->z < -100 && env->z > -350)
				|| (env->z2 < -100 && env->z2 > -350))
			env->color = 0x864420;
		else
			env->color = WHITE;
	}
}
