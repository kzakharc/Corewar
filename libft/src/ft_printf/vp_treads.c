/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_treads.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:43:33 by vpoltave          #+#    #+#             */
/*   Updated: 2017/06/21 18:08:43 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hash_func(t_eb *k, const char **format)
{
	if (**format == 'o' || **format == 'O')
	{
		ft_putchar('0');
		k->outn++;
	}
	else if (**format == 'x' || **format == 'p')
	{
		ft_putstr("0x");
		k->outn += 2;
	}
	else if (**format == 'X')
	{
		ft_putstr("0X");
		k->outn += 2;
	}
}

void	print_wany(t_eb *k, const char **format)
{
	if (k->plus && !(k->neg))
	{
		ft_putchar('+');
		k->outn++;
	}
	if (k->space && !(k->neg))
	{
		ft_putchar(' ');
		k->outn++;
	}
	k->hash ? hash_func(k, format) : 0;
	(*k->dst == '\0' && (**format == 'c' || **format == 'C')) ?
	write(1, "\0", 1) : ft_putstr(k->dst);
	k->outn += ft_strlen(k->dst);
	((**format != 's') && (k->dst != NULL) && !(k->prec)) ?
	ft_strdel(&k->dst) : 0;
}

/*
** The number of characters written so far is stored into the
** integer indicated by the int *
*/

void	ft_n(va_list ap, t_eb *k)
{
	int *i;

	i = va_arg(ap, void *);
	*i = k->outn;
}
