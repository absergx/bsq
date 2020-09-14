/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:35:02 by memilio           #+#    #+#             */
/*   Updated: 2020/02/26 19:25:42 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_str.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int		get_map_len(char *filename)
{
	int		fo;
	int		len;
	char	buf[100];
	ssize_t	byte;

	len = 0;
	fo = open(filename, O_RDONLY);
	while ((byte = read(fo, &buf, 100)))
	{
		len += byte;
	}
	close(fo);
	return (len);
}

void	ft_split_legend(char *str)
{
	t_chel	*pars;
	char	*leg;
	int		i;

	i = 0;
	leg = (char *)malloc(sizeof(char) * ft_strlen_n(str) + 1);
	while (*str != '\n')
	{
		leg[i] = *str;
		++i;
		++str;
	}
	leg[i] = '\0';
	++str;
	pars = (ft_get_params(leg));
	ft_split_map(str, pars);
	free(leg);
}

void	ft_split_map(char *str, t_chel *pars)
{
	int		i;
	char	*map;

	i = 0;
	map = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (*str != '\0')
	{
		map[i] = *str;
		++i;
		++str;
	}
	map[i] = '\0';
	pars = (ft_get_map(pars, map));
}

void	get_arg(char *filename)
{
	char			*mem;
	char			*start;
	int				fo;
	ssize_t			byte;

	mem = (char *)malloc(sizeof(char) * get_map_len(filename));
	start = mem;
	fo = open(filename, O_RDONLY);
	if (mem == NULL)
		return ;
	while ((byte = read(fo, mem, 1000)))
	{
		mem += byte;
	}
	*mem = '\0';
	close(fo);
	ft_split_legend(start);
	free(start);
}

int		map_validate(t_chel *pars)
{
	int i;
	int len_count;
	int height_count;

	i = 0;
	height_count = 0;
	while ((pars->map)[i] != '\0')
	{
		if (((pars->map)[i] == '\n') && (len_count == pars->len))
		{
			len_count = 0;
			++height_count;
			++i;
		}
		else if ((pars->map)[i] != pars->obs && (pars->map)[i] != pars->empty)
			return (0);
		else
		{
			++i;
			++len_count;
		}
	}
	if (height_count != pars->height)
		return (0);
	return (1);
}
