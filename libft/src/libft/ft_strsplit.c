/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:41:01 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/07 21:01:50 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char			**buf;
	unsigned int	i;
	size_t			k;
	size_t			t;

	i = 0;
	t = 0;
	if (s == NULL)
		return (NULL);
	if (!(buf = (char **)ft_memalloc(sizeof(char*) * (ft_cntwords(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if ((s[i] != c))
		{
			k = 0;
			while (s[i + k] != c && s[i + k])
				k++;
			if (!(buf[t++] = ft_strsub(s, i, k)))
				return (NULL);
			i += k - 1;
		}
		i++;
	}
	return (buf);
}
