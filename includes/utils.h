/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:24:43 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:24:49 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <fcntl.h>

void	putstr_info_int(char *str, int i, int fd);
void	putstr_info_char(char *str, char c, int fd);
void	putstr_info_str(char *str, char *st, int fd);
void	putstr_info_cmd(void);

int		get_next_line(int fd, char **line);

int		is_whitespace(int c);

#endif