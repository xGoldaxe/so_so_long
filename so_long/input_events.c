/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:23:15 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/13 12:48:57 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_press(int keycode, t_gamestate *gamestate)
{
	if ((keycode == TOUCH_UP
			|| keycode == TOUCH_DOWN
			|| keycode == TOUCH_LEFT
			|| keycode == TOUCH_RIGHT))
	{
		gamestate->moving = 1;
		if (gamestate->hero.sprite != HERO_WALK_SPRITE)
			gamestate->hero.actual_frame = 0;
		gamestate->hero.sprite = HERO_WALK_SPRITE;
		gamestate->hero.number_frames = 4;
		gamestate->hero.frame_speed = 10;
	}
	if (keycode == TOUCH_UP)
	{
		gamestate->touch_press = TOUCH_UP;
		gamestate->hero.direction = -2;
	}
	if (keycode == TOUCH_RIGHT)
	{
		gamestate->touch_press = TOUCH_RIGHT;
		gamestate->hero.direction = -1;
	}
	if (keycode == TOUCH_LEFT)
	{
		gamestate->touch_press = TOUCH_LEFT;
		gamestate->hero.direction = 1;
	}
	if (keycode == TOUCH_DOWN)
	{
		gamestate->touch_press = TOUCH_DOWN;
		gamestate->hero.direction = 2;
	}
	if (keycode == ESCAPE)
		clean_exit();
	return (1);
}

int	on_release(int keycode, t_gamestate *gamestate)
{
	if ((keycode == 13
			|| keycode == 2
			|| keycode == 0
			|| keycode == 1)
		&& keycode == gamestate->touch_press)
	{
		gamestate->moving = 0;
		gamestate->hero.sprite = HERO_SPRITE;
		gamestate->hero.number_frames = 2;
		gamestate->hero.actual_frame = 0;
		gamestate->hero.frame_speed = 50;
	}
	return (1);
}
