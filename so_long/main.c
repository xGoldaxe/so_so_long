/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:35:01 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/14 16:59:21 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int		clean_exit_event(void *unused);

static void	load_screens(t_gamestate *gamestate)
{
	gamestate->vars.img.img = mlx_new_image(gamestate->vars.mlx,
			gamestate->map_size.width * gamestate->unit_size,
			gamestate->map_size.height * gamestate->unit_size);
	gamestate->vars.img.addr = mlx_get_data_addr(gamestate->vars.img.img,
			&gamestate->vars.img.bits_per_pixel,
			&gamestate->vars.img.line_length, &gamestate->vars.img.endian);
	gamestate->background.img = mlx_new_image(gamestate->vars.mlx,
			gamestate->map_size.width * gamestate->unit_size,
			gamestate->map_size.height * gamestate->unit_size);
	gamestate->background.addr = mlx_get_data_addr(gamestate->background.img,
			&gamestate->background.bits_per_pixel,
			&gamestate->background.line_length,
			&gamestate->background.endian);
	gamestate->blocks_layer.img = mlx_new_image(gamestate->vars.mlx,
			gamestate->map_size.width * gamestate->unit_size,
			gamestate->map_size.height * gamestate->unit_size);
	gamestate->blocks_layer.addr = mlx_get_data_addr(
			gamestate->blocks_layer.img,
			&gamestate->blocks_layer.bits_per_pixel,
			&gamestate->blocks_layer.line_length,
			&gamestate->blocks_layer.endian);
}

void	load_gamestate(t_gamestate *gamestate, char *map_src)
{
	t_size	bg_size;

	store_map(map_src, gamestate);
	gamestate->vars.mlx = mlx_init();
	gamestate->vars.win = mlx_new_window(gamestate->vars.mlx,
			GAME_WIDTH,
			GAME_HEIGHT, "So long");
	load_screens(gamestate);
	bg_size.width = gamestate->map_size.width * gamestate->unit_size;
	bg_size.height = gamestate->map_size.height * gamestate->unit_size;
	ft_put_gradient(bg_size,
		0x003B364E, 0x00797296, gamestate->background);
	render_layers(gamestate);
	copy_img(&gamestate->blocks_layer, &gamestate->vars.img,
		gamestate->map_size.width * gamestate->unit_size,
		gamestate->map_size.height * gamestate->unit_size);
}

int	main(int argc, char **argv)
{
	t_gamestate	gamestate;

	if (argc < 2)
	{
		printf("Error.\n");
		return (0);
	}
	load_sprites(&gamestate);
	load_gamestate(&gamestate, argv[1]);
	mlx_hook(gamestate.vars.win, 2, 0, on_press, &gamestate);
	mlx_hook(gamestate.vars.win, 3, 0, on_release, &gamestate);
	mlx_hook(gamestate.vars.win, 17, 0, clean_exit_event, &gamestate);
	mlx_loop_hook(gamestate.vars.mlx, render_next_frame, &gamestate);
	mlx_loop(gamestate.vars.mlx);
}

static int	clean_exit_event(void *gamestate)
{
	clean_exit((t_gamestate *)gamestate);
	return (0);
}
