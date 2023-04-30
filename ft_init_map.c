/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 07:52:00 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/30 07:37:46 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_to_tab(t_game *game, char *dest)
{
	int	i;
	int	j;
	int	indice;

	game->map = malloc(sizeof(char *) * game->nb_ligne);
	if (!game->map)
		return (ft_putstr_zero("Error\nErreur malloc\n"));
	i = -1;
	indice = 0;
	while (++i < game->nb_ligne)
	{
		j = 0;
		game->map[i] = malloc(sizeof(char) * (game->size_x + 1));
		if (!game->map[i])
			return (ft_putstr_zero("Error\nErreur malloc\n"));
		while (dest[indice] && dest[indice] != '\n')
		{
			game->map[i][j] = dest[indice];
			j++;
			indice++;
		}
		game->map[i][j] = '\0';
		indice++;
	}
	return (1);
}

int	map_to_tab_temp(t_game *game, char *dest)
{
	int	i;
	int	j;
	int	indice;

	game->map_temp = malloc(sizeof(char *) * game->nb_ligne);
	if (!game->map_temp)
		return (ft_putstr_zero("Error\nErreur malloc\n"));
	i = -1;
	indice = 0;
	while (++i < game->nb_ligne)
	{
		j = 0;
		game->map_temp[i] = malloc(sizeof(char) * (game->size_x + 1));
		if (!game->map_temp[i])
			return (ft_putstr_zero("Error\nErreur malloc\n"));
		while (dest[indice] && dest[indice] != '\n')
		{
			game->map_temp[i][j] = dest[indice];
			j++;
			indice++;
		}
		game->map_temp[i][j] = '\0';
		indice++;
	}
	return (1);
}

int	ft_adieux(t_game *game)
{
	int	i;

	i = game->nb_ligne - 1;
	while (i >= 0)
	{
		free(game->map[i]);
		i--;
	}
	free(game->map);
	return (0);
}

int	ft_check_file1(char *argv, char *dest)
{
	int		i;
	int		temp;
	int		j;
	char	*ber;

	ber = ".ber";
	i = 0;
	j = 0;
	while (argv[i])
	{
		temp = i;
		while (argv[i] && ber[j] && argv[i] == ber[j])
		{
			i++;
			j ++;
		}
		if (ber[j] == '\0' && argv[i] == '\0')
			break ;
		j = 0;
		i = temp + 1;
	}
	if (ber[j] == '\0' && argv[i] == '\0')
		return (1);
	free (dest);
	return (ft_putstr_zero("Error\nLe fichier de la map doit finir en .ber\n"));
}

int	ft_init_map(char *argv, t_game *game, int read_file)
{
	int		map_file;
	char	buff[BUFFER_SIZE + 1];
	char	*dest;

	dest = malloc(sizeof(char) * 1);
	if (!dest)
		return (ft_putstr_zero("Error\nErreur malloc\n"));
	dest[0] = '\0';
	map_file = open(argv, O_RDONLY);
	if (map_file < 0)
		return (erreur_map(dest));
	if (ft_check_file1(argv, dest) == 0 || map_file < 0)
		return (0);
	while (read_file > 0)
	{
		read_file = read(map_file, buff, BUFFER_SIZE);
		if (read_file <= 0)
			break ;
		buff[read_file] = '\0';
		dest = ft_freejoin(dest, buff);
	}
	close (map_file);
	if (verif_map_to_tab(game, dest) != 1)
		return (0);
	return (1);
}
