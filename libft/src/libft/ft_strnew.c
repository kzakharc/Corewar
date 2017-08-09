/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 08:24:56 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/03 12:56:32 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	n;

	n = size;
	if (!(str = (char *)malloc((size + 1) * sizeof(*str))))
		return (NULL);
	while (size--)
		*str++ = '\0';
	*str = '\0';
	return (str - n);
}
