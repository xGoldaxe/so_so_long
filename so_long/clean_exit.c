/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:49:43 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/20 18:00:56 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_elements(t_gamestate *gamestate)
{
	t_list	*next;

	while (gamestate->elements)
	{
		next = gamestate->elements->next;
		free(gamestate->elements->content);
		free(gamestate->elements);
		gamestate->elements = next;
	}
}

void	clean_exit(t_gamestate *gamestate)
{
	mlx_destroy_image(gamestate->vars.mlx, gamestate->vars.img.img);
	mlx_destroy_image(gamestate->vars.mlx, gamestate->background.img);
	mlx_destroy_image(gamestate->vars.mlx, gamestate->blocks_layer.img);
	if (gamestate->str_loaded)
		clean_str(gamestate->str_loaded);
	if (gamestate->mif)
		free_sprites(gamestate->mif);
	if (gamestate->elements)
		free_elements(gamestate);
	exit(EXIT_SUCCESS);
}

void	parse_error(t_gamestate *gamestate)
{
	printf("Error.\n");
	clean_exit(gamestate);
	exit(1);
}
