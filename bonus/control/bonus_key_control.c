/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_key_control.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:20:33 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:20:50 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	bonus_key_manager(t_window *win_infos)
{
	if (win_infos->keybuffer->cam_up == 1)
		turn_up(win_infos);
	if (win_infos->keybuffer->cam_down == 1)
		turn_down(win_infos);
	return (SUCCES);
}

int	bonus_event_key_released(int key, t_window *win_infos)
{
	if (key == CAMUP && win_infos->keybuffer->cam_up == 1)
		win_infos->keybuffer->cam_up = 0;
	else if (key == CAMDOWN && win_infos->keybuffer->cam_down == 1)
		win_infos->keybuffer->cam_down = 0;
	return (SUCCES);
}

int	bonus_event_key_pressed(int key, t_window *win_infos)
{
	if (key == CAMUP && win_infos->keybuffer->cam_up == 0)
		win_infos->keybuffer->cam_up = 1;
	else if (key == CAMDOWN && win_infos->keybuffer->cam_down == 0)
		win_infos->keybuffer->cam_down = 1;
	else if (key == 78)
		remove_health(win_infos, 2);
	else if (key == 69)
		add_health(win_infos, 2);
	return (SUCCES);
}
