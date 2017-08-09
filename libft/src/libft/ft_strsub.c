/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:26:16 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/07 16:34:41 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!(tmp = ft_strnew(len)))
		return (NULL);
	if (s == NULL)
		return (NULL);
	ft_memcpy(tmp, s + start, len);
	return (tmp);
}
