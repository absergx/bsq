/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_magic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:18:07 by memilio           #+#    #+#             */
/*   Updated: 2020/02/26 18:25:04 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../includes/ft_str.h"

void	ft_print_magic(int i_max, int j_max, int value, t_chel *pars)
{
	int i;
	int j;
	int x;
	int temp;

	i = 0;
	while (i < value)
	{
		j = 0;
		temp = j_max;
		while (j < value)
		{
			x = (temp + (i_max * ((pars->len) + 1)));
			(pars->map)[x] = pars->full;
			--temp;
			++j;
		}
		--i_max;
		++i;
	}
	write(1, pars->map, ((pars->len + 1) * (pars->height)));
	free(pars);
}

int		ft_find_min(int x, int y, int z)
{
	if ((x >= y) && (z >= y))
		return (y);
	else if ((y >= x) && (z >= x))
		return (x);
	else
		return (z);
}

void	ft_find_magic(t_chel *pars)
{
	int i;
	int j;
	int i_max;
	int j_max;
	int value;

	i = 0;
	value = 0;
	while (i < (pars->height))
	{
		j = 0;
		while (j < (pars->len))
		{
			if ((pars->magic)[i][j] > value)
			{
				value = (pars->magic)[i][j];
				i_max = i;
				j_max = j;
			}
			++j;
		}
		++i;
	}
	ft_print_magic(i_max, j_max, value, pars);
}

int		ft_sawing_magic(int i, int k, t_chel *pars, int **magic)
{
	int j;
	int res;

	j = 0;
	res = 0;
	magic[k] = (int *)malloc(sizeof(int) * (pars->len));
	while ((pars->map)[i] != '\n')
	{
		if ((pars->map)[i] == (pars->obs))
		{
			magic[k][j] = 0;
		}
		else
		{
			if (k == 0 || j == 0)
				magic[k][j] = 1;
			else
				magic[k][j] = (ft_find_min(magic[k][j - 1],
				magic[k - 1][j], magic[k - 1][j - 1])) + 1;
		}
		++i;
		++j;
		++res;
	}
	return (res);
}

int		**ft_get_magic(t_chel *pars)
{
	int i;
	int k;
	int **magic;

	i = 0;
	k = 0;
	magic = (int **)malloc(sizeof(int *) * (pars->height));
	if ((magic) == NULL)
		return (NULL);
	while ((pars->map)[i] != '\0')
	{
		i += ft_sawing_magic(i, k, pars, magic);
		++i;
		++k;
	}
	return (magic);
}
