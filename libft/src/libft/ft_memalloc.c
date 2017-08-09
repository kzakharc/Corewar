/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:33:11 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/03 13:06:14 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	unsigned char	*tmp;
	size_t			n;

	n = size;
	tmp = (void *)malloc(size * sizeof(tmp));
	if (tmp == NULL)
		return (NULL);
	while (size-- != 0)
		*tmp++ = 0;
	return (tmp - n);
}
