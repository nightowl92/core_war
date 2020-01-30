/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:19:57 by vlaroque          #+#    #+#             */
/*   Updated: 2020/01/30 15:01:42 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <stdio.h>
# include "op.h"
# include "libft.h"

typedef unsigned char	t_octet;
typedef struct			s_process
{
	int					id;
	int					couldown;
	struct s_process	*next;
}						t_process;

typedef struct			s_champid
{
	int					id;
	int					carry;
	int					carried_nbr;
}						t_champid;


/*
** champion
*/

typedef struct			s_champ
{
	int					id;
	t_octet				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	t_octet				comment[COMMENT_LENGTH + 1];
	t_octet				content[CHAMP_MAX_SIZE];
	struct s_champ		*next;
}						t_champ;

typedef struct			s_data
{
	t_octet				mars[MEM_SIZE];
	int					colors[MEM_SIZE];
	int					nbr_champs;
	t_champ				*champs;
	t_process			*processes;
}						t_data;

/*
** debug
*/
int			show_mars(t_data *data);
int			battle(t_data *data);
void		hex_dump(t_octet *src, size_t len);
int			champ_dump(t_champ *champ);

/*
** init
*/
int			init_corewar(t_data *data, int ac, char **av);



int			new_champ(t_data *data, char *source, t_champid *champ_id);
#endif
