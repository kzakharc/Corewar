/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:08:57 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/03 12:54:49 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int		ft_atoi(const char *str)
{
	int			i;
	int			sign;
	long int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == '\r' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
	|| str[i] == ' ' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res *= 10;
		res += (str[i] - '0');
		i++;
	}
	return (res * sign);
}
