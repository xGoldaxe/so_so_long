/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 16:49:43 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/14 18:19:24 by pleveque         ###   ########.fr       */
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
	clean_str(gamestate->str_loaded);
	free_sprites(gamestate->mif);
	free_elements(gamestate);
	exit(EXIT_SUCCESS);
}

void	parse_error(void)
{
	printf("Error.\n");
	exit(1);
}
