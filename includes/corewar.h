/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 17:19:57 by vlaroque          #+#    #+#             */
/*   Updated: 2020/02/09 22:14:32 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H
# include <stdio.h>
# include <stdlib.h>
# include "op.h"
# include "libft.h"
typedef unsigned long long	t_llu;
# include "common.h"
typedef unsigned char		t_octet;

typedef struct			s_arg
{
	t_arg_type			type;
	int					len;
	unsigned int		content;
}						t_arg;

typedef struct			s_instruction
{
	int					op;
	unsigned int		pc;
	int					nbr_args;
	t_arg				args[4];
}						t_instruction;

/*
** register size determination
*/

# if REG_SIZE == 1
typedef unsigned char		t_reg;
# elif REG_SIZE == 2
typedef unsigned short		t_reg;
# elif REG_SIZE == 4
typedef unsigned int		t_reg;
# elif REG_SIZE == 8
typedef unsigned long long	t_reg;
# else
#  error register size not accepted
# endif

typedef struct			s_op
{
	char	*name;
	int		param_number;
	int		param_possible_types[4];
	int		op_code;
	int		cycle;
	char	*complete_name;
	int		encoding_byte;
	int		direct_size_two;
}						t_op;

typedef struct			s_process
{
	int					id;
	t_reg				pc;
	unsigned int		carry;
	t_reg				reg[REG_NUMBER];
	t_instruction		instruction;
	int					couldown;
	struct s_process	*next;
}						t_process;

/*
** used for bonus of champs number id
*/

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
int			mars_fill(t_data *data);

int			new_champ(t_data *data, char *source, t_champid *champ_id);

/*
** process_new
*/

int			new_process(t_data *data, int loc, int champ_id);
#endif
