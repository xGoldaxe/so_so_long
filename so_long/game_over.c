/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 17:31:52 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/08 14:32:43 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_text(t_elt_opt opt)
{
	opt.coord.y = 450;
	opt.color = 0x000aaf9e;
	put_str(opt, "SO LOOOONG", 6);
	opt.coord.y = 650;
	opt.color = 0x001000ff;
	put_str(opt, "PRESS ESCAPE TO LEAVE", 2);
	opt.coord.y = 150;
	opt.color = 0x00ff0000;
	put_str(opt, "GAME OVER", 5);
}

static t_data	generate_screen(t_data screen, t_gamestate *gamestate)
{
	char			*tmp;
	t_size			screen_size;
	t_elt_opt		opt;

	screen.img = mlx_new_image(gamestate->vars.mlx, GAME_WIDTH, GAME_HEIGHT);
	screen.addr = mlx_get_data_addr(
			screen.img, &screen.bits_per_pixel,
			&screen.line_length, &screen.endian);
	screen_size.width = GAME_WIDTH;
	screen_size.height = GAME_HEIGHT;
	opt.coord.x = GAME_WIDTH / 2;
	opt.img = screen;
	ft_put_gradient(screen_size, 0x006b6ba4, 0x00333333, screen);
	tmp = ft_realloc_cat(ft_itoa(gamestate->score), "SCORE: ");
	printf("%s\n", tmp);
	opt.coord.y = 300;
	opt.color = 0x00ffffff;
	put_str(opt, tmp, 3);
	free(tmp);
	print_text(opt);
	return (screen);
}

void	game_over(t_gamestate *gamestate)
{
	t_vars			*vars;
	static int		animation_state = 0;
	static t_data	screen;

	vars = &(gamestate->vars);
	if (animation_state == 0)
		screen = generate_screen(screen, gamestate);
	if (animation_state + 3 > 100)
		animation_state = -1;
	if (animation_state != -1 && animation_state <= 100)
	{
		animation_state += 3;
		mlx_put_image_to_window(gamestate->vars.mlx, gamestate->vars.win,
			screen.img, 0,
			- GAME_HEIGHT + GAME_HEIGHT * animation_state / 100);
	}
	else
		mlx_put_image_to_window(gamestate->vars.mlx,
			gamestate->vars.win, screen.img, 0, 0);
}
