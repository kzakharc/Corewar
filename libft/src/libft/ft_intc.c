/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzakharc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/16 13:38:25 by yzakharc          #+#    #+#             */
/*   Updated: 2017/09/16 13:38:26 by yzakharc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int 	ft_intc(int *mass, int c, int length)
{
	int	tmp;
	int	cnt;

	tmp = -1;
	cnt = 0;
	while (++tmp < length)
		if (mass[tmp] == c)
			cnt++;
	return (cnt);
}