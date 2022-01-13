/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 15:39:40 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/09 19:14:06 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x > GAME_WIDTH || y > GAME_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	my_mlx_pixel_put_from(t_data *data, t_data *from_data, int x, int y)
{
	char			*dst;
	unsigned int	from;
	int				offset;

	if (x > GAME_WIDTH || y > GAME_HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	offset = (y * from_data->line_length + x * (from_data->bits_per_pixel / 8));
	from = *(unsigned int *)(from_data->addr + offset);
	*(unsigned int *)dst = from;
}
