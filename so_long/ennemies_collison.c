/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ennemies_collison.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:05:31 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/08 15:44:02 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_collision_ennemies(t_element *ennemy,
		t_element *element, t_gamestate *gamestate);

int	verify_ennemies_collision(t_element *ennemy,
		t_gamestate *gamestate);

int	verify_collision_ennemies(t_element *elt, t_gamestate *gamestate)
{
	if (elt->direction == -2)
		elt->coord.y -= elt->speed;
	if (elt->direction == -1)
		elt->coord.x += elt->speed;
	if (elt->direction == 2)
		elt->coord.y += elt->speed;
	if (elt->direction == 1)
		elt->coord.x -= elt->speed;
	return (verify_ennemies_collision(elt, gamestate));
}

static void	solid_collision_ennemies(t_element *ennemy, t_element *element)
{
	if (ennemy->direction == -1)
		ennemy->coord.x = element->coord.x - ennemy->size.width;
	if (ennemy->direction == 2)
		ennemy->coord.y = element->coord.y - ennemy->size.height;
	if (ennemy->direction == -2)
		ennemy->coord.y = element->coord.y + element->size.height;
	if (ennemy->direction == 1)
		ennemy->coord.x = element->coord.x + element->size.width;
}

static int	ennemies_collision(t_element *ennemy, t_element *element,
t_gamestate *gamestate)
{
	if (is_collision_ennemies(ennemy, element, gamestate))
	{
		if (element->type == '1')
		{
			solid_collision_ennemies(ennemy, element);
			return (1);
		}
	}
	return (0);
}

int	verify_ennemies_collision(t_element *ennemy,
t_gamestate *gamestate)
{
	t_list		*element;
	t_element	*elt;

	element = gamestate->elements;
	while (element)
	{
		elt = (t_element *)element->content;
		if (elt->visible)
		{
			if (ennemies_collision(ennemy, elt, gamestate))
				return (1);
		}
		element->content = (void *)elt;
		element = element->next;
	}
	return (0);
}

// static int	is_collision_ennemies_same_coord(t_element *ennemy,
// t_element *element, t_gamestate *gamestate)
// {
// 	if ((coord->x == element->coord.x
// 		&& coord->x + ennemy->size.width
// 		== element->coord.x + gamestate->unit_size))
// 	if ((coord->y + ennemy->size.width > element->coord.y
// 			&& coord->y + gamestate->unit_size
// 			< element->coord.y + gamestate->unit_size)
// 		|| (coord->y > element->coord.y
// 			&& coord->y < element->coord.y + gamestate->unit_size))
// 		return (1);
// 	if ((coord->x + ennemy->size.width > element->coord.x
// 		&& coord->x + ennemy->size.width
// 		< element->coord.x + gamestate->unit_size)
// 	|| (coord->x > element->coord.x && coord->x
// 		< element->coord.x + gamestate->unit_size))
// 	if ((coord->y == element->coord.y
// 			&& coord->y + ennemy->size.width
// 			== element->coord.y + gamestate->unit_size))
// 		return (1);
// 	return (0);
// }

int	is_collision_ennemies(t_element *ennemy,
t_element *element, t_gamestate *gamestate)
{
	int		unitwidth;
	int		unitheight;
	int		ennemy_size;
	t_coord	*coord;

	coord = &ennemy->coord;
	unitwidth = element->size.width;
	unitheight = element->size.height;
	ennemy_size = ennemy->size.width;
	if ((coord->x + ennemy_size > element->coord.x
			&& coord->x + ennemy_size < element->coord.x + unitwidth)
		|| (coord->x > element->coord.x
			&& coord->x < element->coord.x + unitwidth))
		if ((coord->y + ennemy_size > element->coord.y
				&& coord->y + ennemy_size < element->coord.y + unitheight)
			|| (coord->y > element->coord.y
				&& coord->y < element->coord.y + unitheight))
			return (1);
	return (0);
}
