/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 07:47:29 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/03 13:11:30 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*dst;
	int		i;

	i = 0;
	if (s)
	{
		dst = ft_strnew(ft_strlen(s));
		if (dst == 0)
			return (NULL);
		while (s[i])
		{
			dst[i] = f(s[i]);
			i++;
		}
		return (dst);
	}
	return (NULL);
}
