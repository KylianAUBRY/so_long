/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyaubry <kyaubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 00:11:40 by kyaubry           #+#    #+#             */
/*   Updated: 2023/04/30 09:02:59 by kyaubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_nb(int n)
{
	int	t;

	t = 0;
	if (n <= 0)
		t++;
	while (n != 0)
	{
		n /= 10;
		t++;
	}
	return (t);
}

char	*ft_itoa(int n)
{
	char	*dest;
	int		i;
	long	nb;

	i = count_nb(n) - 1;
	nb = n;
	dest = malloc(sizeof(char) * (count_nb(n) + 1));
	if (!dest)
		return (NULL);
	if (nb < 0)
	{
		dest[0] = '-';
		nb = -nb;
	}
	if (nb == 0)
		dest[0] = '0';
	while (nb != 0)
	{
		dest[i] = (nb % 10) + '0';
		i--;
		nb /= 10;
	}
	dest[count_nb(n)] = '\0';
	return (dest);
}

int	ft_putstr(char *dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	return (i);
}

int	ft_putstr_zero(char *dest)
{
	int	i;

	i = 0;
	while (dest[i])
	{
		write(1, &dest[i], 1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		i;

	i = ft_strlen(s);
	dest = malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
