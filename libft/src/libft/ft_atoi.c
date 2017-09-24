/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:08:57 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/03 12:54:49 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int	ft_isspace(int c)
{
	if ((c == '\t') || (c == '\n') || (c == '\v') || (c == '\f') || (c == '\r')\
		|| (c == ' '))
		return (1);
	return (0);
}

int		ft_atoi(const char *str)
{
	int b;
	int d;

	b = 0;
	while (ft_isspace(*str) == 1)
		str++;
	d = (*str == '-' ? -1 : 1);
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		b = b * 10 + (*str - '0');
		str++;
	}
	return (b * d);
}
