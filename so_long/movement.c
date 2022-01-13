/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:22:43 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/12 15:24:31 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_velocity(int keycode, t_gamestate *gamestate)
{
	(void)keycode;
	if (gamestate->moving == 1 && gamestate->hero.speed
		< gamestate->game_speed * 1)
		gamestate->hero.speed += 1;
	else if (gamestate->moving == 0 && gamestate->hero.speed > 0)
		gamestate->hero.speed -= 1;
}

int	update_coord(int keycode, t_coord *player_coord, t_gamestate *gamestate)
{
	t_coord	new_coord;

	new_coord.x = player_coord->x;
	new_coord.y = player_coord->y;
	update_velocity(keycode, gamestate);
	if (keycode == 2)
		new_coord.x += gamestate->hero.speed / 1;
	if (keycode == 0)
		new_coord.x -= gamestate->hero.speed / 1;
	if (keycode == 1)
		new_coord.y += gamestate->hero.speed / 1;
	if (keycode == 13)
		new_coord.y -= gamestate->hero.speed / 1;
	verify_collision(&new_coord, gamestate);
	gamestate->score += gamestate->hero.speed / 1;
	player_coord->x = new_coord.x;
	player_coord->y = new_coord.y;
	return (1);
}
