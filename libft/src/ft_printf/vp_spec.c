/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:43:09 by vpoltave          #+#    #+#             */
/*   Updated: 2017/06/21 18:07:37 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**  for %d
*/

void	ft_dec(va_list ap, t_eb *k, const char **format)
{
	k->hash = 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		(k->h == 1) ? (iab((short)(va_arg(ap, int)), 10, k)) : 0;
		(k->hh == 1) ? (iab((signed char)(va_arg(ap, int)), 10, k)) : 0;
		(k->l == 1) ? (iab((va_arg(ap, long)), 10, k)) : 0;
		(k->ll == 1) ? (iab((va_arg(ap, long long)), 10, k)) : 0;
		(k->j == 1) ? (iab((va_arg(ap, intmax_t)), 10, k)) : 0;
		(k->z == 1) ? (iab((va_arg(ap, size_t)), 10, k)) : 0;
	}
	else
		iab((va_arg(ap, int)), 10, k);
	((k->dst[0] == '0') && (k->p_n == 0) && k->prec) ? (ft_strclr(k->dst)) : 0;
	k->neg = (k->dst[0] == '-') ? 1 : 0;
	k->prec ? found_preco(k) : 0;
	if ((k->width) && ((k->w_n) > (int)(ft_strlen(k->dst))))
		(((k->plus) || (k->space)) && !(k->neg)) ? found_width(k, format, 1) :
		found_width(k, format, 0);
	else
		print_wany(k, format);
	ft_strdel(&k->dst);
}

/*
**  for %s
*/

void	ft_string(va_list ap, t_eb *k, const char **format)
{
	char *str;

	str = NULL;
	k->plus = 0;
	k->hash = 0;
	k->space = 0;
	k->dst = (va_arg(ap, char *));
	(k->dst == NULL) ? k->dst = "(null)" : 0;
	k->dst != NULL ? (str = ft_strnew((size_t)k->p_n)) : 0;
	if (k->prec && (k->p_n >= 0))
		((k->p_n < (int)ft_strlen(k->dst))) ?
			k->dst = ft_strncpy(str, k->dst, (size_t)k->p_n) : 0;
	(k->width) ? found_width(k, format, 0) : print_wany(k, format);
	str != NULL ? ft_strdel(&str) : 0;
}

/*
**  for unsigned octal %o
*/

void	ft_ooctal(va_list ap, t_eb *k, const char **format)
{
	k->plus = 0;
	k->space = 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		(k->h) ? (ixb((unsigned short)(va_arg(ap, int)), 8, 0, k)) : 0;
		(k->hh) ? (ixb((unsigned char)(va_arg(ap, int)), 8, 0, k)) : 0;
		(k->l) ? (ixb((va_arg(ap, unsigned long)), 8, 0, k)) : 0;
		(k->ll) ? (ixb((va_arg(ap, unsigned long long)), 8, 0, k)) : 0;
		(k->j) ? (ixb((va_arg(ap, uintmax_t)), 8, 0, k)) : 0;
		(k->z) ? (ixb((va_arg(ap, size_t)), 8, 0, k)) : 0;
	}
	else
		ixb((va_arg(ap, unsigned int)), 8, 0, k);
	(k->dst[0] == '0' && k->prec && !k->p_n) ? (ft_strclr(k->dst)) : 0;
	(k->dst[0] == '0' && !k->prec && k->hash) ? (ft_strclr(k->dst)) : 0;
	k->dst[0] == '0' ? k->hash = 0 : 0;
	(k->dst[0] == '0') ? k->dst[1] = '\0' : 0;
	k->hash ? (k->p_n -= 1) : 0;
	k->prec ? found_preco(k) : 0;
	k->hash ? (k->w_n -= 1) : 0;
	if ((k->width) && ((k->w_n) > (int)(ft_strlen(k->dst))))
		found_width(k, format, 0);
	else
		print_wany(k, format);
	k->hash ? free(k->dst) : 0;
}

/*
**  for %x and %X
*/

void	ft_xhex(va_list ap, t_eb *k, char const **format)
{
	k->plus = 0;
	k->space = 0;
	**format == 'p' ? k->space = 0 : 0;
	k->h ? ixb((unsigned short)(va_arg(ap, unsigned int)), 16, format, k) : 0;
	k->hh ? ixb((unsigned char)(va_arg(ap, unsigned int)), 16, format, k) : 0;
	(k->l) ? (ixb((va_arg(ap, unsigned long)), 16, format, k)) : 0;
	(k->ll) ? (ixb((va_arg(ap, unsigned long long)), 16, format, k)) : 0;
	(k->j) ? (ixb((va_arg(ap, uintmax_t)), 16, format, k)) : 0;
	(k->z) ? (ixb((va_arg(ap, size_t)), 16, format, k)) : 0;
	(k->dst == NULL) ? ixb((va_arg(ap, unsigned int)), 16, format, k) : 0;
	(k->dst[0] == '0' && **format != 'p') ? (k->hash = 0) : 0;
	if (k->dst[0] == '0')
		k->dst = ft_strdup("0");
	(k->dst[0] == '0' && k->prec && !k->p_n) ? (ft_strclr(k->dst)) : 0;
	(k->hash && **format != 'p' && **format != 'x' && **format != 'X') ?
	(k->p_n -= 2) : 0;
	(k->prec) ? found_preco(k) : 0;
	(k->hash) ? (k->w_n -= 2) : 0;
	((k->width) && ((k->w_n) > (int)(ft_strlen(k->dst)))) ?
	found_width(k, format, 0) : print_wany(k, format);
}

/*
**  for unsigned decimal %u
*/

void	ft_udec(va_list ap, t_eb *k, const char **format)
{
	k->plus = 0;
	k->space = 0;
	if ((k->h) || (k->hh) || (k->l) || (k->ll) || (k->j) || (k->z))
	{
		k->h ? (ixb((unsigned short)(va_arg(ap, unsigned int)), 10, 0, k)) : 0;
		k->hh ? (ixb((unsigned char)(va_arg(ap, unsigned int)), 10, 0, k)) : 0;
		(k->l) ? (ixb((va_arg(ap, unsigned long)), 10, 0, k)) : 0;
		(k->ll) ? (ixb((va_arg(ap, unsigned long long)), 10, 0, k)) : 0;
		(k->j) ? (ixb((va_arg(ap, uintmax_t)), 10, 0, k)) : 0;
		(k->z) ? (ixb((va_arg(ap, size_t)), 10, 0, k)) : 0;
	}
	else
		ixb((va_arg(ap, unsigned int)), 10, 0, k);
	(k->dst[0] == '0') ? k->dst[1] = '\0' : 0;
	(k->dst[0] == '0' && k->prec && !k->p_n) ? (ft_strclr(k->dst)) : 0;
	k->prec ? found_preco(k) : 0;
	if ((k->width) && ((k->w_n) > (int)(ft_strlen(k->dst))))
		found_width(k, format, 0);
	else
		print_wany(k, format);
}
