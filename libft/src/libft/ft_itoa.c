/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 12:23:13 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/07 16:30:30 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*dst;
	int		i;
	size_t	j;

	j = ft_cntdigits(n);
	if (!(dst = ft_strnew(j)))
		return (NULL);
	if (n == 0)
	{
		dst[0] = 48;
		return (dst);
	}
	if (n < 0)
		dst[0] = '-';
	while (j - 1 > 0)
	{
		i = n % 10;
		if (i < 0)
			i = -i;
		dst[j-- - 1] = i + 48;
		n /= 10;
	}
	if (n > 0)
		dst[0] = n + 48;
	return (dst);
}
