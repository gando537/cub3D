/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:45:59 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:46:01 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_game_player(t_window *win_infos)
{
	win_infos->player = malloc(sizeof(t_player));
	if (!(win_infos->player))
		return (ERROR);
	ft_bzero(win_infos->player, sizeof(t_player));
	win_infos->player->posx = -20.0;
	win_infos->player->posy = -20.0;
	win_infos->player->speed = 0.10;
	win_infos->player->dir_x = 1.0;
	win_infos->player->dir_y = 0.0;
	win_infos->player->plane_x = -20.0;
	win_infos->player->plane_y = -20.0;
	win_infos->player->rotate_speed = 0.10;
	win_infos->player->cam_height = 1.0;
	win_infos->player->health = 20;
	return (SUCCES);
}

int	init_game_keybuffer(t_window *win_infos)
{
	win_infos->keybuffer = malloc(sizeof(t_keybuffer));
	if (!(win_infos->keybuffer))
		return (ERROR);
	ft_bzero(win_infos->keybuffer, sizeof(t_keybuffer));
	win_infos->keybuffer->toward = 0;
	win_infos->keybuffer->backward = 0;
	win_infos->keybuffer->left = 0;
	win_infos->keybuffer->right = 0;
	win_infos->keybuffer->turn_left = 0;
	win_infos->keybuffer->turn_right = 0;
	win_infos->keybuffer->cam_up = 0;
	win_infos->keybuffer->cam_down = 0;
	return (SUCCES);
}

int	init_game_map(t_window *win_infos, const char *map_name)
{
	win_infos->map = malloc(sizeof(t_map));
	if (!(win_infos->map))
		return (ERROR);
	ft_bzero(win_infos->map, sizeof(t_map));
	win_infos->map->map_name = map_name;
	win_infos->map->height = 0;
	win_infos->map->width = 0;
	return (SUCCES);
}

int	init_game_textures(t_window *win_infos, int nbr_textures)
{
	int	count;

	count = 0;
	win_infos->textures = malloc(sizeof(t_image *) * nbr_textures - 1);
	if (!(win_infos->textures))
		return (ERROR);
	while (count < nbr_textures)
	{
		win_infos->textures[count] = malloc(sizeof(t_image));
		if (!(win_infos->textures[count]))
			return (ERROR);
		ft_bzero(win_infos->textures[count], sizeof(t_image));
		count++;
	}
	return (SUCCES);
}

int	init_game_sprite(t_window *win_infos)
{
	win_infos->sprite = malloc(sizeof(t_image));
	if (!(win_infos->sprite))
		return (ERROR);
	ft_bzero(win_infos->sprite, sizeof(t_image));
	win_infos->sprites_on_screen = malloc(sizeof(t_list));
	if (!(win_infos->sprites_on_screen))
		return (ERROR);
	ft_bzero(win_infos->sprites_on_screen, sizeof(t_list));
	win_infos->sprites_on_screen->x = -1;
	win_infos->sprites_on_screen->y = -1;
	return (SUCCES);
}
