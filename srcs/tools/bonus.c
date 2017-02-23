/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/19 20:23:31 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/22 15:15:29 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/lem_in.h"

int	init_bonus(int argc, char **argv, t_bonus *bonus)
{
	int i;

	i = 1;
	bonus->print = 0;
	bonus->infos = 0;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-infos") == 0)
			bonus->infos = 1;
		else
			return (0);
		i++;
	}
	return (1);
}

int	print_infos1(t_map *map, int **optimal_paths, t_bonus *bonus)
{
	if (bonus->infos == 1 && map->ants > 0)
	{
		ft_putstr("\n----------BONUS----------\n\nnumber of steps = ");
		ft_putnbr(strlen_tab_int(optimal_paths[0], -1) - 2 + map->ants);
		ft_putstr(" steps\n\n");
		ft_putstr("best = ");
		ft_putnbr(strlen_tab_int(optimal_paths[0], -1) - 2 + map->ants);
		ft_putstr(" steps.\n\nexample = ");
		ft_putnbr(map->ants);
		ft_putstr(" ants in path 1\n\n");
		ft_putstr("length path 1 = ");
		ft_putnbr(strlen_tab_int(optimal_paths[0], -1) - 1);
		ft_putstr("\n");
	}
	return (0);
}

int	print_infos3(t_map *map, int **optimal_paths, t_bonus *bonus)
{
	int len1;
	int len2;

	len1 = strlen_tab_int(optimal_paths[0], -1);
	len2 = strlen_tab_int(optimal_paths[1], -1);
	ft_putstr("\n----------BONUS----------\n\nnumber of steps = ");
	ft_putnbr((strlen_tab_int(optimal_paths[1], -1) > 1) ? bonus->print :
	strlen_tab_int(optimal_paths[0], -1) - 2 + map->ants);
	ft_putstr("\n\n");
	ft_putstr("best =  ");
	ft_putnbr(MAX((map->ants + 1) / 2 + (len2 - len1) / 2 - 1 + len1 -
	1, (map->ants) / 2 - (len2 - len1) / 2 - 1 + len2 - 1));
	ft_putstr(" steps.\n\nexample = ");
	ft_putnbr((map->ants + 1) / 2 + (strlen_tab_int(optimal_paths[1], -1) -
	strlen_tab_int(optimal_paths[0], -1)) / 2);
	ft_putstr(" ants in path 1 and ");
	ft_putnbr(map->ants / 2 - (strlen_tab_int(optimal_paths[1], -1) -
	strlen_tab_int(optimal_paths[0], -1)) / 2);
	ft_putstr(" ants in path 2.\n\n");
	return (0);
}

int	print_infos2(t_map *map, int **optimal_paths, t_bonus *bonus)
{
	if (bonus->infos == 1 && map->ants > 0)
	{
		print_infos3(map, optimal_paths, bonus);
		ft_putstr("length path 1 = ");
		ft_putnbr(strlen_tab_int(optimal_paths[0], -1) - 1);
		ft_putstr("\n");
		if (strlen_tab_int(optimal_paths[1], -1) > 1)
		{
			ft_putstr("length path 2 = ");
			ft_putnbr(strlen_tab_int(optimal_paths[1], -1) - 1);
			ft_putstr("\n");
		}
	}
	return (0);
}
