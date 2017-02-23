/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 13:59:26 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/22 16:37:13 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	odd_number(t_map *map, int *optimal_paths, int j, int len1)
{
	int k;
	int l;

	k = (j + 1 > len1) ? len1 : (j + 1);
	l = (j + 1 > len1) ? j - len1 + 1 : 0;
	while (k > 0 && 2 * l + 1 < ((map->ants + 1)))
	{
		print_line(2 * l + 1, map->room[optimal_paths[k]].name);
		k--;
		l++;
		if (k > 0 && 2 * l + 1 < ((map->ants + 1)))
			ft_putstr(" ");
	}
	return (0);
}

int	even_number(t_map *map, int *optimal_paths, int j, int len2)
{
	int k;
	int l;

	k = (j + 1 > len2) ? len2 : j + 1;
	l = (j + 1 > len2) ? j - len2 + 1 : 0;
	while (k > 0 && 2 * l + 2 < (map->ants + 1))
	{
		print_line(2 * l + 2, map->room[optimal_paths[k]].name);
		k--;
		l++;
		if (k > 0 && 2 * l + 2 < (map->ants + 1))
			ft_putstr(" ");
	}
	return (0);
}

int	send_ants_two_path(t_map *map, int **optimal_paths, t_bonus *bonus)
{
	int len1;
	int len2;
	int j;

	len1 = strlen_tab_int(optimal_paths[0], -1) - 1;
	len2 = strlen_tab_int(optimal_paths[1], -1) - 1;
	j = 0;
	while (2 * (j - len2 + 2) < map->ants + 2)
	{
		if (2 * (j - len1 + 1) < map->ants)
		{
			odd_number(map, optimal_paths[0], j, len1);
			ft_putstr(" ");
		}
		if (2 * (j - len2 + 2) < map->ants + 1)
			even_number(map, optimal_paths[1], j, len2);
		if ((2 * (j - len1 + 1) < map->ants) || (2 * (j - len2 + 2) <
		map->ants + 1))
			bonus->print++;
		j++;
		if ((2 * (j - len1 + 1) < map->ants) || (2 * (j - len2 + 2) <
		map->ants + 1))
			ft_putstr("\n");
	}
	return (0);
}

int	send_ants_one_path_ter(t_map *map, int i, int len, int *path)
{
	int j;

	while (i < map->ants + len + 1)
	{
		j = len;
		while (j > 0 && i - j + 1 < map->ants + 1)
		{
			print_line(i - j + 1, map->room[path[j]].name);
			j--;
			if (j != 0 && i - j + 1 < map->ants + 1)
				ft_putstr(" ");
		}
		i++;
		if (i != map->ants + len + 1)
			ft_putstr("\n");
	}
	return (0);
}
