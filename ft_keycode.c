/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keycode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 02:13:43 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/30 07:30:30 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	life_and_end(t_game *game, int y, int x)
{
	if (game->map[game->y / 32][game->x / 32] == 'n')
	{
		game->image_degat[0][12] = 'D';
		game->image_degat[1][12] = 'D';
		game->image_degat[2][12] = 'D';
		game->image_degat[3][12] = 'D';
		game->image_degat[4][12] = 'D';
		game->nb_steps--;
		game->vie--;
		if (game->vie == 3)
			game->image_health[14] = '2';
		if (game->vie == 2)
			game->image_health[14] = '1';
		if (game->vie == 1)
			game->image_health[14] = '0';
		if (game->vie <= 0)
		{
			write(1, "t'as plus de vie frero t'es nul\n", 33);
			ft_free(game);
		}
		game->annimation_degat = 5;
		game->y -= y;
		game->x -= x;
	}
}

void	piece(t_game *game, int y, int x)
{
	game->nb_steps += 1;
	game->y += y;
	game->x += x;
	if (game->map[game->y / 32][game->x / 32] == 'C')
	{
		game->piece++;
		game->map[game->y / 32][game->x / 32] = '0';
	}
	if (game->map[game->y / 32][game->x / 32] == 'N')
	{
		game->map[game->y / 32][game->x / 32] = 'n';
		game->image_enemy[0][14] = '1';
		game->image_enemy[1][14] = '2';
		game->image_enemy[2][14] = '3';
		game->image_enemy[3][14] = '4';
		game->image_enemy[4][14] = '5';
		game->image_enemy[5][14] = '6';
	}
	if (game->map[game->y / 32][game->x / 32] == 'e'
		&& game->piece >= game->nb_item)
	{
		ft_putstr("bravo t'es le bosse des capibara t'as gagner\n");
		ft_free(game);
	}
	life_and_end(game, y, x);
}

void	ft_attaque(t_game *game)
{
	if (game->map[game->y / 32][(game->x / 32) + 1] == 'N' || game->map[game->y
		/ 32][(game->x / 32) + 1] == 'n')
		game->map[game->y / 32][(game->x / 32) + 1] = '0';
	if (game->map[(game->y / 32) + 1][game->x / 32] == 'N' || game->map[(game->y
			/ 32) + 1][game->x / 32] == 'n')
		game->map[(game->y / 32) + 1][game->x / 32] = '0';
	if (game->map[game->y / 32][(game->x / 32) - 1] == 'N' || game->map[game->y
		/ 32][(game->x / 32) - 1] == 'n')
		game->map[game->y / 32][(game->x / 32) - 1] = '0';
	if (game->map[game->y / 32 - 1][(game->x / 32)] == 'N' || game->map[game->y
		/ 32][(game->x / 32) + 1] == 'n')
		game->map[game->y / 32 - 1][(game->x / 32)] = '0';
	game->image_degat[0][12] = 'A';
	game->image_degat[1][12] = 'A';
	game->image_degat[2][12] = 'A';
	game->image_degat[3][12] = 'A';
	game->image_degat[4][12] = 'A';
	game->annimation_degat = 5;
	game->i_img_enemy = -1;
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 65307)
		ft_free(game);
	if (keycode == 119 && game->map[(game->y / 32) - 1][game->x / 32] != '1')
		ft_up(game);
	if (keycode == 115 && game->map[(game->y / 32) + 1][game->x / 32] != '1')
		ft_down(game);
	if (keycode == 97 && game->map[game->y / 32][(game->x / 32) - 1] != '1')
		ft_right(game);
	if (keycode == 100 && game->map[game->y / 32][(game->x / 32) + 1] != '1')
		ft_left(game);
	if (keycode == 32)
		ft_attaque(game);
	return (0);
}
