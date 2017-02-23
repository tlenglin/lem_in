/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 13:56:43 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/22 16:37:41 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	get_ants_inputs(char **line, t_map *map)
{
	if (get_next_line(0, line) != 1)
		return (0);
	get_string_inputs(*line, map);
	if (check_ants_inputs(*line) == 0)
	{
		free(*line);
		return (0);
	}
	map->ants = ft_atoi(*line);
	free(*line);
	return (1);
}

int	get_inputs(t_map *map)
{
	char	*line;

	line = NULL;
	if (get_ants_inputs(&line, map) == 0)
		return (0);
	if (get_rooms_inputs(&line, map) == 0)
		return (0);
	return (1);
}

int	error(t_map *map, int ***paths)
{
	free_map_and_paths(map);
	free(*paths);
	ft_putstr("Error\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_map	map;
	int		**paths;
	t_bonus bonus;

	if (argc > 4)
		return (0);
	if (init_bonus(argc, argv, &bonus) == 0)
	{
		return (0);
	}
	init_map_and_paths(&map, &paths);
	if (get_inputs(&map) == 0)
		return (error(&map, &paths));
	if (map.start == -1 || map.end == -1 || map.start == map.end)
		return (error(&map, &paths));
	if (algorithm_main(&map, &paths, &bonus) == 0)
		return (error(&map, &paths));
	free_map_and_paths(&map);
	return (0);
}
