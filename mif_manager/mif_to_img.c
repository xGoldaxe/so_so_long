/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mif_to_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:45:03 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/14 18:13:40 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mif_manager.h"

t_coord	swap_coord_dir(t_coord *coord, int size, int dir)
{
	t_coord	res;

	size--;
	if (dir == 2)
	{
		res.x = - (coord->x - size);
		res.y = - (coord->y - size);
	}
	else if (dir == -1)
	{
		res.x = - (coord->y - size);
		res.y = coord->x;
	}
	else if (dir == 1)
	{
		res.y = - (coord->x - size);
		res.x = coord->y;
	}
	else
		res = *coord;
	return (res);
}

void	print_pixel(t_elt_opt options, int unit, t_elt_opt ref_opt, t_mif *mif)
{
	unsigned int	color;

	color = mif->container[options.coord.y * mif->width + options.coord.x];
	options.coord = swap_coord_dir(&options.coord,
			ref_opt.size.width / unit, ref_opt.direction);
	options.coord.x = (options.coord.x * unit) + ref_opt.coord.x;
	options.coord.y = (options.coord.y * unit) + ref_opt.coord.y;
	if ((unsigned int)color >= 0xFF000000)
		put_square_from_bg(&options.img, &ref_opt.img, options);
	else
		put_square(options, unit, unit, color);
}

void	mif_to_img(t_mif *mif, t_data *img, t_data *ref, t_elt_opt ref_opt)
{
	t_elt_opt		options;
	int				unit;
	int				size;

	unit = ref_opt.size.width / mif->width;
	if (ref_opt.size.width % mif->width)
		unit++;
	size = ref_opt.size.width / unit;
	options.size.width = unit;
	options.size.height = unit;
	options.coord.y = 0;
	options.img = *img;
	ref_opt.img = *ref;
	while (options.coord.y < size)
	{
		options.coord.x = 0;
		while (options.coord.x < size)
		{
			(void)ref;
			print_pixel(options, unit, ref_opt, mif);
			options.coord.x++;
		}
		options.coord.y++;
	}
}
