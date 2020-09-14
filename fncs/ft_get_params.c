/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 16:38:01 by memilio           #+#    #+#             */
/*   Updated: 2020/02/26 15:37:11 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../includes/ft_str.h"

t_chel		*ft_create_elem(void)
{
	t_chel *element;

	if (!(element = (t_chel *)malloc(sizeof(t_chel))))
		return (NULL);
	element->empty = 0;
	element->obs = 0;
	element->full = 0;
	element->len = 0;
	element->height = 0;
	element->map = NULL;
	element->magic = NULL;
	return (element);
}

t_chel		*ft_get_params(char *str)
{
	int			i;
	t_chel		*pars;

	pars = ft_create_elem();
	i = 0;
	while (str[i] != '\0')
		++i;
	pars->full = str[i - 1];
	pars->obs = str[i - 2];
	pars->empty = str[i - 3];
	str[i - 3] = 'a';
	pars->height = ft_atoi(str);
	return (pars);
}

t_chel		*ft_get_map(t_chel *pars, char *str)
{
	int i;

	i = 0;
	pars->len = ft_strlen_n(str);
	pars->map = (char *)malloc(sizeof(char) * (pars->len + 1) *
	pars->height + 1);
	while (str[i] != '\0')
	{
		(pars->map)[i] = str[i];
		++i;
	}
	(pars->map)[i] = '\0';
	free(str);
	if (map_validate(pars) == 0)
	{
		write(2, "map error\n", 10);
		return (0);
	}
	pars->magic = ft_get_magic(pars);
	ft_find_magic(pars);
	return (pars);
}
