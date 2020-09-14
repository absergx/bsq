/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 11:54:52 by memilio           #+#    #+#             */
/*   Updated: 2020/02/26 13:55:11 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_str.h"

int	ft_strlen_n(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\n' && str[len] != '\0')
	{
		len++;
	}
	return (len);
}

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
		++len;
	return (len);
}
