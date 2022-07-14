/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbraghis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/21 22:42:27 by dbraghis          #+#    #+#             */
/*   Updated: 2016/07/21 22:45:01 by dbraghis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

void	afisaref(int argc, char **argv)
{
	char	buf;
	int		fd;
	int		i;

	i = 1;
	while (i < argc)
	{
		fd = open(argv[i], O_RDONLY);
		if (fd >= 0)
		{
			while (read(fd, &buf, 1) != 0)
				write(1, &buf, 1);
		}
		else
		{
			ft_putstr("ft_cat: ");
			ft_putstr(argv[i]);
			ft_putstr(": No such file or directory\n");
		}
		close(fd);
		i++;
	}
}

void	afisare(void)
{
	char	buf;

	while (read(0, &buf, 1) != 0)
		write(1, &buf, 1);
}

int		main(int argc, char **argv)
{
	if (argc < 2 || argv[1][0] == '-')
		afisare();
	afisaref(argc, argv);
	return (0);
}
