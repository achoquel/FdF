/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 12:35:51 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/22 12:36:38 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

void	draw_esc(t_key *key, int x, int y)
{
	t_pos	pos;
	t_size	size;

	pos.x = x;
	pos.y = y;
	size.w = 80;
	size.h = 40;
	draw_rectangle(key->id, key->win, &pos, &size);
	mlx_string_put(key->id, key->win, x + 25, y + 7, 0x9adaf9, key->is);
	mlx_string_put(key->id, key->win, x + 130, y + 7, 0x9adaf9, key->help);
}

void	draw_key(t_key *key, int x, int y)
{
	t_pos	pos;
	t_size	size;

	pos.x = x;
	pos.y = y;
	size.w = 80;
	size.h = 80;
	draw_rectangle(key->id, key->win, &pos, &size);
	mlx_string_put(key->id, key->win, x + 35, y + 30, 0x9adaf9, key->is);
	mlx_string_put(key->id, key->win, x + 130, y + 30, 0x9adaf9, key->help);
}

void	setup1(t_key *key)
{
	key->is = "esc";
	key->help = "Close";
	draw_esc(key, 102, 60);
	key->is = "W";
	key->help = "";
	draw_key(key, 102, 125);
	key->is = "A";
	key->help = "";
	draw_key(key, 20, 207);
	key->is = "S";
	key->help = "";
	draw_key(key, 102, 207);
	key->is = "D";
	key->help = "Move";
	draw_key(key, 184, 207);
	key->is = "+";
	key->help = "";
	draw_key(key, 60, 312);
	key->is = "-";
	key->help = "Zoom";
	draw_key(key, 142, 312);
	key->is = "T";
	key->help = "Color Themes";
	draw_key(key, 102, 837);
}

void	setup2(t_key *key)
{
	key->is = "<";
	key->help = "";
	draw_key(key, 60, 417);
	key->is = ">";
	key->help = "Rotation";
	draw_key(key, 142, 417);
	key->help = "";
	key->is = "R";
	draw_key(key, 20, 522);
	key->is = "G";
	draw_key(key, 102, 522);
	key->is = "B";
	key->help = "Color Adjustment";
	draw_key(key, 184, 522);
	key->is = "^";
	key->help = "";
	draw_key(key, 60, 627);
	key->is = "v";
	key->help = "Altitude Adjustment";
	draw_key(key, 142, 627);
	key->is = "P";
	key->help = "Perspective";
	draw_key(key, 102, 732);
}

void	help_init(t_env *env)
{
	t_key	key;

	key.id = env->mlx_id;
	key.win = env->win_help;
	mlx_string_put(key.id, key.win, 213, 15, 0x42b9f4, "Hotkeys");
	draw_overlay1(env->mlx_id, env->win_help, env->hx, env->hy);
	setup1(&key);
	setup2(&key);
}
