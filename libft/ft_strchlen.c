/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchlen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:libft/ft_strchlen.c
/*   Created: 2020/02/05 18:03:20 by stherkil          #+#    #+#             */
/*   Updated: 2020/02/05 18:03:22 by stherkil         ###   ########.fr       */
=======
/*   Created: 2018/11/12 11:15:22 by vlaroque          #+#    #+#             */
/*   Updated: 2018/11/20 19:11:10 by vlaroque         ###   ########.fr       */
>>>>>>> e4f6ee8af640b74478e23c9b3d940b677adee35a:libft/ft_strlen.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

<<<<<<< HEAD:libft/ft_strchlen.c
int		ft_strchlen(const char *s, char ch)
=======
size_t	ft_strlen(const char *c)
>>>>>>> e4f6ee8af640b74478e23c9b3d940b677adee35a:libft/ft_strlen.c
{
	size_t i;

	i = 0;
<<<<<<< HEAD:libft/ft_strchlen.c
	c = (char*)s;
	while (*c && *c != ch)
	{
		c++;
=======
	while (c[i])
>>>>>>> e4f6ee8af640b74478e23c9b3d940b677adee35a:libft/ft_strlen.c
		i++;
	return (i);
}
