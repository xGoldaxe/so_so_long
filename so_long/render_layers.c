/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_layers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:31:04 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/08 14:30:14 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_layers(t_gamestate *gamestate)
{
	copy_img(&gamestate->background, &gamestate->blocks_layer,
		gamestate->map_size.width * gamestate->unit_size,
		gamestate->map_size.height * gamestate->unit_size);
	place_elements(gamestate);
	copy_img(&gamestate->blocks_layer, &gamestate->vars.img,
		gamestate->map_size.width * gamestate->unit_size,
		gamestate->map_size.height * gamestate->unit_size);
}
