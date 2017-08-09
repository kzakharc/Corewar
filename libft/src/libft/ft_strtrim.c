/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 12:20:50 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/05 14:07:02 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	n;
	size_t	l;
	char	*tmp;

	i = 0;
	l = 0;
	if (s == NULL)
		return (NULL);
	n = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if ((i - 1) == n)
	{
		if (!(tmp = ft_strnew(0)))
			return (NULL);
		return (tmp);
	}
	while (s[n] == ' ' || s[n] == '\n' || s[n] == '\t')
		n--;
	l = n - i + 1;
	if (!(tmp = ft_strnew(l)))
		return (NULL);
	ft_strncpy(tmp, &s[i], l);
	return (tmp);
}
