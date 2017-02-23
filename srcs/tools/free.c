/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 13:32:58 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/21 15:58:24 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	free_split(char ***split)
{
	int i;

	i = 0;
	while ((*split)[i])
	{
		free((*split)[i]);
		i++;
	}
	free((*split)[i]);
	free(*split);
	return (-1);
}

int	free_map_and_paths(t_map *map)
{
	int i;

	i = 0;
	while (map->room[i].name != NULL)
	{
		free(map->room[i].name);
		free(map->room[i].link);
		i++;
	}
	free(map->room[i].name);
	free(map->room);
	free(map->inputs);
	return (0);
}

int	free_queue(int **queue)
{
	if ((*queue)[0] == -1)
	{
		free(*queue);
		return (0);
	}
	return (1);
}
