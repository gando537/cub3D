/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putstr_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:48:29 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:48:32 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	putstr_info_cmd(void)
{
	ft_putstr_fd("\nCub3D : \n", 1);
	ft_putstr_fd("\n./Cub3D <\"name\".cub>", 1);
	ft_putstr_fd("\n./Cub3D <\"name\".cub> <--save>\n", 1);
	ft_putchar_fd('\n', 1);
	exit(-1);
}
