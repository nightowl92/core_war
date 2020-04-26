/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parttwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:01:42 by stherkil          #+#    #+#             */
/*   Updated: 2020/04/21 11:12:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

void			asm_ld(header_t *header, instr_t *instr, unsigned char *BUF, int *bufptout)
{
	int i;

	i = -1;
	BUF[*bufptout] = instr->instr;
	*bufptout += 1;
	if (instr->instr != 1)
	{
	BUF[*bufptout] = instr->enc;
	*bufptout += 1;
	}
	while (++i < instr->ptlen)
	{
		if (instr->instr == 1)
		{
			itobh(BUF, bufptout, instr->data[i]);
		}
		else
		{
			BUF[*bufptout] = instr->data[i];
			*bufptout += 1;
		}
	}
}

void			parttwo(unsigned char *BUF, int *bufptout, header_t *header)
{
	int bufpt;

	//hexlittle(header->NUM, 42);
	bufpt = *bufptout;
	while (header->firstinstr->instr != -1)
	{
		asm_ld(header, header->firstinstr, BUF, &bufpt);
		header->firstinstr = header->firstinstr->next;
	}
	/*	
		printf("big hex is %s\n", header->NUM);
		ft_memcpy(BUF + bufpt, header->NUM, 4);
		bufpt += 4;
		*/
	*bufptout = bufpt;
}
