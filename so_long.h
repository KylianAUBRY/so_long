/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:21:04 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/30 04:12:14 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**image;
	void	*img;
	int		i_img;
	int		nb_max_img;
	char	**image_degat;
	char	*image_health;
	void	*img_health;
	int		x;
	int		y;
	int		piece;
	int		vie;
	int		nb_steps;
	int		annimation_degat;
	void	*degat;
	void	*img_enemy;
	char	**image_enemy;
	int		i_img_enemy;
	int		nb_max_img_enemy;
	char	**map;
	int		nb_item;
	char	**map_temp;
	char	**image_map;
	void	*top;
	void	*top_right;
	void	*top_left;
	void	*down;
	void	*down_right;
	void	*down_left;
	void	*left;
	void	*right;
	void	*back;
	void	*barrier;
	void	*chest;
	void	*dors_open;
	void	*dors_close;
	int		nb_ligne;
	int		size_x;
	int		temp_x;
	int		temp_y;

}			t_game;
int			ft_check_file1(char *argv, char *dest);
int			ft_init_map(char *argv, t_game *game, int read_file);
char		*ft_freejoin(char *s1, char const *s2);
char		*ft_strdup(char *s);
int			ft_strlen(const char *s);
int			ft_strlen_line(char *dest);
int			ft_adieux(t_game *game);
int			ft_free(t_game *game);
int			verif_map_to_tab(t_game *game, char *dest);
int			map_to_tab(t_game *game, char *dest);
int			map_is_good(t_game *game);
void		ft_cherch_joueur(t_game *game);
int			map_to_tab_temp(t_game *game, char *dest);
int			verif_map_to_tab(t_game *game, char *dest);
int			map_is_good(t_game *game);
void		affi_map(t_game *game);
int			ft_draw_map(t_game *game);
void		ft_file(t_game *game);
char		*ft_itoa(int n);
void		ft_right(t_game *game);
void		piece(t_game *game, int y, int x);
void		ft_left(t_game *game);
void		ft_up(t_game *game);
void		ft_down(t_game *game);
int			key_hook(int keycode, t_game *game);
int			ft_putstr(char *dest);
int			ft_putstr_zero(char *dest);
int			erreur_map(char *dest);
#endif
