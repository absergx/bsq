/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:00:10 by memilio           #+#    #+#             */
/*   Updated: 2020/04/29 15:40:33 by sergeyabramov    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "./includes/ft_str.h"

void	get_input(void)
{
	char		*mem_out;
	ssize_t		bit;
	char		*start;

	mem_out = malloc(sizeof(char) * BUF_SIZE);
	if (mem_out == NULL)
		return ;
	start = mem_out;
	while ((bit = read(0, mem_out, 1000)))
	{
		mem_out += bit;ƒ
	}
	*mem_out = '\0';
	ft_split_legend(start);
	free(start);
}

int		ft_check_opening(char *filename)
{
	int fo;

	fo = open(filename, O_RDONLY);
	if (fo < 0)
	{
		close(fo);
		write(2, "map error\n", 10);
		return (0);
	}
	else
	{
		close(fo);
		return (1);
	}
}

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			if ((ft_check_opening(argv[i])) == 1)
				get_arg(argv[i]);
			if (i < (argc - 1))
				write(1, "\n", 1);
			++i;
		}
	}
	else
		get_input();
	return (0);
}
