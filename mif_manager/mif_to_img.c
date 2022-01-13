/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mif_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:45:03 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/12 12:44:12 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mif_manager.h"

void swap_coord_dir(t_coord *coord, int size, int dir)
{
	int	tmp;

	size--;
	if (dir == 2)
	{
		coord->x = - (coord->x - size);
		coord->y = - (coord->y - size);
	}
	else if (dir == -1)
	{
		tmp = coord->x;
		coord->x = - (coord->y - size);
		coord->y = tmp;
	}
	else if (dir == 1)
	{
		tmp = coord->y;
		coord->y = - (coord->x - size);
		coord->x = tmp;
	}
}

void	mif_to_img(t_mif *mif, t_data *img, t_data *ref, int size, t_coord coord, int direction)
{
	int				x;
	int				y;
	unsigned int	color;
	t_elt_opt		options;
	int				unit;
	t_coord			tmp;

	unit = size / mif->width;
	if (size % mif->width)
		unit++;
	y = 0;
	options.coord.y = coord.y;
	options.img = *img;
	while (options.coord.y - coord.y  < size)
	{
		x = 0;
		options.coord.x = coord.x;
		while (options.coord.x - coord.x < size)
		{
			options.size.width = unit;
			options.size.height = unit;
			color = mif->container[(y * mif->width )+ x];
			tmp.x = options.coord.x;
			tmp.y = options.coord.y;
			///***********
			options.coord.x = (options.coord.x - coord.x) / unit ;
			options.coord.y = (options.coord.y - coord.y) / unit ;
			swap_coord_dir(&options.coord, size / unit, direction);
			options.coord.x = options.coord.x * unit + coord.x;
			options.coord.y = options.coord.y * unit + coord.y;
			if (color >= 0xFF000000)
				put_square_from_bg(img, ref, options);
			else
				put_square(options, options.size.width, options.size.height, color);
			options.coord.y = tmp.y;
			options.coord.x = tmp.x + unit;
			++x;
		}
		++y;
		options.coord.y += unit;
	}
}
