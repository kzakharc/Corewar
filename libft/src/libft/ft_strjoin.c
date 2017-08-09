/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 20:27:54 by vpoltave          #+#    #+#             */
/*   Updated: 2017/06/21 19:17:21 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *tmp;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(tmp, s1);
	ft_strcat(tmp, s2);
	return (tmp);
}
