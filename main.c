/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:15:04 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/30 09:01:53 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	init_affi(t_game *game)
{
	int	h;
	int	w;

	if (game->annimation_degat <= 0)
		game->annimation_degat = 0;
	game->annimation_degat--;
	game->i_img = (game->i_img + 1) % game->nb_max_img;
	game->i_img_enemy = (game->i_img_enemy + 1) % game->nb_max_img_enemy;
	game->img = mlx_xpm_file_to_image(game->mlx, game->image[game->i_img], &w,
			&h);
	game->img_enemy = mlx_xpm_file_to_image(game->mlx,
			game->image_enemy[game->i_img_enemy], &w, &h);
	game->degat = mlx_xpm_file_to_image(game->mlx,
			game->image_degat[game->i_img], &w, &h);
	game->img_health = mlx_xpm_file_to_image(game->mlx,
			game->image_health, &w, &h);
}

int	affi_poulet(t_game *game)
{
	char	*nb_steps_char;

	init_affi(game);
	ft_draw_map(game);
	if (game->annimation_degat <= 0)
		mlx_put_image_to_window(game->mlx, game->win, game->img, game->x,
			game->y);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->degat, game->x,
			game->y);
	mlx_put_image_to_window(game->mlx, game->win, game->img_health, 0, 0);
	free(game->img);
	free(game->img_enemy);
	free(game->degat);
	free(game->img_health);
	mlx_string_put(game->mlx, game->win, 25, 30, 0xFF0000, "Nombre de pas :");
	nb_steps_char = ft_itoa(game->nb_steps);
	mlx_string_put(game->mlx, game->win, 120, 32, 0xFF0000, nb_steps_char);
	free (nb_steps_char);
	mlx_do_sync(game->mlx);
	usleep(100000);
	return (0);
}

void	ini_img2(t_game *game)
{
	game->image_degat = malloc(sizeof(char *) * 6);
	game->image_degat[0] = ft_strdup("./asset/CapyDR1.xpm");
	game->image_degat[1] = ft_strdup("./asset/CapyDR2.xpm");
	game->image_degat[2] = ft_strdup("./asset/CapyDR3.xpm");
	game->image_degat[3] = ft_strdup("./asset/CapyDR4.xpm");
	game->image_degat[4] = ft_strdup("./asset/CapyDR5.xpm");
	game->image_health = ft_strdup("./asset/health3.xpm");
}

void	int_img(t_game *game)
{
	game->piece = 0;
	game->annimation_degat = 0;
	game->vie = 4;
	game->i_img = 0;
	game->nb_max_img = 5;
	game->image = malloc(sizeof(char *) * 6);
	game->image[0] = ft_strdup("./asset/CapyWR1.xpm");
	game->image[1] = ft_strdup("./asset/CapyWR2.xpm");
	game->image[2] = ft_strdup("./asset/CapyWR3.xpm");
	game->image[3] = ft_strdup("./asset/CapyWR4.xpm");
	game->image[4] = ft_strdup("./asset/CapyWR5.xpm");
	game->i_img_enemy = 0;
	game->nb_max_img_enemy = 6;
	game->image_enemy = malloc(sizeof(char *) * 7);
	game->image_enemy[0] = ft_strdup("./asset/misticC.xpm");
	game->image_enemy[1] = ft_strdup("./asset/misticC.xpm");
	game->image_enemy[2] = ft_strdup("./asset/misticC.xpm");
	game->image_enemy[3] = ft_strdup("./asset/misticC.xpm");
	game->image_enemy[4] = ft_strdup("./asset/misticC.xpm");
	game->image_enemy[5] = ft_strdup("./asset/misticC.xpm");
	ini_img2(game);
	ft_file(game);
	mlx_loop_hook(game->mlx, affi_poulet, game);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	if (!game)
		return (0);
	if (argc != 2)
	{
		free(game);
		return (ft_putstr_zero("Error\nNombre d'argument diferent de 2\n"));
	}
	if (ft_init_map(argv[1], game, 1) == 1)
	{
		game->nb_steps = 0;
		game->mlx = mlx_init();
		game->win = mlx_new_window(game->mlx, 1920, 1080,
				"Le meilleurs des jeux");
		int_img(game);
		mlx_key_hook(game->win, key_hook, game);
		mlx_hook(game->win, 17, 1L << 17, ft_free, game);
		mlx_loop(game->mlx);
	}
	else
		free(game);
	return (0);
}
