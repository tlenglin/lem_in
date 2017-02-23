/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inputs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:38:05 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/22 14:34:49 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	check_ants_inputs(char *line)
{
	if (is_number(line) == 0)
		return (0);
	if (ft_atoi(line) < 0)
		return (0);
	if (ft_atoi_long(line) > 2147483647 || ft_atoi_long(line) < -2147483648)
		return (0);
	return (1);
}

int	check_name(char *str, t_map *map)
{
	int i;

	i = 0;
	while (map->room[i].name != NULL)
	{
		if (ft_strcmp(map->room[i].name, str) == 0)
			return (i);
		i++;
	}
	return (-1);
}

int	check_links_inputs(char *str, t_map *map)
{
	int		i;
	char	**split;
	int		count;
	int		count2;

	split = NULL;
	if (check_hyphen(str) == 0)
		return (0);
	ft_new_strsplit(str, '-', &split);
	i = 0;
	count = 0;
	count2 = 0;
	while (map->room[i].name != NULL)
	{
		if (ft_strcmp((map->room[i]).name, split[0]) == 0)
			count = (count == 0) ? 1 : 2;
		else if (ft_strcmp((map->room)[i].name, split[1]) == 0)
			count2 = (count2 == 0) ? 1 : 2;
		i++;
	}
	free_split(&split);
	if (count == 0 || count == 2 || count2 == 0 || count2 == 2)
		return (0);
	return (1);
}

int	check_rooms_inputs(char *str, t_map *map)
{
	char	**split;
	int		i;

	split = NULL;
	i = 0;
	if (str[0] == '#')
		return (-2);
	ft_new_strsplit(str, ' ', &split);
	while (split[i] != NULL)
		i++;
	if (i < 2)
		return (free_split(&split));
	return (check_rooms_inputs_bis(str, &split, map, i));
}

int	check_rooms_inputs_bis(char *str, char ***split, t_map *map, int i)
{
	int len1;
	int len2;
	int length;

	len2 = ft_strlenint((*split)[i - 2]);
	len1 = ft_strlenint((*split)[i - 1]);
	length = ft_strlen(str);
	if (str[0] == 'L' || is_number((*split)[i - 1]) == 0 ||
	is_number((*split)[i - 2]) == 0)
		return (free_split(split));
	if (str[length - len2 - 2] == ' ' || str[length - len2 - len1 - 3] == ' ')
		return (free_split(split));
	while (i - 2 >= 0)
	{
		if (ft_strchr((*split)[i - 2], '-') != 0)
			return (free_split(split));
		i--;
	}
	free_split(split);
	return (pre_init_room(str, len1, len2, map));
}
