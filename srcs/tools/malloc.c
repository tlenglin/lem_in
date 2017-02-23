/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:14:24 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/21 16:09:46 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	realloc_paths(int ***paths, int *path)
{
	int i;
	int length;
	int **tmp;

	i = 0;
	length = 0;
	while ((*paths)[length] != NULL)
		length++;
	if (!(tmp = malloc(sizeof(int*) * (length + 10))))
		return (0);
	while ((*paths)[i] != NULL)
	{
		tmp[i] = (*paths)[i];
		i++;
	}
	free((*paths));
	tmp[i] = path;
	tmp[i + 1] = NULL;
	(*paths) = tmp;
	return (1);
}

int	remove_first_queue(int **queue)
{
	int length;
	int *tmp;
	int i;

	length = 0;
	i = 0;
	while ((*queue)[length] != -1)
		length++;
	if (!(tmp = malloc(sizeof(int) * (length))))
		return (0);
	while ((*queue)[i + 1] != -1)
	{
		tmp[i] = (*queue)[i + 1];
		i++;
	}
	free((*queue));
	tmp[i] = -1;
	(*queue) = tmp;
	return (1);
}

int	realloc_last_queue(int **queue, int link)
{
	int length;
	int *tmp;
	int i;

	length = 0;
	i = 0;
	while ((*queue)[length] != -1)
		length++;
	if (!(tmp = malloc(sizeof(int) * (length + 2))))
		return (0);
	while ((*queue)[i] != -1)
	{
		tmp[i] = (*queue)[i];
		i++;
	}
	free((*queue));
	tmp[i] = link;
	tmp[i + 1] = -1;
	(*queue) = tmp;
	return (1);
}

int	realloc_room(char *str, t_map *map)
{
	int		length;
	int		i;
	t_room	*room_tmp;

	length = 0;
	i = -1;
	while (map->room[length].name != NULL)
		length++;
	if (!(room_tmp = malloc(sizeof(t_room) * (length + 2))))
		return (0);
	while (map->room[++i].name != NULL)
		room_tmp[i] = map->room[i];
	i--;
	while (map->room[++i].name != NULL)
		room_tmp[i] = map->room[i];
	free(map->room[i].name);
	free(map->room);
	room_tmp[i].name = ft_strdup(str);
	room_tmp[i + 1].name = NULL;
	if (!(room_tmp[i].link = malloc(sizeof(int) * 2)))
		return (0);
	room_tmp[i].link[0] = -1;
	map->room = room_tmp;
	return (length);
}

int	realloc_link(t_room *room, int index)
{
	int i;
	int	*tmp;

	i = 0;
	while (room->link[i] != -1)
	{
		if (room->link[i] == index)
			return (1);
		i++;
	}
	if (!(tmp = malloc(sizeof(int) * i + 10)))
		return (0);
	i = 0;
	while (room->link[i] != -1)
	{
		tmp[i] = room->link[i];
		i++;
	}
	free(room->link);
	tmp[i] = index;
	tmp[i + 1] = -1;
	room->link = tmp;
	return (1);
}
