/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: obanshee <obanshee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:24:13 by obanshee          #+#    #+#             */
/*   Updated: 2019/11/06 22:06:13 by obanshee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

char	**g_result;
int		fillit_usage(void);
void	tetra_null(char tetrimino[26][5][5]);
int		input_check(char *line);
int		finish_input(int cur, int gnl, int num_str, char *line);
int		fillit_input(int fd, char tetrimino[26][5][5]);
int		sv_func(int cur, char tetrimino[26][5][5], int i, int j);
int		tetra_check(int cur, char tetrimino[26][5][5]);
int		transform(int cur, char *line, char tetrimino[26][5][5], int num);
void	fillit_optimal(int cur, char tetrimino[26][5][5]);
void	fillit_swap_top(int cur, char tetrimino[26][5][5]);
void	fillit_swap_left(int cur, char tetrimino[26][5][5]);
int		without_points_right(int cur, char tetrimino[26][5][5], int len);
int		without_points_bottom(int cur, char tetrimino[26][5][5], int len);
char	**new_map(int size);
void	print_res(char **map);
int		check_insert(char **map, char tetrimino[5][5], int x, int y);
int		insert_tetremino(char **map, char tetrimino[5][5], int x, int y);
int		delete_tetra(char **map, int cur);
int		search_tetra(char **map, char cur);
void	free_map(char **map, int size);
int		without_points(char **map, int len);
void	copy_map(char **map, char **res);
char	**check_min(char **map);
char	**recur(char **map, char tetrimino[26][5][5], int nbr, int ins);
int		size_map(int nbr);
void	solve(char tetrimino[26][5][5], int nbr);
void	clear_finish(char **map1, char **map2);
int		free_line(char *line);
int		reader(int fd, char *line);

#endif
