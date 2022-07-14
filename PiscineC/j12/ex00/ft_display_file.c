/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 20:53:13 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/25 14:00:22 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	d_file(int fd)
{
	char	buf;

	while (read(fd, &buf, 1) != 0)
		write(1, &buf, 1);
}

int		main(int argc, char **argv)
{
	int		fd;

	fd = 0;
	if (argc != 2)
	{
		if (argc > 2)
			write(2, "Too many arguments.\n", 20);
		if (argc < 2)
			write(2, "File name missing.\n", 19);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	d_file(fd);
	close(fd);
	return (0);
}
