/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:21:28 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:21:45 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	turn_up(t_window *win_infos)
{
	if (win_infos->player->cam_height + win_infos->player->rotate_speed < 2)
		win_infos->player->cam_height += win_infos->player->rotate_speed;
}

void	turn_down(t_window *win_infos)
{
	if (win_infos->player->cam_height - win_infos->player->rotate_speed > 0)
		win_infos->player->cam_height -= win_infos->player->rotate_speed;
}
