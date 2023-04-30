/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 22:22:59 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/30 03:45:48 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verif_size(t_game *game, char *dest)
{
	int	i;

	game->nb_ligne = 1;
	i = 0;
	while (dest[i] && dest[i] != '\n')
		i++;
	if (dest[i] == '\0')
		return (ft_putstr_zero("Error\nLa map contien qu'une ligne ou rien\n"));
	game->size_x = i;
	i++;
	while (dest[i])
	{
		if (ft_strlen_line(dest + i) != game->size_x)
			return (ft_putstr_zero("Error\nLigne de taille differente\n"));
		while (dest[i] && dest[i] != '\n')
			i++;
		if (dest[i] == '\n')
			i++;
		game->nb_ligne++;
	}
	if (game->nb_ligne <= 2)
		ft_putstr("Error\nMap non faisable\n");
	return (game->nb_ligne);
}

int	verif_char2(char dest)
{
	if (dest != '\n' && dest != 'C' && dest != 'P' && dest != 'E' && dest != '1'
		&& dest != '0' && dest != '\0' && dest != 'N')
	{
		ft_putstr("Error\nCaractere non autoriser\n");
		return (0);
	}
	return (1);
}

int	verif_char(t_game *game, char *dest)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	j = 0;
	k = 0;
	game->nb_item = 0;
	while (dest[++i])
	{
		if (dest[i] == 'E')
			j++;
		if (dest[i] == 'P')
			k++;
		if (dest[i] == 'C')
			game->nb_item++;
		if (verif_char2(dest[i]) == 0)
			return (0);
	}
	if (k != 1 || j != 1)
		return (ft_putstr("Error\nNombre de sortie ou d'entrer diferent de 1\n"));
	if (game->nb_item <= 0)
		return (ft_putstr("Error\nIl faut au minimum 1 item\n"));
	return (1);
}

int	verif_cote(t_game *game, int i)
{
	while (game->map[0][++i])
	{
		if (game->map[0][i] != '1')
		{
			ft_putstr("Error\nIl manque des murs dans les contourne de map\n");
			return (ft_adieux(game));
		}
	}
	i = -1;
	while (++i < game->nb_ligne - 1)
	{
		if (game->map[i][0] != '1')
		{
			ft_putstr("Error\nIl manque des murs dans les contourne de map\n");
			return (ft_adieux(game));
		}
		if (game->map[i][game->size_x - 1] != '1')
		{
			ft_putstr("Error\nIl manque des murs dans les contourne de map\n");
			return (ft_adieux(game));
		}
	}
	return (1);
}

int	verif_map_to_tab(t_game *game, char *dest)
{
	int	i;

	i = 0;
	if (verif_size(game, dest) <= 2 || verif_char(game, dest) != 1)
	{
		free(dest);
		return (0);
	}
	if (map_to_tab(game, dest) != 1 || map_to_tab_temp(game, dest) != 1)
		return (0);
	free(dest);
	while (game->map[game->nb_ligne - 1][i])
	{
		if (game->map[game->nb_ligne - 1][i] != '1')
		{
			ft_putstr("Error\nIl manque des murs dans les contourne de map\n");
			return (ft_adieux(game));
		}
		i++;
	}
	if (verif_cote(game, -1) != 1)
		return (0);
	ft_cherch_joueur(game);
	return (map_is_good(game));
}
