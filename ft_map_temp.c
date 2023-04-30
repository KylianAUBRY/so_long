/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_temp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 02:29:50 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/30 10:03:12 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cherch_joueur(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->nb_ligne)
	{
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->x = x + 1;
				game->y = y + 1;
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

int	remplace_space(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	if (game->map_temp[y + 1][x] != '1' && game->map_temp[y + 1][x] != '9')
	{
		i++;
		game->map_temp[y + 1][x] = '9';
	}
	if (game->map_temp[y - 1][x] != '1' && game->map_temp[y - 1][x] != '9')
	{
		i++;
		game->map_temp[y - 1][x] = '9';
	}
	if (game->map_temp[y][x + 1] != '1' && game->map_temp[y][x + 1] != '9')
	{
		i++;
		game->map_temp[y][x + 1] = '9';
	}
	if (game->map_temp[y][x - 1] != '1' && game->map_temp[y][x - 1] != '9')
	{
		i++;
		game->map_temp[y][x - 1] = '9';
	}
	return (i);
}

int	ft_adieux_temp(t_game *game)
{
	int	y;

	y = 0;
	while (y < game->nb_ligne)
	{
		free(game->map_temp[y]);
		y++;
	}
	free(game->map_temp);
	return (0);
}

int	verif_map_temp(t_game *game)
{
	int	x;
	int	y;

	x = 1;
	y = 1;
	while (y < game->nb_ligne - 1)
	{
		if (game->map_temp[y][x] == 'C' || game->map_temp[y][x] == 'E'
			|| game->map_temp[y][x] == 'P')
		{
			ft_putstr("Error\nMap non faisable");
			ft_adieux_temp(game);
			ft_adieux(game);
			return (0);
		}
		x++;
		if (x >= game->size_x - 1)
		{
			y++;
			x = 1;
		}
	}
	ft_adieux_temp(game);
	return (1);
}

int	map_is_good(t_game *game)
{
	int	x;
	int	y;

	game->map_temp[game->y - 1][game->x - 1] = '9';
	x = 1;
	y = 1;
	while (y < game->nb_ligne - 1)
	{
		if (game->map_temp[y][x] == '9')
		{
			if (remplace_space(game, x, y) != 0)
			{
				x = 0;
				y = 1;
			}
		}
		x++;
		if (x >= game->size_x - 1)
		{
			y++;
			x = 1;
		}
	}
	return (verif_map_temp(game));
}
