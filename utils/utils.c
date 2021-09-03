/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:48:40 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:48:43 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_whitespace(int c)
{
	if (c == '\t' || c == '\n' || c == '\r'
		|| c == '\v' || c == '\f' || c == ' ')
		return (SUCCES);
	return (ERROR);
}