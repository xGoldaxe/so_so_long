/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 20:29:26 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/14 16:07:53 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_gamestate *gamestate)
{
	gamestate->moving = 0;
	gamestate->elements = NULL;
	gamestate->nbr_c = 0;
	gamestate->collected_c = 0;
	gamestate->state = 0;
	gamestate->score = 0;
}

void	add_element(char c, t_coord coord, t_gamestate *gamestate)
{
	t_element	*element;

	if (c == '1' || c == 'E' || c == 'C' || c == 'H' || c == 'V')
	{
		element = find_create_element(c, coord, gamestate);
		if (!gamestate->elements)
			gamestate->elements = ft_lstnew(element);
		else
			ft_lstadd_front(&gamestate->elements, ft_lstnew(element));
	}
	if (c == 'P')
	{
		gamestate->hero.coord.x = gamestate->unit_size * coord.x
			+ ((gamestate->unit_size - gamestate->unit_size / 2) / 2);
		gamestate->hero.coord.y = gamestate->unit_size * coord.y
			+ ((gamestate->unit_size - gamestate->unit_size / 2) / 2);
	}
}

void	setup_unit_size(t_gamestate *gamestate)
{
	int	scale;
	int	actual_size;

	if (gamestate->map_size.width > gamestate->map_size.height)
		scale = gamestate->map_size.width;
	else
		scale = gamestate->map_size.height;
	gamestate->game_speed = HERO_SPEED / scale;
	gamestate->unit_size = 1020 / scale;
	actual_size = 1020;
	while ((gamestate->unit_size % 40
			|| (gamestate->unit_size < 40
				&& gamestate->unit_size % 20)) && gamestate->unit_size > 20)
	{
		--actual_size;
		gamestate->unit_size = actual_size / scale;
	}
}

static void	init_hero(t_gamestate *gamestate)
{
	gamestate->touch_press = -1;
	gamestate->hero.speed = 0;
	gamestate->hero.sprite = HERO_SPRITE;
	gamestate->hero.direction = -2;
	gamestate->hero.actual_frame = 0;
	gamestate->hero.number_frames = 2;
	gamestate->hero.frame_speed = 50;
	gamestate->hero.size.width = gamestate->unit_size / 2;
	gamestate->hero.size.height = gamestate->unit_size / 2;
}

t_list	*store_map(char	*file, t_gamestate *gamestate)
{
	int			fd;

	fd = open(file, O_RDONLY);
	read_map(fd, gamestate, 0);
	close(fd);
	setup_unit_size(gamestate);
	init_map(gamestate);
	init_hero(gamestate);
	fd = open(file, O_RDONLY);
	read_map(fd, gamestate, 1);
	close(fd);
	return (NULL);
}
