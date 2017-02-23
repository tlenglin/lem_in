/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 15:32:44 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/22 14:23:02 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	print_line(int ant, char *name)
{
	ft_putstr("L");
	ft_putnbr(ant);
	ft_putstr("-");
	ft_putstr(name);
	return (0);
}

int	send_ants_one_path_bis(t_map *map, int *path)
{
	int i;
	int j;

	i = 1;
	ft_putchar('\n');
	while (path[i] != -1 && i < map->ants)
	{
		j = i;
		if (i - j + 1 > map->ants)
			break ;
		while (j > 0)
		{
			print_line(i - j + 1, map->room[path[j]].name);
			if (j != 1)
				ft_putstr(" ");
			j--;
		}
		ft_putstr("\n");
		i++;
	}
	return (i);
}

int	send_ants_one_path(t_map *map, int *path)
{
	int i;
	int j;
	int len;

	len = 0;
	while (path[len + 1] != -1)
		len++;
	i = send_ants_one_path_bis(map, path);
	while (i < map->ants + 1 || i < len)
	{
		j = i > len ? len : i;
		while (j > 0 && i - j + 1 > 0 && i - j + 1 < map->ants + 1 &&
			path[j] != -1)
		{
			print_line(i - j + 1, map->room[path[j]].name);
			j--;
			if (j > 0 && i - j + 1 > 0 && i - j + 1 < map->ants + 1 &&
				path[j] != -1)
				ft_putstr(" ");
		}
		ft_putstr("\n");
		i++;
	}
	send_ants_one_path_ter(map, i, len, path);
	return (0);
}

int	send_ants(t_map *map, int ***optimal_paths, t_bonus *bonus)
{
	if ((*optimal_paths)[0] == NULL)
		return (0);
	if (((*optimal_paths)[1] == NULL || (*optimal_paths)[1][1] == map->end ||
	strlen_tab_int((*optimal_paths)[0], -1) - 2 + map->ants <=
	strlen_tab_int((*optimal_paths)[1], -1) - 2 + (map->ants + 1) / 2))
	{
		send_ants_one_path(map, (*optimal_paths)[0]);
		print_infos1(map, *optimal_paths, bonus);
		free((*optimal_paths)[0]);
		if ((*optimal_paths)[1] != NULL)
			free((*optimal_paths)[1]);
		free(*optimal_paths);
	}
	else
	{
		ft_putstr("\n");
		send_ants_two_path(map, *optimal_paths, bonus);
		ft_putstr("\n");
		print_infos2(map, *optimal_paths, bonus);
		free((*optimal_paths)[0]);
		free((*optimal_paths)[1]);
		free(*optimal_paths);
	}
	return (1);
}

int	get_string_inputs(char *str, t_map *map)
{
	char	*tmp;
	int		i;
	int		j;
	int		len;

	len = (map->inputs) ? ft_strlen(map->inputs) : 0;
	if (!(tmp = malloc(ft_strlen(str) + len + 2)))
		return (0);
	i = 0;
	while (map->inputs && map->inputs[i])
	{
		tmp[i] = map->inputs[i];
		i++;
	}
	j = -1;
	while (str[++j])
		tmp[i++] = str[j];
	tmp[i] = '\n';
	tmp[i + 1] = '\0';
	if (map->inputs)
		free(map->inputs);
	map->inputs = tmp;
	return (1);
}
