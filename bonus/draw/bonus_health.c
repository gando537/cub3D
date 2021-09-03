/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_health.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:21:56 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:22:35 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	add_health(t_window *win_infos, int amount)
{
	if (win_infos->player->health + amount > 20)
		win_infos->player->health = 20;
	else
		win_infos->player->health += amount;
}

void	remove_health(t_window *win_infos, int amount)
{
	if (win_infos->player->health - amount <= 0)
		leave(0, win_infos, "Game over!");
	else
		win_infos->player->health -= amount;
}

static void	health_img(t_window *win_infos)
{
	t_image	*img;
	double	img_width;
	int		x;
	int		y;

	img_width = (int)(((double)191 / (double)20)
			* (double)win_infos->player->health);
	img = new_image(win_infos, (int)img_width, 30);
	if (!img)
		leave(1, win_infos, "Error init image map");
	img->width = (int)img_width;
	img->height = 30;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			pixel_put_to_image(0x00FF00, x, y, img);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win_infos->mlx_ptr, win_infos->win_ptr,
		img->img_ptr, win_infos->width - 205, win_infos->height - 80);
}

void	draw_health(t_window *win_infos)
{
	health_img(win_infos);
	mlx_put_image_to_window(win_infos->mlx_ptr, win_infos->win_ptr,
		win_infos->textures[4]->img_ptr, win_infos->width - 250,
		win_infos->height - 100);
}
