/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_merge.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 19:09:40 by pleveque          #+#    #+#             */
/*   Updated: 2021/12/16 19:12:22 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_realloc_cat(char *src, char *dst)
{
	char	*tmp;
	int		i;
	int		y;
	int		src_size;
	int		dst_size;

	src_size = ft_strlen(src);
	dst_size = ft_strlen(dst);
	tmp = malloc(sizeof(char) * (src_size + dst_size + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	y = 0;
	while (i < dst_size)
	{
		tmp[i] = dst[i];
		i++;
	}
	while (y < src_size)
	{
		tmp[i + y] = src[y];
		y++;
	}
	tmp[i + y] = '\0';
	return (tmp);
}

char	*ft_realloc_merge(int nb_str, ...)
{
	char			*res;
	va_list			marker;
	int				i;
	int				res_size;
	char			*step;

	va_start(marker, nb_str);
	res = NULL;
	res_size = 0;
	i = 0;
	while (i < nb_str)
	{
		step = va_arg(marker, char *);
		if (step)
		{
			res = ft_realloc_cat(step, res);
			if (!res)
				return (NULL);
		}
		i++;
	}
	return (res);
}
