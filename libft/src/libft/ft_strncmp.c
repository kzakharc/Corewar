/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 19:09:08 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/06 12:57:39 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while ((*s1 == *s2) && (n > 1) && (*s1 && *s2))
	{
		s1++;
		s2++;
		n--;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}
