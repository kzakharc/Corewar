/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 22:18:34 by vpoltave          #+#    #+#             */
/*   Updated: 2017/07/23 20:37:39 by vpoltave         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		where_is_smth(int fd, char **line, char **s, char *buff)
{
	ssize_t	i;
	char	*tmp;

	while ((i = read(fd, buff, BUFF_SIZE)) > 0 || **s)
	{
		tmp = *s;
		*s = (*s != NULL) ? ft_strjoin(*s, buff) : ft_strdup(buff);
		free(tmp);
		ft_strclr(buff);
		if (ft_strchr(*s, '\n'))
		{
			where_is_n(&(*s), line);
			ft_strdel(&buff);
			return (1);
		}
		else if (!i && **s)
		{
			*line = ft_strsub(*s, 0, ft_strlen(*s));
			*s = ft_strnew(0);
			return (1);
		}
	}
	return ((i == 0) && (ft_strlen(*s) == 0)) ? 0 : 1;
}

char	**where_is_bacon(const int fd, t_bacon **bacon)
{
	t_bacon *tmp;

	tmp = *bacon;
	while (tmp != NULL)
	{
		if ((tmp->fd) == fd)
			return (&(tmp->s));
		tmp = tmp->next;
	}
	tmp = (t_bacon *)malloc(sizeof(t_bacon));
	tmp->s = ft_strnew(0);
	tmp->fd = fd;
	tmp->next = (*bacon);
	(*bacon) = tmp;
	return (&(tmp->s));
}

void	where_is_n(char **s, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *s;
	while (**s != '\n')
	{
		(*s)++;
		i++;
	}
	*s -= i;
	*line = ft_strsub(*s, 0, (size_t)i);
	*s += i + 1;
	*s = ft_strsub(*s, 0, ft_strlen(*s));
	ft_strdel(&tmp);
}

int		get_next_line(const int fd, char **line)
{
	char			*buff;
	static t_bacon	*bacon;
	char			**s;
	int				i;

	buff = ft_strnew(BUFF_SIZE);
	if ((fd < 0) || ((read(fd, buff, 0)) < 0) || (BUFF_SIZE <= 0))
		return (-1);
	s = where_is_bacon(fd, &bacon);
	i = where_is_smth(fd, line, s, buff);
	return (i);
}
