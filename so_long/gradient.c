/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:33:41 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/08 14:19:31 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_prop(int start, int end, int size, int progression)
{
	if (start > end)
		return (start - (progression * end / size));
	return (start + (progression * end / size));
}

void	ft_put_gradient(t_size size, int a,
int b, t_data img)
{
	int		y;
	int		x;

	y = 0;
	while (y < size.height)
	{
		x = 0;
		while (x < size.width)
		{
			my_mlx_pixel_put(&img, x, y, create_trgb(0,
					get_prop(get_r(a), get_r(b), size.width, x),
					get_prop(get_g(a), get_g(b), size.width, x),
					get_prop(get_b(a), get_b(b), size.width, x)));
			x++;
		}
		y++;
	}
}
