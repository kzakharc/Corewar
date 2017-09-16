/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intmalloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 11:25:15 by yzakharc          #+#    #+#             */
/*   Updated: 2017/09/16 11:25:16 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	*ft_intmalloc(size_t size)
{
	int n;
	int *tmp;

	n = -1;
	if (!(tmp = malloc(size * sizeof(tmp))))
		return (NULL);
	while (++n < (int)size)
		tmp[n] = 0;
	return (tmp);
}