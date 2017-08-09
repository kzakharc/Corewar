/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 18:29:11 by vpoltave          #+#    #+#             */
/*   Updated: 2016/12/07 16:34:11 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *i;
	t_list *new;

	if (lst == NULL)
		return (NULL);
	new = f(lst);
	i = new;
	while (lst->next)
	{
		lst = lst->next;
		i->next = f(lst);
		i = i->next;
	}
	return (new);
}
