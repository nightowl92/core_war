/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:19:57 by vlaroque          #+#    #+#             */
/*   Updated: 2020/02/19 15:49:10 by stherkil         ###   ########.fr       */
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

/*
** champion
*/

typedef struct			s_champ
{
	int				magic_nbr;
	int				prog_id;
	header_t		header;
	struct s_champ	*next;

}						t_champ;


typedef struct			s_data
{
	t_octet				mars[MEM_SIZE];
	int					colors[MEM_SIZE];
	t_process			*processes;
	t_champ				*champs;
}						t_data;

/*
** debug
*/
int			show_mars(t_data *data);
int			battle(t_data *data);

#endif
