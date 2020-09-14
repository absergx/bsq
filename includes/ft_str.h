/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memilio <memilio@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:24:35 by memilio           #+#    #+#             */
/*   Updated: 2020/02/26 15:55:44 by memilio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STR_H
# define FT_STR_H

# ifndef BUF_SIZE
#  define BUF_SIZE 300000000
# endif

typedef	struct	s_chel
{
	char		*map;
	char		empty;
	char		obs;
	char		full;
	int			len;
	int			height;
	int			**magic;
}				t_chel;

t_chel			*ft_create_elem(void);
t_chel			*ft_get_params(char *str);
t_chel			*ft_get_map(t_chel *pars, char *str);
int				ft_atoi(char *str);
int				map_validate(t_chel *pars);
int				ft_strlen_n(char *str);
int				ft_strlen(char *str);
void			get_arg(char *filename);
void			get_input(void);
int				**ft_get_magic(t_chel *pars);
void			ft_print_arr(t_chel *pars);
void			ft_find_magic(t_chel *pars);
void			ft_split_legend(char *str);
void			ft_split_map(char *str, t_chel *pars);

#endif
