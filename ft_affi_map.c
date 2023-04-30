/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_affi_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 07:26:04 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/30 07:54:51 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_file(t_game *game)
{
	int	w;
	int	h;

	game->top = mlx_xpm_file_to_image(game->mlx, "./asset/DT.xpm", &w, &h);
	game->top_right = mlx_xpm_file_to_image(game->mlx, "./asset/DTR.xpm", &w,
			&h);
	game->top_left = mlx_xpm_file_to_image(game->mlx, "./asset/DTL.xpm", &w,
			&h);
	game->down = mlx_xpm_file_to_image(game->mlx, "./asset/DD.xpm", &w, &h);
	game->down_right = mlx_xpm_file_to_image(game->mlx, "./asset/DDR.xpm", &w,
			&h);
	game->down_left = mlx_xpm_file_to_image(game->mlx, "./asset/DDL.xpm", &w,
			&h);
	game->left = mlx_xpm_file_to_image(game->mlx, "./asset/DL.xpm", &w, &h);
	game->right = mlx_xpm_file_to_image(game->mlx, "./asset/DR.xpm", &w, &h);
	game->back = mlx_xpm_file_to_image(game->mlx, "./asset/B1.xpm", &w, &h);
	game->barrier = mlx_xpm_file_to_image(game->mlx,
			"./asset/Dungeon_Bricks1.xpm", &w, &h);
	game->chest = mlx_xpm_file_to_image(game->mlx, "./asset/Chest.xpm", &w, &h);
	game->dors_open = mlx_xpm_file_to_image(game->mlx, "./asset/DorsOpen.xpm",
			&w, &h);
	game->dors_close = mlx_xpm_file_to_image(game->mlx, "./asset/DorsClose.xpm",
			&w, &h);
}

void	ft_draw_map3(t_game *game, int y, int x)
{
	if (x == game->size_x - 1)
		mlx_put_image_to_window(game->mlx, game->win, game->right, x * 32,
			y * 32);
	else if (game->map[y][x] == '0' || game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->back, x * 32,
			y * 32);
	else if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->barrier, x * 32,
			y * 32);
	else if (game->map[y][x] == 'C' || game->map[y][x] == 'N')
		mlx_put_image_to_window(game->mlx, game->win, game->chest, x * 32,
			y * 32);
	else if (game->map[y][x] == 'n')
		mlx_put_image_to_window(game->mlx, game->win, game->img_enemy, x * 32,
			y * 32);
	else if (game->map[y][x] == 'E')
	{
		if (game->piece >= game->nb_item)
			game->map[y][x] = 'e';
		mlx_put_image_to_window(game->mlx, game->win, game->dors_close, x * 32,
			y * 32);
	}
	else if (game->map[y][x] == 'e')
		mlx_put_image_to_window(game->mlx, game->win, game->dors_open, x * 32,
			y * 32);
}

void	ft_draw_map2(t_game *game, int y, int x)
{
	if (y == 0 && x == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->top_left, x * 32,
			y * 32);
	else if (y == 0 && x != 0 && x != game->size_x - 1)
		mlx_put_image_to_window(game->mlx, game->win, game->top, x * 32,
			y * 32);
	else if (y == 0 && x == game->size_x - 1)
		mlx_put_image_to_window(game->mlx, game->win, game->top_right, x * 32,
			y * 32);
	else if (y == game->nb_ligne - 1 && x == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->down_left, x * 32,
			y * 32);
	else if (y == game->nb_ligne - 1 && x != 0 && x != game->size_x - 1)
		mlx_put_image_to_window(game->mlx, game->win, game->down, x * 32,
			y * 32);
	else if (y == game->nb_ligne - 1 && x == game->size_x - 1)
		mlx_put_image_to_window(game->mlx, game->win, game->down_right, x * 32,
			y * 32);
	else if (x == 0)
		mlx_put_image_to_window(game->mlx, game->win, game->left, x * 32,
			y * 32);
	else
		ft_draw_map3(game, y, x);
}

void	ft_dell_map2(t_game *game, int y, int x)
{
	if (y == 0 && x == 0)
		mlx_destroy_image(game->mlx, game->top_left);
	else if (y == 0 && x != 0 && x != game->size_x - 1)
		mlx_destroy_image(game->mlx, game->top);
	else if (y == 0 && x == game->size_x - 1)
		mlx_destroy_image(game->mlx, game->top_right);
	else if (y == game->nb_ligne - 1 && x == 0)
		mlx_destroy_image(game->mlx, game->down_left);
	else if (y == game->nb_ligne - 1 && x != 0 && x != game->size_x - 1)
		mlx_destroy_image(game->mlx, game->down);
	else if (y == game->nb_ligne - 1 && x == game->size_x - 1)
		mlx_destroy_image(game->mlx, game->down_right);
	else if (x == 0)
		mlx_destroy_image(game->mlx, game->left);
	else if (x == game->size_x - 1)
		mlx_destroy_image(game->mlx, game->right);
	else if (game->map[y][x] == '0')
		mlx_destroy_image(game->mlx, game->back);
	else if (game->map[y][x] == '1')
		mlx_destroy_image(game->mlx, game->barrier);
	else if (game->map[y][x] == 'C')
		mlx_destroy_image(game->mlx, game->chest);
	else if (game->map[y][x] == 'N' || game->map[y][x] == 'n')
		mlx_destroy_image(game->mlx, game->img_enemy);
}

int	ft_draw_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->nb_ligne)
	{
		if (game->map[y][x] == 'P')
		{
			game->x = x * 32;
			game->y = y * 32;
			game->map[y][x] = '0';
		}
		ft_draw_map2(game, y, x);
		x++;
		if (x >= game->size_x)
		{
			x = 0;
			y++;
		}
	}
	return (0);
}
