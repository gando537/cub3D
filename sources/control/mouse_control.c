/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:43:21 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:43:23 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	mouse_manager(int button, int x, int y, void *param)
{
	t_window	*mlx_infos;

	mlx_infos = (t_window *)param;
	putstr_info_int("Button : ", button, 1);
	putstr_info_int("X : ", x, 1);
	putstr_info_int("Y : ", y, 1);
	return (0);
}
