/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vp_big_fck_S.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 15:42:37 by vpoltave          #+#    #+#             */
/*   Updated: 2017/06/21 18:53:27 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_bigs(va_list ap, t_eb *k, const char **format)
{
	found_ignored(k, format);
	k->utf = va_arg(ap, int *);
	if (k->utf != NULL)
	{
		while (*k->utf)
		{
			if (k->prec && (k->p_n >= 0))
				preco_for_bs(k, k->utf, k->new);
			else if (*k->utf)
			{
				if (*k->utf >= 0 && *k->utf <= 127)
					first_octet(k, k->utf, 1);
				else if (*k->utf >= 128 && *k->utf <= 2047)
					second_octet(k, k->utf, k->new, 2);
				else if (*k->utf >= 2048 && *k->utf <= 65535)
					third_octet(k, k->utf, k->new, 3);
			}
			k->utf++;
		}
	}
	((k->dst == NULL) && (k->utf == NULL)) ? k->dst = ft_strdup("(null)") : 0;
	(k->utf != NULL && (*k->utf == 0) && !(k->dst)) ?
	k->dst = ft_strdup("\0") : 0;
	(k->width && (((k->w_n) > (int)(ft_strlen(k->dst))))) ?
	found_width(k, format, 0) : print_wany(k, format);
}

void	preco_for_bs(t_eb *k, int *utf, int new)
{
	if ((*utf >= 0 && *utf <= 127) && (k->p_n >= 1))
	{
		k->p_n -= 1;
		first_octet(k, utf, 1);
	}
	else if ((*utf >= 128 && *utf <= 2047) && (k->p_n >= 2))
	{
		k->p_n -= 2;
		second_octet(k, utf, new, 2);
	}
	else if ((*utf >= 2048 && *utf <= 65535) && (k->p_n >= 3))
	{
		k->p_n -= 3;
		third_octet(k, utf, new, 3);
	}
	else
		k->p_n = 0;
}

void	first_octet(t_eb *k, int *utf, size_t size)
{
	char	*tmp;
	char	*str;

	str = k->dst;
	tmp = ft_strnew(size);
	tmp[0] = (char)*utf;
	tmp[1] = '\0';
	k->dst = (k->dst == NULL) ? ft_strdup(tmp) : ft_strjoin(k->dst, tmp);
	ft_strdel(&tmp);
	ft_strdel(&str);
}

void	second_octet(t_eb *k, int *utf, int new, size_t size)
{
	char	*tmp;
	char	*str;

	str = k->dst;
	tmp = ft_strnew(size);
	new = *utf >> 6;
	new |= 192;
	tmp[0] = (char)new;
	new = *utf;
	new &= 63;
	new |= 128;
	tmp[1] = (char)new;
	tmp[2] = '\0';
	k->dst = (k->dst == NULL) ? ft_strdup(tmp) : ft_strjoin(k->dst, tmp);
	ft_strdel(&tmp);
	ft_strdel(&str);
}

void	third_octet(t_eb *k, int *utf, int new, size_t size)
{
	char *tmp;
	char *str;

	str = k->dst;
	tmp = ft_strnew(size);
	new = *utf >> 12;
	new |= 224;
	tmp[0] = (char)new;
	new = *utf >> 6;
	new &= 63;
	new |= 128;
	tmp[1] = (char)new;
	new = *utf;
	new &= 63;
	new |= 128;
	tmp[2] = (char)new;
	tmp[3] = '\0';
	k->dst = (k->dst == NULL) ? ft_strdup(tmp) : ft_strjoin(k->dst, tmp);
	ft_strdel(&tmp);
	ft_strdel(&str);
}
