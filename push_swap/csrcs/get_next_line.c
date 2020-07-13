/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/23 17:42:28 by dbraghis          #+#    #+#             */
/*   Updated: 2016/12/23 18:02:28 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <unistd.h>
#include <fcntl.h>

t_gnl		*create_t(char *buff, int fd)
{
	t_gnl *ptr;

	ptr = (t_gnl *)malloc(sizeof(t_gnl));
	if (!ptr)
		return (NULL);
	if (!buff)
	{
		ptr->buff = NULL;
		fd = 0;
	}
	else
	{
		ptr->buff = buff;
		ptr->fd = fd;
		ptr->next = NULL;
	}
	return (ptr);
}

void		read_in_buffer(const int fd, char **buffer, int *read_return)
{
	char	tmp[BUFF_SIZE + 1];
	char	*p;

	ft_bzero(tmp, BUFF_SIZE + 1);
	*read_return = read(fd, tmp, BUFF_SIZE);
	if (*read_return == 0)
		return ;
	tmp[*read_return] = '\0';
	p = ft_strjoin(*buffer, tmp);
	ft_strdel(buffer);
	*buffer = p;
}

void		chek_and_add_node(t_gnl **begin, t_gnl **p, t_gnl **p1, int fd)
{
	int		flag;

	flag = 0;
	if (*begin == NULL)
	{
		*begin = create_t(ft_strnew(0), fd);
		*p = *begin;
	}
	else
	{
		while (*p)
		{
			if ((*p1 = *p) && (*p)->fd == fd)
			{
				flag = 1;
				break ;
			}
			*p = (*p1)->next;
		}
		if (flag == 0)
		{
			(*p1)->next = create_t(ft_strnew(0), fd);
			*p = (*p1)->next;
		}
	}
}

int			end(int *read_return, char **buff, char **line)
{
	if (*read_return == 0 && *buff && **buff != '\0')
	{
		*line = ft_strdup(*buff);
		ft_strdel(&(*buff));
		return (1);
	}
	else if (*line)
		*line = ft_strnew(0);
	return (*read_return);
}

int			get_next_line(const int fd, char **line)
{
	static		t_gnl	*begin;
	t_gnl				*p;
	t_gnl				*p1;
	char				*ptr;
	int					read_return;

	if (fd < 0 || BUFF_SIZE > 65534 || !line)
		return (-1);
	p = begin;
	chek_and_add_node(&begin, &p, &p1, fd);
	read_return = 1;
	while (read_return > 0)
	{
		read_in_buffer(fd, &(p->buff), &read_return);
		if (p->buff && ((ptr = ft_strchr(p->buff, '\n')) != NULL))
		{
			*ptr = '\0';
			*line = ft_strdup(p->buff);
			ft_memmove(p->buff, ptr + 1, ft_strlen(ptr + 1) + 1);
			if (ft_strlen(*line) > 0 || **line == '\0')
				return (1);
		}
	}
	return (end(&read_return, &(p->buff), &(*line)));
}
// static t_list	*create_node(int fd)
// {
// 	t_list	*ret;
// 	t_fd	*fd_node;

// 	fd_node = (t_fd *)malloc(sizeof(t_fd));
// 	fd_node->fd = fd;
// 	fd_node->str = ft_strnew(BUFF_SIZE);
// 	fd_node->start = fd_node->str;
// 	ret = ft_lstnew(fd_node, sizeof(t_fd));
// 	return (ret);
// }

// static t_fd		*get_node(int fd, t_list **fd_list)
// {
// 	t_list	*tmp;
// 	t_fd	*fd_node;

// 	if (!fd_list || !*fd_list)
// 		*fd_list = create_node(fd);
// 	tmp = *fd_list;
// 	while (tmp)
// 	{
// 		fd_node = (t_fd *)tmp->content;
// 		if (fd_node->fd == fd)
// 			return (fd_node);
// 		tmp = tmp->next;
// 	}
// 	ft_lstadd(fd_list, create_node(fd));
// 	return ((t_fd*)(*fd_list)->content);
// }

// static void		handle_node(t_fd *fd_node, char **ret, char **end)
// {
// 	long	n_nl;
// 	char	*nl;

// 	nl = ft_strchr(fd_node->str, '\n');
// 	if (nl)
// 	{
// 		n_nl = (long)(nl - fd_node->str);
// 		*end = (char *)1;
// 		fd_node->str[n_nl] = 0;
// 		*ret = ft_strdup(fd_node->str);
// 		fd_node->str += n_nl + 1;
// 	}
// 	else
// 	{
// 		*ret = ft_strdup(fd_node->str);
// 		ft_strclr(fd_node->start);
// 		fd_node->str = fd_node->start;
// 	}
// }

// static char		*handle_data(int count, char **ret,
// 					char *buff, t_fd *fd_node)
// {
// 	long	n_nl;
// 	char	*nl;
// 	int		len;

// 	len = ft_strlen(*ret);
// 	nl = ft_strchr(buff, '\n');
// 	if (!nl)
// 	{
// 		*ret = ft_realloc((void *)*ret, len, len + count + 1);
// 		ft_strncat(*ret, buff, count);
// 		ft_strclr(buff);
// 	}
// 	else
// 	{
// 		n_nl = (long)(nl - buff);
// 		*ret = (char *)ft_realloc((void *)*ret, len, len + n_nl + 1);
// 		ft_strncat(*ret, buff, n_nl);
// 		ft_strncpy(fd_node->start, buff + n_nl + 1, BUFF_SIZE - n_nl - 1);
// 	}
// 	return (ft_strchr(buff, '\n'));
// }

// int				get_next_line(const int fd, char **line)
// {
// 	static t_list	*fd_lsit;
// 	t_fd			*fd_node;
// 	char			*ret;
// 	char			*tmp[2];
// 	int				count;

// 	if (!line)
// 		return (-1);
// 	fd_node = get_node(fd, &fd_lsit);
// 	tmp[1] = 0;
// 	handle_node(fd_node, &ret, &tmp[1]);
// 	if (!tmp[1])
// 		tmp[0] = ft_strnew(BUFF_SIZE);
// 	else
// 		return ((*line = ret) ? 1 : 0);
// 	while (!tmp[1] && (count = read(fd, tmp[0], BUFF_SIZE)) > 0)
// 		tmp[1] = handle_data(count, &ret, tmp[0], fd_node);
// 	if (tmp[1] > tmp[0])
// 		ft_strcpy(fd_node->start, tmp[1] + 1);
// 	*line = ret;
// 	ft_strdel(&tmp[0]);
// 	if (tmp[1] || ret[0] || count)
// 		return ((count >= 0 ? 1 : -1));
// 	return (0);
// }
