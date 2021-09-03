/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:46:23 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:46:24 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_char(char *str, int *i)
{
	while (is_whitespace(str[*i]))
		*i += 1;
	if (str[*i] != 'N' && str[*i] != 'S' && str[*i] != 'W'
		&& str[*i] != 'E' && str[*i] != 'H')
		return (ERROR);
	return (SUCCES);
}

void	assign_i(int *i, char *line, int first_char_pos)
{
	if (line[first_char_pos + 1] == ' ')
		*i = first_char_pos + 2;
	else
		*i = first_char_pos + 3;
}

int	alloc_line_mapstr(char **line, char **map_string)
{
	*map_string = malloc(sizeof(char) * 2);
	if (!(*map_string))
		return (ERROR);
	ft_bzero(*map_string, sizeof(char));
	*line = malloc(sizeof(char));
	if (!(*line))
		return (ERROR);
	ft_bzero(*line, sizeof(char));
	return (SUCCES);
}
