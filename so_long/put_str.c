/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:02:06 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/15 15:05:29 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**load_letters(char *src, int nbr_char)
{
	int		i;
	int		y;
	int		fd;
	char	buff[1];
	char	**res;

	res = malloc(sizeof(char *) * (nbr_char + 1));
	fd = open(src, O_RDONLY);
	y = 0;
	while (y < nbr_char)
	{
		i = 0;
		res[y] = malloc(sizeof(char) * 111);
		if (!res[y])
			return (NULL);
		while (i < 111)
		{
			read(fd, buff, 1);
			res[y][i] = *buff;
			i++;
		}
		y++;
	}
	res[y] = NULL;
	return (res);
}

void	write_letter(t_elt_opt options, char *letter, int size)
{
	int	x;
	int	y;
	int	c_x;
	int	c_y;

	y = 0;
	c_x = options.coord.x;
	c_y = options.coord.y;
	while (y < 10)
	{
		x = 0;
		while (x < 10)
		{
			if (*letter == '*')
			{
				options.coord.x = c_x + x * size;
				options.coord.y = c_y + y * size;
				put_square(options, size, size, options.color);
			}
			letter++;
			x += 1;
		}
		letter++;
		y += 1;
	}
}

static int	get_vcode(char c)
{
	if (c == ' ')
		return (26);
	else if (c == ':')
		return (27);
	else if (ft_isdigit(c))
		return (28 - ('0' - c));
	else
		return (c - 'A');
}

char	**put_str(t_elt_opt options, char *content, int size)
{
	int			x;
	int			z;
	int			left;
	static char	**letters = NULL;

	if (!letters)
	{
		letters = load_letters("insane_fonts.txt", 38);
		if (!letters)
			return (NULL);
	}
	left = options.coord.x - ((10 * size) + (3 * size))
		* ft_strlen(content) / 2;
	options.coord.y -= (size * 10) / 2;
	z = 0;
	x = 0;
	while (content[z])
	{
		options.coord.x = left + x;
		write_letter(options, letters[get_vcode(content[z])], size);
		x += (10 * size) + (3 * size);
		z++;
	}
	return (letters);
}

void	clean_str(char **loaded)
{
	int	i;

	i = 0;
	while (loaded[i])
	{
		free(loaded[i]);
		++i;
	}
	free(loaded);
}
