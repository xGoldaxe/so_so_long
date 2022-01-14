/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:14:27 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/14 16:15:09 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_elt(t_element *elt, t_gamestate *gamestate,
t_data *dst, t_data *src)
{
	int			frame;
	t_elt_opt	ref_opt;

	elt->actual_frame += 1;
	if (elt->actual_frame >= elt->number_frames * elt->frame_speed)
		elt->actual_frame = 0;
	frame = elt->sprite;
	if (elt->actual_frame > 0)
		frame += elt->actual_frame / elt->frame_speed;
	ref_opt.direction = elt->direction;
	ref_opt.size.width = elt->size.width;
	ref_opt.coord = elt->coord;
	mif_to_img(&gamestate->mif[frame], dst, src, ref_opt);
}

void	place_elements(t_gamestate *gamestate)
{
	t_list		*element;
	t_element	elt;

	element = gamestate->elements;
	while (element)
	{
		elt = *(t_element *)element->content;
		if (elt.visible == 1)
		{
			if (elt.type == '1' || elt.type == 'C' || elt.type == 'E')
				put_elt(&elt, gamestate, &gamestate->blocks_layer,
					&gamestate->blocks_layer);
		}
		element = element->next;
	}
}
