/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:23:00 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:23:29 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_sound(t_window *win_infos)
{
	win_infos->sound = malloc(sizeof(t_sound));
	if (!(win_infos->sound))
		return (ERROR);
	ft_bzero(win_infos->sound, sizeof(t_sound));
	win_infos->sound->last_start_song = clock();
	system("afplay -v 0.30 bonus/sound/new-world-sound.mp3 &>/dev/null &");
	return (SUCCES);
}
