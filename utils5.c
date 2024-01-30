/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amatta <amatta@student.42roma.it>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 12:59:38 by amatta            #+#    #+#             */
/*   Updated: 2024/01/30 13:01:24 by amatta           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

char	*trim_whitespace(char *str)
{
	char	*end;

	while (is_space((unsigned char)*str))
		str++;
	if (*str == 0)
		return (str);
	end = str + ft_strlen(str) - 1;
	while ((end > str) && is_space((unsigned char)*end))
		end--;
	end[1] = '\0';
	return (str);
}

void	mlx_hooks(t_game *cube)
{
	mlx_hook(cube->mlx_win, 17, 0, close_window, cube);
	mlx_hook(cube->mlx_win, 6, 1L << 6, handle_mouse, (void *)cube);
	mlx_hook(cube->mlx_win, 2, 1L << 0, key_press, (void *)cube);
	mlx_hook(cube->mlx_win, 3, 1L << 1, key_release, (void *)cube);
}

// check if the file is a .cub file
void	is_cube(t_game *cube, char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len < 5)
	{
		printf("Error\nInvalid file extension\n");
		free(cube);
		exit(1);
	}
	if (ft_strncmp(argv + len - 4, ".cub", 4) != 0)
	{
		printf("Error\nInvalid file extension\n");
		free(cube);
		exit(1);
	}
}
