/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:43:11 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:43:13 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	hud(t_window *win_infos)
{
	char	*str;
	char	*itoa;

	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr,
		25, win_infos->height - 130, 0x2ECC71, "Look Up : /\\ , Look down : \\/");
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr,
		25, win_infos->height - 110, 0x2ECC71, "Look left : <, Look right : >");
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25,
		win_infos->height - 90, 0x2ECC71,
		"Forwars : W , Backward : S , Left : A, Right : D");
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25,
		win_infos->height - 70, 0x2ECC71, "Leave Game : ESC");
	str = ft_strjoin("Map name test: ", win_infos->map->map_name);
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25,
		win_infos->height - 50, 0x2ECC71, str);
	itoa = ft_itoa(win_infos->width);
	str = ft_strjoin("Width : ", itoa);
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25,
		win_infos->height - 30, 0x2ECC71, str);
	itoa = ft_itoa(win_infos->height);
	str = ft_strjoin("Height : ", itoa);
	mlx_string_put(win_infos->mlx_ptr, win_infos->win_ptr, 25,
		win_infos->height - 10, 0x2ECC71, str);
	return ;
}

static void	draw(t_window *win_infos)
{
	if (!(raycasting(win_infos)))
		leave(0, win_infos, "");
	hud(win_infos);
}

int	loop_manager(void *param)
{
	t_window	*win_infos;

	win_infos = (t_window *)param;
	draw(win_infos);
	draw_health(win_infos);
	key_manager(win_infos);
	play_music(win_infos);
	return (SUCCES);
}
