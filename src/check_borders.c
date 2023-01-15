/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_borders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:15:32 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/21 21:20:33 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	first_and_last_row(int *line_len, int max_j, char **map)
{
	int	i;

	i = 0;
	while (map[0][i] && i < line_len[0])
	{
		if (map[0][i] != '1' && map[0][i] != ' ')
			error("Invalid Map.");
		i++;
	}
	i = 0;
	while (map[max_j][i] && i < line_len[max_j])
	{
		while (map[max_j][i] && map[max_j][i] == ' ')
			i++;
		if (map[max_j][i] != '1' && map[max_j][i] != ' ')
			error("Invalid Map.");
		i++;
	}
}

static void	front_column(char **map)
{
	int	j;

	j = 0;
	while (map[j])
	{
		while (map[j][0] && map[j][0] == ' ')
			j++;
		if (map[j][0] != '1')
			error("Invalid Map.");
		j++;
	}
}

static void	end_column(int *len, char **map)
{
	int	j;
	int	i;
	int	k;

	i = 0;
	j = 0;
	while (map[j])
	{
		k = len[j];
		while (map[j][i] && map[j][k] == '\n')
			i++;
		while (map[j][i] && map[j][k] == ' ')
			i++;
		if (map[j][k - 1] != '1')
			error("Invalid Map.");
		j++;
	}
}

void	check_borders(t_data *data, t_check *check)
{
	first_and_last_row(data->map.len, check->max_j, data->map.map_array);
	front_column(data->map.map_array);
	end_column(data->map.len, data->map.map_array);
}
