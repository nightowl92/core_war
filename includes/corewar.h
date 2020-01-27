/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:19:57 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/27 20:26:31 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <stdio.h>
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
	int					fd;
	int					id;
	t_octet				content[CHAMP_MAX_SIZE];
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
	struct s_champ		*next;
}						t_champ;

typedef struct			s_data
{
	t_octet				mars[MEM_SIZE];
	int					colors[MEM_SIZE];
	t_process			*processes;
	int					nbr_champs;
	t_champ				*champs;
}						t_data;

/*
** debug
*/
int			show_mars(t_data *data);
int			battle(t_data *data);

/*
** init
*/
int			init(t_data *data, int ac, char **av);



int			new_champ(t_data *data, char *source, int id);
#endif
