/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:09:20 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/12 18:11:46 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_gamestate *gamestate)
{
	gamestate->mif = malloc(sizeof(t_mif) * 100);
	mif_read("./files/ennemies.mif", &gamestate->mif[0]);
	mif_read("./files/ennemies2.mif", &gamestate->mif[1]);
	mif_read("./files/c.mif", &gamestate->mif[3]);
	mif_read("./files/exit.mif", &gamestate->mif[4]);
	mif_read("./files/wall.mif", &gamestate->mif[5]);
	mif_read("./files/perso_iddle_1.mif", &gamestate->mif[10]);
	mif_read("./files/perso_iddle_2.mif", &gamestate->mif[11]);
	mif_read("./files/perso_walk_1.mif", &gamestate->mif[12]);
	mif_read("./files/perso_walk_2.mif", &gamestate->mif[13]);
	mif_read("./files/perso_walk_3.mif", &gamestate->mif[14]);
	mif_read("./files/perso_walk_4.mif", &gamestate->mif[15]);
}