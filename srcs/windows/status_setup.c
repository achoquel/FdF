/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:38:22 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/24 09:35:32 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	status_vars(t_env *env)
{
	mlx_string_put(env->mlx_id, WSTAT, 80, 50, WHITE, env->map);
	mlx_string_put(env->mlx_id, WSTAT, 150, 80, WHITE, itoa_f(env->xcam));
	mlx_string_put(env->mlx_id, WSTAT, 150, 110, WHITE, itoa_f(env->ycam));
	mlx_string_put(env->mlx_id, WSTAT, 90, 140, WHITE, itoa_f(env->zoom));
	mlx_string_put(env->mlx_id, WSTAT, 130, 170, WHITE, itoa_f(env->rot));
	mlx_string_put(env->mlx_id, WSTAT, 60, 200, WHITE, itoa_f(env->r));
	mlx_string_put(env->mlx_id, WSTAT, 60, 230, WHITE, itoa_f(env->g));
	mlx_string_put(env->mlx_id, WSTAT, 60, 260, WHITE, itoa_f(env->b));
	mlx_string_put(env->mlx_id, WSTAT, 130, 290, WHITE, itoa_f(-env->alt));
	if (env->perspective == 1 || env->perspective == 0)
		mlx_string_put(env->mlx_id, WSTAT, 160, 320, WHITE, "Isometric");
	else
		mlx_string_put(env->mlx_id, WSTAT, 160, 320, WHITE, "Parallel");
	if (env->theme == 0)
		mlx_string_put(env->mlx_id, WSTAT, 160, 350, WHITE, "RGB");
	else if (env->theme == 1)
		mlx_string_put(env->mlx_id, WSTAT, 160, 350, WHITE, "Inverted RGB 1");
	else if (env->theme == 2)
		mlx_string_put(env->mlx_id, WSTAT, 160, 350, WHITE, "Inverted RGB 2");
	else if (env->theme == 3)
		mlx_string_put(env->mlx_id, WSTAT, 160, 350, WHITE, "Yellow / Purple");
	else if (env->theme == 4)
		mlx_string_put(env->mlx_id, WSTAT, 160, 350, WHITE, "Cyan / Purple");
	else
		mlx_string_put(env->mlx_id, WSTAT, 160, 350, WHITE, "Terrain");
}

void	status_init(t_env *env)
{
	draw_overlay2(env->mlx_id, WSTAT, env->sx, env->sy);
	mlx_string_put(env->mlx_id, WSTAT, 203, 15, STA_R, "Variables");
	mlx_string_put(env->mlx_id, WSTAT, 20, 50, STA_L, "Map :");
	mlx_string_put(env->mlx_id, WSTAT, 20, 80, STA_L, "X Position :");
	mlx_string_put(env->mlx_id, WSTAT, 20, 110, STA_L, "Y Position :");
	mlx_string_put(env->mlx_id, WSTAT, 20, 140, STA_L, "Zoom :");
	mlx_string_put(env->mlx_id, WSTAT, 20, 170, STA_L, "Rotation :");
	mlx_string_put(env->mlx_id, WSTAT, 20, 200, STA_L, "R :");
	mlx_string_put(env->mlx_id, WSTAT, 20, 230, STA_L, "G :");
	mlx_string_put(env->mlx_id, WSTAT, 20, 260, STA_L, "B :");
	mlx_string_put(env->mlx_id, WSTAT, 20, 290, STA_L, "Altitude :");
	mlx_string_put(env->mlx_id, WSTAT, 20, 320, STA_L, "Perspective :");
	mlx_string_put(env->mlx_id, WSTAT, 20, 350, STA_L, "Color Theme :");
	mlx_string_put(env->mlx_id, WSTAT, 20, 368, WHITE, \
	"Some themes might not work with few map because");
	mlx_string_put(env->mlx_id, WSTAT, 20, 383, WHITE, \
	"they depend of the map's relief.");
	status_vars(env);
}
