/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cntwords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 14:48:29 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/05 15:13:42 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_cntwords(char const *s, char c)
{
	size_t i;
	size_t n;

	i = 0;
	n = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		n++;
		while (s[i] == c && s[i])
			i++;
	}
	return (n);
}
