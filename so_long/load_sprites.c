/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 12:09:20 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/15 15:07:32 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	load_sprites(t_gamestate *gamestate)
{
	gamestate->mif = malloc(sizeof(t_mif) * 100);
	mif_read("./files/ennemies.mif", &gamestate->mif[0]);
	mif_read("./files/ennemies2.mif", &gamestate->mif[1]);
	mif_read("./files/c.mif", &gamestate->mif[2]);
	mif_read("./files/exit.mif", &gamestate->mif[3]);
	mif_read("./files/wall.mif", &gamestate->mif[4]);
	mif_read("./files/perso_iddle_1.mif", &gamestate->mif[5]);
	mif_read("./files/perso_iddle_2.mif", &gamestate->mif[6]);
	mif_read("./files/perso_walk_1.mif", &gamestate->mif[7]);
	mif_read("./files/perso_walk_2.mif", &gamestate->mif[8]);
	mif_read("./files/perso_walk_3.mif", &gamestate->mif[9]);
	mif_read("./files/perso_walk_4.mif", &gamestate->mif[10]);
}

void	free_sprites(t_mif *mif)
{
	int	i;

	i = 0;
	while (i < 11)
	{
		if (&mif[i])
			mif_clean(&mif[i]);
		i++;
	}
	free(mif);
}
