/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inputs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:01:34 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/21 16:24:25 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	get_start_inputs(char **line, t_map *map)
{
	int i;

	free(*line);
	if (get_next_line(0, line) < 1)
		return (0);
	if (check_rooms_inputs(*line, map) == -1)
	{
		free(*line);
		return (0);
	}
	else if ((i = check_rooms_inputs(*line, map)) == -2)
	{
		get_string_inputs(*line, map);
		return (get_start_inputs(line, map));
	}
	else
	{
		get_string_inputs(*line, map);
		free(*line);
		map->start = i;
		return (1);
	}
}

int	get_end_inputs(char **line, t_map *map)
{
	int i;

	free(*line);
	if (get_next_line(0, line) < 1)
		return (0);
	if (check_rooms_inputs(*line, map) == -1)
	{
		free(*line);
		return (0);
	}
	else if ((i = check_rooms_inputs(*line, map)) == -2)
	{
		get_string_inputs(*line, map);
		return (get_start_inputs(line, map));
	}
	else
	{
		get_string_inputs(*line, map);
		free(*line);
		map->end = i;
		return (1);
	}
}

int	get_comments_inputs(char **line, t_map *map)
{
	if (ft_strcmp(*line, "##start") == 0)
	{
		if (get_start_inputs(line, map) == 0)
			return (0);
	}
	else if (ft_strcmp(*line, "##end") == 0)
	{
		if (get_end_inputs(line, map) == 0)
			return (0);
	}
	else
	{
		free(*line);
	}
	return (1);
}

int	get_links_inputs(char **line, t_map *map)
{
	int ret;

	while ((ret = get_next_line(0, line)) == 1)
	{
		get_string_inputs(*line, map);
		if ((*line)[0] == '#')
			get_comments_inputs(line, map);
		else
		{
			if (check_links_inputs(*line, map) == 0)
			{
				free(*line);
				*line = NULL;
				return (0);
			}
			init_link(*line, map);
			free(*line);
			*line = NULL;
		}
	}
	return (1);
}

int	get_rooms_inputs(char **line, t_map *map)
{
	while (get_next_line(0, line) == 1)
	{
		get_string_inputs(*line, map);
		if (check_rooms_inputs(*line, map) == -1)
		{
			if (check_links_inputs(*line, map) == 0)
			{
				free(*line);
				return (0);
			}
			init_link(*line, map);
			free(*line);
			return (get_links_inputs(line, map));
		}
		else if (check_rooms_inputs(*line, map) == -2)
		{
			if (get_comments_inputs(line, map) == 0)
				return (0);
		}
		else
			free(*line);
	}
	return (0);
}
