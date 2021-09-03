/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:35:26 by mdiallo           #+#    #+#             */
/*   Updated: 2021/04/27 19:35:31 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_hm(char const *s, char c)
{
	size_t	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (i > 0 && s[i] && s[i - 1] == c)
			nbr++;
		if (s[i])
			i++;
	}
	if (nbr == 0 && s[i - 1] == c)
		return (0);
	if (s[0] != c)
		nbr++;
	return (nbr);
}

static char	**ft_mal(char **strs, char const *s, char c)
{
	size_t	count;
	int		i;
	int		h;

	count = 0;
	i = 0;
	h = 0;
	while (s[h])
	{
		if (s[h] != c)
			count++;
		else if (h > 0 && s[h - 1] != c)
		{
			strs[i] = malloc(sizeof(char) * (count + 1));
			count = 0;
			i++;
		}
		if (s[h + 1] == '\0' && s[h] != c)
			strs[i] = malloc(sizeof(char) * count + 1);
		if (!strs[i])
			return (0);
		h++;
	}
	return (strs);
}

static char	**ft_cpy(char **strs, char const *s, char c)
{
	int	i;
	int	j;
	int	h;

	i = 0;
	j = 0;
	h = 0;
	while (s[h])
	{
		if (s[h] != c)
			strs[i][j++] = s[h];
		else if (h > 0 && s[h - 1] != c)
		{
			if (h != 0)
			{
				strs[i][j] = '\0';
				j = 0;
				i++;
			}
		}
		if (s[h + 1] == '\0' && s[h] != c)
			strs[i][j] = '\0';
		h++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		nbr_w;

	if (!s || !*s)
	{
		rtn = malloc(sizeof(char *) * 1);
		if (!rtn)
			return (NULL);
		*rtn = (void *)0;
		return (rtn);
	}
	nbr_w = ft_hm(s, c);
	rtn = malloc(sizeof(char *) * (nbr_w + 1));
	if (!rtn)
		return (0);
	if (ft_mal(rtn, s, c) != 0)
		ft_cpy(rtn, s, c);
	else
	{
		free(rtn);
		return (NULL);
	}
	rtn[nbr_w] = (void *)0;
	return (rtn);
}
