/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:07:42 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/14 18:04:15 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	create_other_elements(t_element *res, char c,
t_coord coord, t_gamestate *gamestate)
{
	res->size.width = gamestate->unit_size / 2;
	res->size.height = gamestate->unit_size / 2;
	res->coord.x = gamestate->unit_size * coord.x
		+ ((gamestate->unit_size - gamestate->unit_size / 2) / 2);
	res->coord.y = gamestate->unit_size * coord.y
		+ ((gamestate->unit_size - gamestate->unit_size / 2) / 2);
	res->speed = gamestate->game_speed / 2;
	res->direction = 2;
	res->actual_frame = 0;
	res->number_frames = 2;
	res->frame_speed = 20;
	res->sprite = ENNEMIES_SPRITE;
	if (c == 'H')
		res->direction = 1;
	if (c == 'C')
	{
		res->sprite = C_SPRITE;
		res->number_frames = 1;
		res->direction = 0;
		gamestate->nbr_c += 1;
	}
}

t_element	*find_create_element(char c, t_coord coord,
t_gamestate *gamestate)
{
	t_element	*res;

	res = malloc(sizeof(t_element));
	res->type = c;
	res->coord.x = gamestate->unit_size * coord.x;
	res->coord.y = gamestate->unit_size * coord.y;
	res->visible = 1;
	res->size.width = gamestate->unit_size;
	res->size.height = gamestate->unit_size;
	res->direction = 0;
	res->speed = 0;
	res->sprite = WALL_SPRITE;
	if (c == 'E')
		res->sprite = EXIT_SPRITE;
	if (c == 'V' || c == 'H' || c == 'C')
		create_other_elements(res, c, coord, gamestate);
	return (res);
}
