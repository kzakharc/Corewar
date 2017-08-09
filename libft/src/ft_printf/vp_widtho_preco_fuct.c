/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_widtho_preco_fuct.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:43:43 by vpoltave          #+#    #+#             */
/*   Updated: 2017/06/21 18:10:09 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	found_preco(t_eb *k)
{
	char	*str;
	int		i;

	i = 0;
	k->pcount = ((k->p_n) - (int)(ft_strlen(k->dst)) + k->neg);
	if (k->pcount <= 0 && !(k->pcount = 0))
		return ;
	str = k->dst;
	g_tmp = ft_strnew((size_t)k->pcount);
	while (k->pcount--)
		g_tmp[i++] = '0';
	if (k->neg)
	{
		k->dst = ft_strjoin(g_tmp, k->dst + 1);
		k->dst = ft_strjoin("-", k->dst);
	}
	else
		k->dst = ft_strjoin(g_tmp, k->dst);
	ft_strdel(&str);
}

void	found_width(t_eb *k, const char **format, int flag)
{
	k->wcount = (int)((k->w_n) - (ft_strlen(k->dst)) - flag);
	if (k->wcount <= 0 && !(k->wcount = 0))
		print_wany(k, format);
	else if (k->minus == 1)
		print_yminus(k, format);
	else if (k->minus == 0 && !(k->zero))
		print_nminus(k, format);
	else if (k->zero)
		print_zero(k, format);
}

void	print_zero(t_eb *k, const char **format)
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
	if (k->neg)
		ft_putchar('-');
	k->hash ? hash_func(k, format) : 0;
	while (k->wcount-- && write(1, "0", 1))
		k->outn++;
	if (**format == 'd' || **format == 'i')
		(!(k->neg)) ? ft_putstr(k->dst) : ft_putstr(k->dst + 1);
	else
		ft_putstr(k->dst);
	(k->dst[0] == 0 && (**format == 'c' || **format == 'C')) ?
	write(1, k->dst, 1) : 0;
	k->outn += ft_strlen(k->dst);
	((**format != 's') && (k->dst != NULL) && !(k->prec)) ?
	ft_strdel(&k->dst) : 0;
}

void	print_nminus(t_eb *k, const char **format)
{
	while (k->wcount-- && write(1, " ", 1))
		k->outn++;
	if ((k->space && !(k->neg)) ? k->outn++ : 0)
		ft_putchar(' ');
	if ((k->plus && !(k->neg)) ? k->outn++ : 0)
		ft_putchar('+');
	k->hash ? hash_func(k, format) : 0;
	(k->dst[0] == 0 && (**format == 'c' || **format == 'C')) ?
		write(1, &k->dst[0], 1) : ft_putstr(k->dst);
	k->outn += ft_strlen(k->dst);
	((**format != 's') && (k->dst != NULL) && !(k->prec)) ?
	ft_strdel(&k->dst) : 0;
}

void	print_yminus(t_eb *k, const char **format)
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
	(k->dst[0] == 0 && (**format == 'c' || **format == 'C')) ?
		write(1, &k->dst[0], 1) : ft_putstr(k->dst);
	(k->dst[0] == 0 && **format == 'c') ? write(1, &k->dst[0], 1) : 0;
	k->outn += ft_strlen(k->dst);
	while (k->wcount-- && write(1, " ", 1))
		k->outn++;
	((**format != 's') && (k->dst != NULL) && !(k->prec)) ?
	ft_strdel(&k->dst) : 0;
}
