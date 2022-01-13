/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:05:31 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/13 14:29:01 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_ennemies(t_gamestate *gamestate)
{
	t_list		*element;
	t_element	*elt;
	t_elt_opt	bg_options;

	element = gamestate->elements;
	while (element)
	{
		elt = (t_element *)element->content;
		if (elt->speed)
		{
			bg_options.coord = elt->coord;
			bg_options.size = elt->size;
			put_square_from_bg(&(gamestate->vars).img,
				&gamestate->blocks_layer, bg_options);
		}
		element = element->next;
	}
}

void	move_ennemies(t_gamestate *gamestate)
{
	t_list		*element;
	t_element	*elt;
	int			is_collision;

	element = gamestate->elements;
	clear_ennemies(gamestate);
	while (element)
	{
		elt = (t_element *)element->content;
		if (elt->speed && (elt->type == 'H' || elt->type == 'V'))
		{

			is_collision = verify_collision_ennemies(elt, gamestate);
			if (is_collision)
				elt->direction = -elt->direction;
			elt = (t_element *)element->content;
			put_elt(elt, gamestate, &(gamestate->vars).img, &(gamestate->vars).img);
		}
		element->content = (void *)elt;
		element = element->next;
	}
}
