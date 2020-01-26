/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stherkil <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 17:35:25 by stherkil          #+#    #+#             */
/*   Updated: 2019/03/09 16:04:53 by stherkil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_exit(t_file **file)
{
	if ((*file)->rest)
		ft_memdel((void**)&(*file)->rest);
	if (*file)
		free(*file);
	return (-1);
}

static t_file	*findfd(const int fd, t_file **list)
{
	t_file *new;
	t_file *tmp;

	tmp = *list;
	while (tmp)
	{
		if (tmp->i == fd)
			return (tmp);
		tmp = tmp->next;
	}
	if (!(new = malloc(sizeof(t_file))))
		return (NULL);
	new->i = fd;
	new->len = 0;
	new->rest = NULL;
	new->next = *list;
	*list = new;
	return (new);
}

static int		ft_strappend(char **init, char *add)
{
	char *tmp;

	tmp = NULL;
	if (!*init || *init == NULL)
	{
		if (!(*init = ft_strdup(add)))
			return (0);
	}
	else
	{
		if (!(tmp = ft_strjoin(*init, add)))
			return (0);
		ft_memdel((void**)init);
		*init = tmp;
	}
	return (1);
}

static char		*update_nl(char **s, size_t *i)
{
	char	*tmp;
	char	*new;
	size_t	len;

	if (ft_strchr(*s, '\n'))
		len = ft_strchr(*s, '\n') - *s;
	else
		len = ft_strlen(*s);
	if (!(tmp = ft_strnew(len + 1)))
		return (NULL);
	tmp = ft_strncpy(tmp, *s, len);
	if ((*i = *i - len) <= 0)
		new = NULL;
	else
	{
		if (!(new = ft_strdup(*s + len + 1)))
		{
			free(tmp);
			return (NULL);
		}
	}
	ft_memdel((void**)s);
	*s = new;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	int				buf_size;
	char			buf[BUFF_SIZE + 1];
	static t_file	*fdlist = NULL;
	t_file			*fdcurr;

	if (line == NULL || fd < 0 || BUFF_SIZE < 1 || read(fd, buf, 0) < 0
			|| !(fdcurr = findfd(fd, &fdlist)))
		return (-1);
	while ((buf_size = read(fd, buf, BUFF_SIZE)))
	{
		fdcurr->len += buf_size;
		buf[buf_size] = '\0';
		if (!(ft_strappend(&(fdcurr->rest), buf)))
			return (ft_exit(&fdcurr));
		if (ft_strchr(buf, '\n'))
		{
			fdcurr->len--;
			break ;
		}
	}
	if ((!fdcurr->rest || *(fdcurr->rest) == '\0'))
		return (0);
	if (!(*line = update_nl(&fdcurr->rest, &fdcurr->len)))
		return (ft_exit(&fdcurr));
	return (1);
}
