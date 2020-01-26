/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:19:57 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/23 20:33:35 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include "op.h"

typedef unsigned char	t_octet;
typedef struct			s_process
{
	int					id;
	int					couldown;
	struct s_process	*next;
}						t_process;

typedef struct			s_data
{
	t_octet				mars[MEM_SIZE];
	int					colors[MEM_SIZE];
	t_process			*processes;
}						t_data;

/*
** champion
*/

typedef struct			s_champ
{
	int			prog_id;
	header_t	header;
}						t_champ;

/*
** debug
*/
int			show_mars(t_data *data);
int			battle(t_data *data);

#endif
