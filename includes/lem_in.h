/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:00:01 by tlenglin          #+#    #+#             */
/*   Updated: 2017/02/22 15:05:54 by tlenglin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../Libft/libft.h"
# include <stdlib.h>

# define MAX(x,y) (x > y ? x : y)

typedef struct	s_room
{
	char	*name;
	int		*link;
	int		previous;
	int		visited;
}				t_room;

typedef struct	s_map
{
	t_room	*room;
	int		ants;
	int		start;
	int		end;
	char	*inputs;
}				t_map;

typedef struct	s_bonus
{
	int	print;
	int	infos;
}				t_bonus;

int				init_map_and_paths(t_map *map, int ***paths);
int				init_room(char *line, t_map *map);
int				init_link(char *str, t_map *map);
int				init_start_end(char **line, t_map *map, int i);
int				pre_init_room(char *str, int len1, int len2, t_map *map);
int				check_ants_inputs(char *line);
int				check_name(char *str, t_map *map);
int				check_links_inputs(char *str, t_map *map);
int				check_rooms_inputs(char *str, t_map *map);
int				check_rooms_inputs_bis(char *str, char ***split, t_map *map,
	int i);
int				check_hyphen(char *str);
int				get_ants_inputs(char **line, t_map *map);
int				get_inputs(t_map *map);
int				get_rooms_inputs(char **line, t_map *map);
int				get_links_inputs(char **line, t_map *map);
int				get_comments_inputs(char **line, t_map *map);
int				get_end_inputs(char **line, t_map *map);
int				get_start_inputs(char **line, t_map *map);
int				realloc_room(char *str, t_map *map);
int				realloc_link(t_room *room, int index);
int				realloc_last_queue(int **queue, int link);
int				realloc_paths(int ***paths, int *path);
int				remove_first_queue(int **queue);
int				free_split(char ***str);
int				free_map_and_paths(t_map *map);
int				free_queue(int **queue);
int				display_map(t_map map);
int				display_path(t_map map, int ***paths, int nb);
int				set_previous(t_map *map, int **queue, int ***paths);
int				breadth_first_search(t_map map, int ***paths);
int				set_path(t_map *map, int ***paths);
int				init_queue(int **queue, t_map *map);
int				remove_links(t_map *map, int nb);
int				remove_visited_rooms(t_map *map, int **paths);
int				parallel_paths_search(t_map map, int **paths, int max_paths,
	int ***optimal_paths);
int				algorithm_main(t_map *map, int ***paths, t_bonus *bonus);
int				get_string_inputs(char *str, t_map *map);
int				send_ants_one_path(t_map *map, int *path);
int				send_ants(t_map *map, int ***optimal_paths, t_bonus *bonus);
int				print_line(int ant, char *name);
int				send_ants_two_path(t_map *map, int **optimal_paths, t_bonus
	*bonus);
int				odd_number(t_map *map, int *optimal_paths, int j, int len1);
int				even_number(t_map *map, int *optimal_paths, int j, int len2);
int				print_message1(t_map *map, int message, int i, int j);
int				send_ants_one_path_bis(t_map *map, int *path);
int				send_ants_one_path_ter(t_map *map, int i, int len, int *path);
int				init_bonus(int argc, char **argv, t_bonus *bonus);
int				error(t_map *map, int ***paths);
int				print_infos1(t_map *map, int **optimal_paths, t_bonus *bonus);
int				print_infos2(t_map *map, int **optimal_paths, t_bonus *bonus);
int				print_infos3(t_map *map, int **optimal_paths, t_bonus *bonus);

#endif
