/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parttwo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <stherkil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 11:01:42 by stherkil          #+#    #+#             */
/*   Updated: 2020/01/28 21:50:46 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/asm.h"

static t_op		op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
};

char			decitohex(int nb)
{
	return (nb);
}

void			putmax(char *NUM)
{
	int i;

	i = -1;
	while (++i < 8)
		NUM[i] = 'f';
}

void			hexlittle(char *NUM, long long nb)
{
	if (nb / 4294967296 > 0)
	{
		putmax(NUM);
		return ;
	}
	NUM[0] = decitohex(nb / 268435456);
	nb -= 268435456 * (nb / 268435456);
	NUM[1] = decitohex(nb / 16777216);
	nb -= 16777216 * (nb / 16777216);
	NUM[0] = NUM[0] * 16 + NUM[1];
	NUM[2] = decitohex(nb / 1048576);
	nb -= 1048576 * (nb / 1048576);
	NUM[3] = decitohex(nb / 65536);
	nb -= 65536 * (nb / 65536);


	NUM[1] = NUM[2] * 16 + NUM[3];
	NUM[4] = decitohex(nb / 4096);
	nb -= 4096 * (nb / 4096);
	NUM[5] = decitohex(nb / 256);
	nb -= 256 * (nb / 256);


	NUM[2] = NUM[4] * 16 + NUM[5];
	NUM[6] = decitohex(nb / 16);
	nb -= 16 * (nb / 16);
	NUM[7] = decitohex(nb);


	NUM[3] = NUM[6] * 16 + NUM[7];
}

void			asm_ld(instr_t *instr, unsigned char *BUF, int *bufptout)
{
	char NUM[8];
	int i;

	i = -1;
	BUF[*bufptout] = instr->instr;
	*bufptout += 1;
	BUF[*bufptout] = instr->enc;
	*bufptout += 1;
	printf("len is %d\n", instr->ptlen);
	while (++i < instr->ptlen)
	{
		hexlittle(NUM, instr->data[i]);
		BUF[*bufptout] = NUM[0];
		BUF[*bufptout + 1] = NUM[1];
		BUF[*bufptout + 2] = NUM[2];
		BUF[*bufptout + 3] = NUM[3];
		*bufptout += 4;
	}
}

void			parttwo(unsigned char *BUF, int *bufptout, header_t *header)
{
	int bufpt;

	//hexlittle(header->NUM, 42);
	bufpt = *bufptout;
	while (header->firstinstr->instr != -1)
	{
		asm_ld(header->firstinstr, BUF, &bufpt);
		header->firstinstr = header->firstinstr->next;
	}
/*	
	printf("big hex is %s\n", header->NUM);
	ft_memcpy(BUF + bufpt, header->NUM, 4);
	bufpt += 4;
	*/
	*bufptout = bufpt;
}
