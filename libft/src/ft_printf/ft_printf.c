/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:41:42 by vpoltave          #+#    #+#             */
/*   Updated: 2017/06/22 13:39:48 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_eb	k;

	k.outn = 0;
	va_start(ap, format);
	while (*format)
	{
		prep_clear(&k);
		while ((*format != '%') && (*format))
		{
			k.outn++;
			ft_putchar(*format++);
		}
		if (*format == '%' && &(*format++))
			ft_get(ap, &format, &k);
		ft_strdel(&g_tmp);
		*format ? format++ : 0;
	}
	va_end(ap);
	return (k.outn);
}

void	ft_get(va_list ap, const char **format, t_eb *k)
{
	k->sp = "sSpdDioOuUxXcCn";
	k->fl = "#0-+#.*123456789 hljz";
	while (ft_strchr(k->fl, **format) && (**format))
	{
		if (ft_specdig(**format) || **format == '*')
			fck_width(ap, format, k);
		if (**format == '.')
			fck_preco(ap, format, k);
		found_flago(format, k);
		((ft_strchr(k->fl, **format))) ? (*format)++ : 0;
	}
	ft_strchr(k->sp, **format) ? biggest_modifier(k, format) : 0;
	if (ft_strchr(k->sp, **format) && (**format))
		found_speco(format, ap, k);
	else
	{
		k->space = 0;
		k->dst = ft_strnew(1);
		k->dst[0] = **format;
		found_width(k, format, 0);
		k->dst != NULL ? ft_strdel(&k->dst) : 0;
	}
}

void	found_flago(const char **format, t_eb *k)
{
	(**format == '-') ? (k->minus = 1) : 0;
	(**format == '+') ? (k->plus = 1) : 0;
	(**format == ' ') ? (k->space = 1) : 0;
	(**format == '#') ? (k->hash = 1) : 0;
	(**format == '0') ? (k->zero = 1) : 0;
	found_hhll(format, k);
	(**format == 'j') ? (k->j = 1) : 0;
	(**format == 'z') ? k->z = 1 : 0;
}

void	found_hhll(const char **format, t_eb *k)
{
	if (**format == 'h')
	{
		k->hcount++;
		if (k->hcount % 2 != 0)
			k->h = 1;
		else
		{
			k->hh = 1;
			k->h = 0;
		}
	}
	if (**format == 'l')
	{
		k->lcount++;
		if (k->lcount % 2 != 0)
			k->l = 1;
		else
			k->ll = 1;
	}
}

void	found_speco(const char **format, va_list ap, t_eb *k)
{
	((**format == 'd') || (**format == 'i')) ? ft_dec(ap, k, format) : 0;
	((**format == 's') && (k->l != 1)) ? ft_string(ap, k, format) : 0;
	((**format == 'S') || (**format == 's' && (k->l))) ?
	ft_bigs(ap, k, format) : 0;
	(**format == 'o') ? ft_ooctal(ap, k, format) : 0;
	(**format == 'O') ? ft_looctal(ap, k, format) : 0;
	(**format == 'x') ? ft_xhex(ap, k, format) : 0;
	(**format == 'X') ? ft_xhex(ap, k, format) : 0;
	(**format == 'u') ? ft_udec(ap, k, format) : 0;
	(**format == 'U') ? ft_ludec(ap, k, format) : 0;
	((**format == 'c') && (k->l != 1)) ? ft_char(ap, k, format) : 0;
	(**format == 'C' || (**format == 'c' && k->l)) ? ft_char(ap, k, format) : 0;
	(**format == 'D') ? ft_lddec(ap, k, format) : 0;
	(**format == 'n') ? ft_n(ap, k) : 0;
	if (**format == 'p')
	{
		k->hash = 1;
		k->l = 1;
		ft_xhex(ap, k, format);
	}
}
