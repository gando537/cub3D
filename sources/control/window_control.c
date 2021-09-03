/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:43:31 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:43:32 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	event_destroy_window(void *param)
{
	t_window	*win_infos;

	win_infos = (t_window *)param;
	leave(0, win_infos, "");
	return (SUCCES);
}
