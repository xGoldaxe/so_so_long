/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleveque <pleveque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 16:47:47 by pleveque          #+#    #+#             */
/*   Updated: 2022/01/14 18:24:50 by pleveque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strnlen(char *line)
{
	int	i;

	if (!line)
		return (-1);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	return (i);
}

int	line_wall_full(char *line, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	ft_arrinclude(char *charset, int c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (i);
		++i;
	}
	return (-1);
}

void	iterate_line(char *line, t_coord *actual_coord,
int *required, t_gamestate *gamestate)
{
	int	line_size;

	line_size = ft_strnlen(line);
	if (!(line[0] == '1' && line[line_size - 1] == '1')
		|| (line[line_size] == '\0' && !line_wall_full(line, line_size)))
		parse_error();
	actual_coord->x = 0;
	while (actual_coord->x < line_size)
	{
		if (ft_arrinclude("01PECHV", line[actual_coord->x]) == -1)
			parse_error();
		if (ft_arrinclude("PEC", line[actual_coord->x]) != -1)
			required[ft_arrinclude("PEC", line[actual_coord->x])] = 1;
		if (required[3])
			add_element(line[actual_coord->x], *actual_coord, gamestate);
		actual_coord->x++;
	}
}

void	read_map(int fd, t_gamestate *gamestate, int is_storing)
{
	char	*line;
	int		required[4];
	t_coord	actual_coord;

	line = get_next_line(fd);
	gamestate->map_size.width = ft_strnlen(line);
	if (!line || !line_wall_full(line, gamestate->map_size.width))
		parse_error();
	actual_coord.y = 0;
	required[0] = 0;
	required[1] = 0;
	required[2] = 0;
	required[3] = is_storing;
	while (line)
	{
		if (ft_strnlen(line) != gamestate->map_size.width)
			parse_error();
		iterate_line(line, &actual_coord, required, gamestate);
		line = get_next_line(fd);
		actual_coord.y++;
	}
	if (!required[0] || !required[1] || !required[2])
		parse_error();
	gamestate->map_size.height = actual_coord.y;
}
