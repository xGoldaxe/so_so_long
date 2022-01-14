/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mif_clean.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 18:45:03 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/14 17:53:51 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mif_manager.h"

void	mif_clean(t_mif *mif)
{
	t_list	*next;

	while (mif->colors)
	{
		next = mif->colors->next;
		free(mif->colors->content);
		free(mif->colors);
		mif->colors = next;
	}
	free(mif->container);
}
