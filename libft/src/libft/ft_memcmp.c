/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:39:19 by vpoltave          #+#    #+#             */
/*   Updated: 2016/11/28 17:52:52 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n-- != 0)
		if (*(unsigned char *)s1++ != *(unsigned char *)s2++)
			return (*(unsigned char *)(s1 - 1) - *(unsigned char *)(s2 - 1));
	return (0);
}
