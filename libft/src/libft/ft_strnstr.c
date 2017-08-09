/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:58:26 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/03 12:56:14 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	len++;
	while ((*big++ && len--) && ((ft_strlen(little) == 0
						|| ft_strlen(little) <= len)))
		if (((ft_strncmp((big - 1), little, ft_strlen((char *)little)) == 0)))
			return ((char *)(big - 1));
	return (NULL);
}
