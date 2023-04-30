/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 19:59:44 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/30 09:02:30 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_line(char *dest)
{
	int	i;

	i = 0;
	while (dest[i] && dest[i] != '\n')
		i++;
	return (i);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_freejoin(char *s1, char const *s2)
{
	char	*dest;
	int		t;
	int		i;

	t = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(sizeof(char) * t + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	free(s1);
	t = 0;
	while (s2[t] != '\0')
	{
		dest[i + t] = s2[t];
		t++;
	}
	dest[i + t] = '\0';
	return (dest);
}

void	ft_free2(t_game *game)
{
	int		i;

	i = -1;
	while (++i < game->nb_ligne)
		free(game->map[i]);
	free(game->map);
	free(game->image_health);
	free(game->top);
	free(game->top_right);
	free(game->top_left);
	free(game->down);
	free(game->down_right);
	free(game->down_left);
	free(game->right);
	free(game->left);
	free(game->back);
	free(game->barrier);
	free(game->chest);
	free(game->dors_open);
	free(game->dors_close);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->win);
	free(game->mlx);
}

int	ft_free(t_game *game)
{
	free(game->image_degat[0]);
	free(game->image_degat[1]);
	free(game->image_degat[2]);
	free(game->image_degat[3]);
	free(game->image_degat[4]);
	free(game->image_degat);
	free(game->image_enemy[0]);
	free(game->image_enemy[1]);
	free(game->image_enemy[2]);
	free(game->image_enemy[3]);
	free(game->image_enemy[4]);
	free(game->image_enemy[5]);
	free(game->image_enemy);
	free(game->image[0]);
	free(game->image[1]);
	free(game->image[2]);
	free(game->image[3]);
	free(game->image[4]);
	free(game->image);
	ft_free2(game);
	free(game);
	exit(0);
	return (0);
}
