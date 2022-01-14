/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_collision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 19:54:55 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/14 16:59:56 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_collision(t_coord *coord, t_element *element, t_gamestate *gamestate)
{
	int	player_size;

	player_size = gamestate->unit_size / 2;
	if ((coord->x + player_size > element->coord.x
			&& coord->x + player_size < element->coord.x + element->size.width)
		|| (coord->x > element->coord.x
			&& coord->x < element->coord.x + element->size.width))
		if ((coord->y + player_size > element->coord.y && coord->y + player_size
				< element->coord.y + element->size.height)
			|| (coord->y > element->coord.y
				&& coord->y < element->coord.y + element->size.height))
			return (1);
	if (coord->x == element->coord.x)
		if ((coord->y + player_size > element->coord.y && coord->y + player_size
				< element->coord.y + element->size.height)
			|| (coord->y > element->coord.y
				&& coord->y < element->coord.y + element->size.height))
			return (1);
	if (coord->y == element->coord.y)
		if ((coord->x + player_size > element->coord.x && coord->x + player_size
				< element->coord.x + element->size.width)
			|| (coord->x > element->coord.x
				&& coord->x < element->coord.x + element->size.width))
			return (1);
	return (0);
}

void	solid_collision(t_coord *coord,
t_element *element, t_gamestate *gamestate)
{
	if (gamestate->touch_press == TOUCH_RIGHT)
		coord->x = element->coord.x - gamestate->unit_size / 2;
	if (gamestate->touch_press == TOUCH_DOWN)
		coord->y = element->coord.y - gamestate->unit_size / 2;
	if (gamestate->touch_press == TOUCH_UP)
		coord->y = element->coord.y + gamestate->unit_size;
	if (gamestate->touch_press == TOUCH_LEFT)
		coord->x = element->coord.x + gamestate->unit_size;
}

t_element	*element_collision(t_coord *coord,
t_element *element, t_gamestate *gamestate)
{
	t_elt_opt	options;

	if (is_collision(coord, element, gamestate))
	{
		if (element->type == '1')
			solid_collision(coord, element, gamestate);
		else if (element->type == 'E')
		{
			if (gamestate->collected_c >= gamestate->nbr_c)
				gamestate->state = 1;
		}
		else if (element->type == 'V' || element->type == 'H')
			clean_exit(gamestate);
		else if (element->type == 'C' && element->visible)
		{
			element->visible = 0;
			options.coord = element->coord;
			options.size = element->size;
			put_square_from_bg(&gamestate->blocks_layer,
				&gamestate->background, options);
			gamestate->collected_c++;
		}
	}
	return (element);
}

void	elements_collision(t_coord *coord, t_gamestate *gamestate)
{
	t_list		*element;
	t_element	*elt;

	element = gamestate->elements;
	while (element)
	{
		elt = (t_element *)element->content;
		if (elt->visible)
			element_collision(coord, elt, gamestate);
		element->content = (void *)elt;
		element = element->next;
	}
}

int	verify_collision(t_coord *coord, t_gamestate *gamestate)
{
	elements_collision(coord, gamestate);
	return (1);
}
