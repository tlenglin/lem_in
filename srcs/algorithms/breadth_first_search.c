/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breadth_first_search.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:04:20 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/22 14:03:42 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	set_path_bis(t_map *map, int **path, int i)
{
	int count;
	int j;
	int *tmp;

	count = 1;
	if (!(tmp = malloc(sizeof(int) * (count + 100))))
		return (0);
	j = 0;
	while ((*path)[j] != -1)
	{
		tmp[j + 1] = (*path)[j];
		j++;
	}
	tmp[j + 1] = -1;
	tmp[0] = map->room[i].previous;
	free(*path);
	*path = tmp;
	count++;
	return (1);
}

int	set_path(t_map *map, int ***paths)
{
	int	*path;
	int i;

	i = map->end;
	if (!(path = malloc(sizeof(int) * 2 + 10)))
		return (0);
	path[0] = map->end;
	path[1] = -1;
	while (map->room[i].previous != -1)
	{
		if (set_path_bis(map, &path, i) == 0)
			return (0);
		i = map->room[i].previous;
	}
	realloc_paths(paths, path);
	return (1);
}

int	set_previous(t_map *map, int **queue, int ***paths)
{
	int link;
	int	i;

	i = -1;
	if (free_queue(queue) == 0)
		return (0);
	while (map->room[(*queue)[0]].link[++i] != -1)
	{
		link = map->room[(*queue)[0]].link[i];
		if (link == map->end)
		{
			map->room[link].previous = (*queue)[0];
			free((*queue));
			set_path(map, paths);
			return (1);
		}
		else if (map->room[link].visited != 1)
		{
			map->room[link].visited = 1;
			map->room[link].previous = (*queue)[0];
			realloc_last_queue(queue, link);
		}
	}
	remove_first_queue(queue);
	return (set_previous(map, queue, paths));
}

int	breadth_first_search(t_map map, int ***paths)
{
	int	*queue;

	queue = NULL;
	if (init_queue(&queue, &map) == 0)
		return (0);
	if (set_previous(&map, &queue, paths) == 0)
		return (0);
	return (1);
}
