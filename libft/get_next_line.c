/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egoodale <eligoodale1@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:47:52 by egoodale          #+#    #+#             */
/*   Updated: 2018/03/14 14:22:05 by egoodale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl	*fetch_gnl(t_list **lst, int fd)
{
	t_gnl	gnl;
	t_list	*tmp;

	tmp = *lst;
	while (tmp)
	{
		if (((t_gnl *)(tmp->content))->fd == fd)
			return ((t_gnl *)(tmp->content));
		tmp = tmp->next;
	}
	gnl.fd = fd;
	gnl.new = NULL;
	gnl.final = NULL;
	gnl.tmp = NULL;
	gnl.src = NULL;
	ft_bzero(gnl.save, BUFF_SIZE);
	gnl.buf_s = BUFF_SIZE;
	tmp = ft_lstnew(&gnl, sizeof(t_gnl));
	ft_lstadd(lst, tmp);
	return ((t_gnl *)(tmp->content));
}

static int		build_line(t_gnl *gnl)
{
	if ((gnl->new = ft_strchr(gnl->str, '\n')))
		ft_strcpy(gnl->save, gnl->new + 1);
	else
		gnl->new = ft_strchr(gnl->str, '\0');
	gnl->src = ft_strndup(gnl->str, gnl->new - gnl->str);
	if (gnl->final && *gnl->final)
		gnl->tmp = ft_strdup(gnl->final);
	else
		gnl->tmp = ft_strnew(0);
	ft_strdel(&gnl->final);
	gnl->final = ft_strjoin(gnl->tmp, gnl->src);
	ft_strdel(&gnl->tmp);
	ft_strdel(&gnl->src);
	if (*gnl->new != '\n')
	{
		ft_bzero(gnl->str, BUFF_SIZE + 1);
		if ((gnl->buf_s = read(gnl->fd, gnl->str, BUFF_SIZE)) < 0)
			return (-1);
	}
	else
		gnl->buf_s = 0;
	return (1);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*lst;
	t_gnl			*gnl;

	if (fd < 0 || !line)
		return (-1);
	gnl = fetch_gnl(&lst, fd);
	ft_bzero(gnl->str, BUFF_SIZE + 1);
	gnl->buf_s = BUFF_SIZE;
	if (gnl->save[0])
		ft_strcpy(gnl->str, gnl->save);
	else if ((gnl->buf_s = read(fd, gnl->str, BUFF_SIZE)) < 0)
		return (-1);
	ft_bzero(gnl->save, BUFF_SIZE);
	gnl->final = 0;
	*line = 0;
	while (gnl->buf_s > 0)
		if (build_line(gnl) == -1)
		{
			ft_strdel(&gnl->final);
			return (-1);
		}
	if (gnl->final)
		*line = ft_strdup(gnl->final);
	ft_strdel(&gnl->final);
	return (*line ? 1 : 0);
}
