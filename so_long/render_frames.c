/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_frames.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:22:11 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/13 14:28:19 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_score(t_gamestate *gamestate)
{
	t_elt_opt	str_options;
	t_elt_opt	bg_options;
	t_vars		*vars;
	char		*content;

	vars = &(gamestate->vars);
	content = ft_realloc_cat(ft_itoa(gamestate->score), "SCORE: ");
	str_options.img = vars->img;
	str_options.color = 0x00ffffff;
	str_options.coord.y = gamestate->unit_size * 0.5;
	str_options.coord.x = gamestate->unit_size
		* (gamestate->map_size.width / 2);
	if (gamestate->map_size.width % 2)
		str_options.coord.x += gamestate->unit_size / 2;
	bg_options.coord.x = 0;
	bg_options.coord.y = 0;
	bg_options.size.width = gamestate->unit_size * gamestate->map_size.width;
	bg_options.size.height = gamestate->unit_size;
	put_square_from_bg(&vars->img, &gamestate->blocks_layer, bg_options);
	put_str(str_options, content, 2);
	free(content);
}

int	render_next_frame(t_gamestate *gamestate)
{
	t_vars		*vars;
	t_elt_opt	bg_options;

	vars = &(gamestate->vars);
	if (gamestate->state == 0)
	{
		bg_options.img = vars->img;
		bg_options.size.width = gamestate->unit_size / 2;
		bg_options.size.height = gamestate->unit_size / 2;
		bg_options.coord = gamestate->hero.coord;
		put_square_from_bg(&vars->img, &gamestate->blocks_layer, bg_options);
		move_ennemies(gamestate);
		update_coord(gamestate->touch_press,
			&gamestate->hero.coord, gamestate);
		// bg_options.coord = gamestate->hero.coord;
		put_elt(&gamestate->hero, gamestate, &vars->img, &gamestate->blocks_layer);
		// mif_to_img(&gamestate->mif[HERO_SPRITE], &vars->img, &gamestate->blocks_layer, bg_options.size.height, bg_options.coord, gamestate->hero.direction);
		print_score(gamestate);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img,
		(GAME_WIDTH - gamestate->map_size.width * gamestate->unit_size) / 2,
		(GAME_HEIGHT - gamestate->map_size.height * gamestate->unit_size) / 2);
	if (gamestate->state == 1)
		game_over(gamestate);
	return (0);
}
