/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loaded_ressources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 16:29:16 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/14 16:48:46 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*malloc_load(int size, void (*free_function)(void *))
{
	static t_list	*loaded;
	t_malloc		malloced;

	malloced.content = malloc(size);
	malloced.cleaner = free_function;
	if (!loaded)
		loaded = ft_lstnew(&malloced);
	else
		ft_lstadd_front(&loaded, ft_lstnew(&malloced));
	return (NULL);
}
