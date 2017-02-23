/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:10:22 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/21 15:18:00 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	init_map_and_paths(t_map *map, int ***paths)
{
	map->room = NULL;
	if (!(map->room = malloc(sizeof(t_room))))
		return (0);
	map->room[0].name = NULL;
	map->ants = 0;
	if (!(*paths = malloc(sizeof(int*) * 1)))
		return (0);
	(*paths)[0] = NULL;
	map->inputs = NULL;
	map->start = -1;
	map->end = -1;
	return (0);
}

int	pre_init_room(char *str, int len1, int len2, t_map *map)
{
	char	*tmp;
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(str);
	if (!(tmp = malloc(length - len2 - len1)))
		return (-1);
	i = 0;
	while (i < length - len2 - len1 - 2)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	i = init_room(tmp, map);
	free(tmp);
	return (i);
}

int	init_room(char *line, t_map *map)
{
	int		index;

	index = check_name(line, map);
	if (index == -1)
	{
		index = realloc_room(line, map);
	}
	map->room[index].visited = 0;
	map->room[index].previous = -1;
	return (index);
}

int	init_link(char *str, t_map *map)
{
	int		i;
	char	**split;
	int		count;
	int		count2;

	i = 0;
	split = NULL;
	ft_new_strsplit(str, '-', &split);
	while (map->room[i].name != NULL)
	{
		if (ft_strcmp(map->room[i].name, split[0]) == 0)
			count = i;
		else if (ft_strcmp(map->room[i].name, split[1]) == 0)
			count2 = i;
		i++;
	}
	free_split(&split);
	realloc_link(&map->room[count], count2);
	realloc_link(&map->room[count2], count);
	return (1);
}

int	init_start_end(char **line, t_map *map, int i)
{
	if (get_next_line(0, line) < 1)
		return (0);
	if (check_rooms_inputs(*line, map) == -1)
		return (0);
	if (i == 1)
		map->start = init_room(*line, map);
	else if (i == 2)
		map->end = init_room(*line, map);
	free(*line);
	*line = NULL;
	return (1);
}
