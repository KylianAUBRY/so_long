/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moove.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 01:52:17 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/30 09:00:04 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	erreur_map(char *dest)
{
	free (dest);
	return (ft_putstr_zero("Error\nL'ouverture du fichier a échoué"));
}

void	ft_right(t_game *game)
{
	piece(game, 0, -32);
	game->image_degat[0][13] = 'R';
	game->image_degat[1][13] = 'R';
	game->image_degat[2][13] = 'R';
	game->image_degat[3][13] = 'R';
	game->image_degat[4][13] = 'R';
	game->image[0][13] = 'R';
	game->image[1][13] = 'R';
	game->image[2][13] = 'R';
	game->image[3][13] = 'R';
	game->image[4][13] = 'R';
}

void	ft_left(t_game *game)
{
	piece(game, 0, 32);
	game->image_degat[0][13] = 'L';
	game->image_degat[1][13] = 'L';
	game->image_degat[2][13] = 'L';
	game->image_degat[3][13] = 'L';
	game->image_degat[4][13] = 'L';
	game->image[0][13] = 'L';
	game->image[1][13] = 'L';
	game->image[2][13] = 'L';
	game->image[3][13] = 'L';
	game->image[4][13] = 'L';
}

void	ft_up(t_game *game)
{
	piece(game, -32, 0);
	game->image_degat[0][13] = 'U';
	game->image_degat[1][13] = 'U';
	game->image_degat[2][13] = 'U';
	game->image_degat[3][13] = 'U';
	game->image_degat[4][13] = 'U';
	game->image[0][13] = 'U';
	game->image[1][13] = 'U';
	game->image[2][13] = 'U';
	game->image[3][13] = 'U';
	game->image[4][13] = 'U';
}

void	ft_down(t_game *game)
{
	piece(game, 32, 0);
	game->image_degat[0][13] = 'D';
	game->image_degat[1][13] = 'D';
	game->image_degat[2][13] = 'D';
	game->image_degat[3][13] = 'D';
	game->image_degat[4][13] = 'D';
	game->image[0][13] = 'D';
	game->image[1][13] = 'D';
	game->image[2][13] = 'D';
	game->image[3][13] = 'D';
	game->image[4][13] = 'D';
}
