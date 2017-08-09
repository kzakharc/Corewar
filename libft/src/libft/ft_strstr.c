/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 10:48:12 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/01 10:38:55 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	while (*big++ || ft_strlen(little) == 0)
		if (ft_strncmp((big - 1), little, ft_strlen((char *)little)) == 0)
			return ((char *)(big - 1));
	return (NULL);
}
