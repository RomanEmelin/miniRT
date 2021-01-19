/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_maker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwinter <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/02 15:10:47 by mwinter           #+#    #+#             */
/*   Updated: 2021/01/05 20:51:52 by mwinter          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

int			make_file(char *filename, t_all *all)
{
	int fd;

	if ((fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0655)) <= 0)
		handle_error("fail to create file.", all);
	free(filename);
	return (fd);
}

char		*create_file(t_all *all, char *file)
{
	char	*filename;
	int		i;

	i = 0;
	while (file[i] != '.')
		i++;
	if (!(filename = (char *)malloc(sizeof(char) * (i + 3))))
		handle_error("fail malloc in createfile.", all);
	i = 0;
	while (file[i] != '.')
	{
		filename[i] = file[i];
		i++;
	}
	filename[i] = '.';
	filename[i + 1] = 'b';
	filename[i + 2] = 'm';
	filename[i + 3] = 'p';
	filename[i + 4] = '\0';
	return (filename);
}

static void	b_offset(unsigned char header[4], unsigned int i)
{
	header[0] = i % 256;
	header[1] = i / 256 % 256;
	header[2] = i / 256 / 256 % 256;
	header[3] = i / 256 / 256 / 256;
}

static void	make_header(t_all *all)
{
	unsigned char	header[54];
	int				size;

	size = all->res.crd.x * all->res.crd.y * 4 + 54;
	ft_bzero(header, 54);
	header[0] = (unsigned char)'B';
	header[1] = (unsigned char)'M';
	b_offset(&header[2], size);
	header[10] = (unsigned int)54;
	header[14] = (unsigned int)40;
	b_offset(&header[18], all->res.crd.x);
	b_offset(&header[22], all->res.crd.y);
	header[26] = (unsigned int)1;
	header[28] = (unsigned int)32;
	if (!(write(all->fd, header, 54)))
		handle_error("fail to write file.", all);
}

void		make_bmp(char *filename, t_all *all)
{
	int	y;
	int	line_length;

	all->fd = make_file(filename, all);
	make_header(all);
	y = all->res.crd.y;
	line_length = all->res.crd.x * all->img.bits_per_pixel / 8;
	while (0 <= y)
	{
		write(all->fd, (unsigned char *)(all->img.addr +
			y * all->img.line_length), line_length);
		y--;
	}
	close(all->fd);
	mlx_destroy_window(all->mlx, all->mlx_win);
}
