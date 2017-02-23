/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel_paths_search.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 11:14:46 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/22 14:24:09 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	remove_links(t_map *map, int nb)
{
	int i;
	int j;

	i = 0;
	while (map->room[i].name != NULL)
	{
		j = 0;
		map->room[i].visited = 0;
		while (map->room[i].link[j] != -1)
		{
			if (map->room[i].link[j] == nb)
				map->room[i].link[j] = i;
			j++;
		}
		i++;
	}
	return (1);
}

int	remove_visited_rooms(t_map *map, int **paths)
{
	int i;
	int j;

	i = 0;
	while (paths[i] != NULL)
	{
		j = 1;
		while (paths[i][j + 1] != -1)
		{
			remove_links(map, paths[i][j]);
			j++;
		}
		i++;
	}
	return (0);
}

int	parallel_paths_search(t_map map, int **paths, int max_paths,
	int ***optimal_paths)
{
	int i;
	int j;
	int k;

	i = 0;
	while (i < max_paths)
	{
		if (breadth_first_search(map, &paths) == 0)
			return (0);
		if (*optimal_paths == NULL)
			*optimal_paths = paths;
		else
		{
			j = strlen_tab_int(paths[1], -1);
			k = strlen_tab_int(paths[0], -1);
			if (k - 1 + map.ants / 2 - 1 < map.ants + j - 1 - 1)
				*optimal_paths = paths;
			else
				free((paths[1]));
		}
		remove_visited_rooms(&map, paths);
		i++;
	}
	return (1);
}

int	algorithm_main(t_map *map, int ***paths, t_bonus *bonus)
{
	int	max_paths;
	int i;
	int	**optimal_paths;
	int j;

	i = 0;
	j = 0;
	max_paths = 2;
	optimal_paths = NULL;
	if (map->ants > 0 && parallel_paths_search(*map, *paths, max_paths,
		&optimal_paths) == 0 &&
	optimal_paths == NULL)
	{
		return (0);
	}
	ft_putstr(map->inputs);
	if (map->ants > 0)
		send_ants(map, &optimal_paths, bonus);
	return (1);
}
