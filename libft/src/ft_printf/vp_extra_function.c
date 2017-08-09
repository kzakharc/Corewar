/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_extra_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:42:53 by vpoltave          #+#    #+#             */
/*   Updated: 2017/06/19 16:17:51 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** count digits for regular itoa_base
*/

int		count_dforiab(intmax_t value, int base)
{
	int i;

	i = 0;
	if ((value <= 0) && (base == 10))
		i++;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

/*
** count digits for (%O, %x %X etc) itoa_base
*/

int		count_dforixb(uintmax_t value, int base)
{
	int i;

	i = 0;
	while (value)
	{
		value /= base;
		i++;
	}
	return (i);
}

/*
** regular itoa_base
*/

void	iab(intmax_t value, int base, t_eb *k)
{
	intmax_t	i;
	int			j;

	j = count_dforiab(value, base);
	k->dst = (char *)malloc(sizeof(char) * (j + 1));
	k->dst[j] = '\0';
	if (value == 0)
		k->dst[0] = 48;
	if (value < 0 && base == 10)
		k->dst[0] = '-';
	while (value)
	{
		i = value % base;
		if (value < 0)
			i = -i;
		if (i > 9)
			i += 7;
		k->dst[j-- - 1] = (char)(i + 48);
		value /= base;
	}
}

/*
** (%O, %x %X etc) itoa_base
*/

void	ixb(uintmax_t value, int base, char const **format, t_eb *k)
{
	uintmax_t	i;
	int			j;

	j = count_dforixb(value, base);
	k->dst = (char *)malloc(sizeof(char) * (j + 1));
	k->dst[j] = '\0';
	if (value == 0)
		k->dst[0] = '0';
	while (value)
	{
		i = value % base;
		if ((i > 9) && (**format == 'X'))
			i += 7;
		else if ((i > 9) && (**format == 'x' || **format == 'p'))
			i += 39;
		k->dst[j-- - 1] = (char)(i + 48);
		value /= base;
	}
}

/*
** function that clear all flags and other shit
*/

void	prep_clear(t_eb *k)
{
	k->minus = 0;
	k->plus = 0;
	k->space = 0;
	k->hash = 0;
	k->zero = 0;
	k->h = 0;
	k->hh = 0;
	k->l = 0;
	k->ll = 0;
	k->j = 0;
	k->z = 0;
	k->w_n = 0;
	k->p_n = 0;
	k->width = 0;
	k->prec = 0;
	k->wcount = 0;
	k->pcount = 0;
	k->new = 0;
	k->neg = 0;
	k->lcount = 0;
	k->hcount = 0;
	k->dst = NULL;
}
