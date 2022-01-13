/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avaures <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:58:34 by avaures           #+#    #+#             */
/*   Updated: 2021/12/03 22:45:22 by avaures          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	int		i;
	int		j;
	char	*trimmed;

	if (!s1)
		return (0);
	len = ft_strlen(s1);
	i = 0;
	j = len - 1;
	while (ft_strchr(set, s1[i]) != NULL && i <= len / 2)
		i++;
	while (ft_strchr(set, s1[j]) != NULL && j >= len / 2)
		j--;
	if (i > j)
	{
		trimmed = (char *)malloc(1);
		if (!trimmed)
			return (0);
		trimmed[0] = '\0';
		return (trimmed);
	}
	else
		len = j - i;
	return (ft_substr(s1, i, len + 1));
}
