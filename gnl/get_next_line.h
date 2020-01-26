/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 18:11:03 by stherkil          #+#    #+#             */
/*   Updated: 2020/01/21 16:11:18 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../libft/libft.h"
# define BUFF_SIZE 32

int						get_next_line(const int fd, char **line);
typedef struct s_file	t_file;
struct					s_file
{
	int					i;
	size_t				len;
	char				*rest;
	t_file				*next;
};
#endif
