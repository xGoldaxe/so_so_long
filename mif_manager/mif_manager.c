/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mif_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:06:58 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/14 15:44:39 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mif_manager.h"

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;
// 	t_mif	mif;
// 	t_coord	coord;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 400, 400, "Hello world!");
// 	img.img = mlx_new_image(mlx, 1000, 1000);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	mif_read("./files/test3.mif", &mif);
// 	coord.x = 11;
// 	coord.y = 11;
// 	t_elt_opt test;
// 	test.coord = coord;
// 	test.img = img;
// 	put_square(test, 300, 300, 0x00FFFFFF);
// 	mif_to_img(&mif, &img, &img, 300, coord, -1);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// 	//afficher le container comme une image via minilibx
// }

static void	store_colors(t_list **colors, int fd)
{
	t_color	*color;
	char	*line;
	t_list	*new;

	while (1)
	{
		color = malloc(sizeof(t_color));
		line = get_next_line(fd);
		if (strncmp(line, "@@@", 3) == 0)
		{
			free(line);
			return ;
		}
		color->c = *line;
		free(line);
		line = get_next_line(fd);
		color->value = atoi(line);
		free(line);
		new = ft_lstnew(color);
		if (colors)
			ft_lstadd_front(colors, new);
		else
			colors = &new;
	}
}

unsigned int	find_color(t_list *colors, char c)
{
	t_color	*color;

	while (colors)
	{
		color = (t_color *)colors->content;
		if (color->c == c)
			return (color->value);
		colors = colors->next;
	}
	return (0);
}

void	mif_read(char *file, t_mif *options)
{
	int		fd;
	char	*line;
	int		index;
	int		x;

	fd = open(file, O_RDONLY);
	options->width = atoi(get_next_line(fd));
	line = get_next_line(fd);
	options->height = atoi(line);
	free(line);
	options->container = malloc(sizeof(int) * options->width * options->height);
	options->colors = NULL;
	store_colors(&options->colors, fd);
	index = 0;
	while (line)
	{
		line = get_next_line(fd);
		x = 0;
		while (line && line[x] && line[x] != '\n')
		{
			options->container[index] = find_color(options->colors, line[x]);
			x++;
			index++;
		}
	}
}
