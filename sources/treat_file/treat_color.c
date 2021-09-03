/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:46:35 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:46:38 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_line_format(char *str, int c, \
	int first_char_pos, t_window *win_infos)
{
	int	i;

	if (!str || str[first_char_pos] != c \
		|| !is_whitespace(str[first_char_pos + 1]))
		return (ERROR);
	i = first_char_pos + 1;
	while (is_whitespace(str[i]))
		i++;
	while (ft_isdigit(str[i]) || str[i] == ',')
		i++;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] != '\0')
		leave(1, win_infos, \
			ft_strjoin("Error\nColor string format :", str));
	return (SUCCES);
}

static int	get_color_from_rgb(int r, int g, int b)
{
	int	rgb;

	rgb = r;
	rgb = (rgb << 8) + g;
	rgb = (rgb << 8) + b;
	return (rgb);
}

static int	get_num_color(int c, char *line, int *i, t_window *win_infos)
{
	int	color;

	color = ft_atoi(&line[*i]);
	if (color < 0 || color > 255)
		return (ERROR_INF);
	while (ft_isdigit(line[*i]))
		*i += 1;
	*i += 1;
	return (color);
}

int	color_from_string(char *line, int c, \
	int first_char_pos, t_window *win_infos)
{
	int	rgb;
	int	r;
	int	g;
	int	b;
	int	i;

	rgb = 0;
	if (!check_line_format(line, c, first_char_pos, win_infos))
		return (ERROR);
	i = first_char_pos + 1;
	while (is_whitespace(line[i]))
		i++;
	r = get_num_color(r, line, &i, win_infos);
	g = get_num_color(g, line, &i, win_infos);
	b = get_num_color(b, line, &i, win_infos);
	if (r == ERROR_INF || g == ERROR_INF || b == ERROR_INF)
		return (ERROR);
	rgb = get_color_from_rgb(r, g, b);
	if (c == 'F')
		win_infos->color_floor = rgb;
	else if (c == 'C')
		win_infos->color_ceiling = rgb;
	free(line);
	return (SUCCES);
}
