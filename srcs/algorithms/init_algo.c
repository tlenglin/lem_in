/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:41:00 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/21 14:16:59 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	init_queue(int **queue, t_map *map)
{
	if (!(*queue = malloc(sizeof(int) * 2)))
		return (0);
	(*queue)[0] = map->start;
	(*queue)[1] = -1;
	map->room[map->start].previous = -1;
	map->room[map->start].visited = 1;
	return (1);
}
