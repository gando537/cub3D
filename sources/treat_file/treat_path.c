/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:47:25 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:47:27 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_size(char *str, int start)
{
	int	rtn;

	rtn = 0;
	while (ft_isprint(str[start + rtn]) && str[start + rtn] != '\t'
		&& str[start + rtn] != '\n' && str[start + rtn] != '\r'
		&& str[start + rtn] != '\v' && str[start + rtn] != ' ')
		rtn++;
	return (rtn);
}

static int	check_line_format(char *str)
{
	int	i;

	i = 0;
	if (check_char(str, &i) == ERROR)
		return (ERROR);
	i++;
	if (str[i] != 'O' && str[i] != 'E' && str[i] != 'A'
		&& !is_whitespace(str[i]))
		return (ERROR);
	i++;
	while (is_whitespace(str[i]))
		i++;
	if (str[i] != '.' && str[i + 1] != '/')
		return (ERROR);
	while (ft_isprint(str[i]) && !is_whitespace(str[i]) && str[i] != '\0')
		i++;
	if (!is_whitespace(str[i]) && str[i] != '\0')
		return (ERROR);
	while (is_whitespace(str[i]))
		i++;
	if (str[i] != '\0')
		return (ERROR);
	return (SUCCES);
}

static int	file_exists(char *fname)
{
	int	fd;
	int	fname_len;

	fname_len = ft_strlen(fname);
	fd = open(fname, O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		return (ERROR);
	}
	if (fname[fname_len - 1] != 'm' || fname[fname_len - 2] != 'p'
		|| fname[fname_len - 3] != 'x' || fname[fname_len - 4] != '.')
		return (ERROR);
	return (SUCCES);
}

int	path_from_string(char *line, t_first_chars *fc, \
	int first_char_pos, t_window *win_infos)
{
	char	*path;
	int		i;

	if (!check_line_format(line))
		leave(1, win_infos, ft_strjoin("Error\nPath Line format : ", line));
	assign_i(&i, line, first_char_pos);
	while (is_whitespace(line[i]))
		i++;
	path = ft_substr(line, i, get_size(line, i));
	if (!path || !file_exists(path))
		leave(1, win_infos, ft_strjoin("Error\nInvalid Path : ", line));
	if (fc->c0 == 'N' && fc->c1 == 'O')
		return (set_texture(win_infos, path, 0));
	else if (fc->c0 == 'S' && fc->c1 == 'O')
		return (set_texture(win_infos, path, 1));
	else if (fc->c0 == 'W' && fc->c1 == 'E')
		return (set_texture(win_infos, path, 2));
	else if (fc->c0 == 'E' && fc->c1 == 'A')
		return (set_texture(win_infos, path, 3));
	else if (fc->c0 == 'S' && fc->c1 == ' ')
		return (stock_sprite(path, win_infos));
	else if (fc->c0 == 'H' && fc->c1 == ' ')
		return (set_texture(win_infos, path, 4));
	return (SUCCES);
}
