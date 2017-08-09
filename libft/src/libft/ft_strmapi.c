/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 12:59:17 by vpoltave          #+#    #+#             */
/*   Updated: 2016/11/30 18:37:19 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*dst;

	i = 0;
	if (s)
	{
		dst = ft_strnew(ft_strlen(s));
		if (dst == 0)
			return (NULL);
		while (s[i])
		{
			dst[i] = f(i, s[i]);
			i++;
		}
		return (dst);
	}
	return (NULL);
}
