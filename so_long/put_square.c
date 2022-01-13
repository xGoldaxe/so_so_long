
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 00:01:38 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/08 14:29:37 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_square(t_elt_opt options, int width, int height, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			my_mlx_pixel_put(&options.img, options.coord.x + x,
				options.coord.y + y, color);
			x++;
		}
		y++;
	}
}

void	put_square_from_bg(t_data *img, t_data *bg, t_elt_opt options)
{
	int	x;
	int	y;

	y = 0;
	while (y < options.size.height)
	{
		x = 0;
		while (x < options.size.width)
		{
			my_mlx_pixel_put_from(img, bg, options.coord.x + x,
				options.coord.y + y);
			x++;
		}
		y++;
	}
}