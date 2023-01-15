/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:13:54 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/21 21:18:12 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	check_map_helper(t_check *check, t_data *data, int i, int j)
{
	char	**map;

	map = data->map.map_array;
	if (map[j][i] != '1' && map[j][i] != '0'
	&& map[j][i] != '\n' && map[j][i] != ' ')
	{
		check->player++;
		if ((j == 0) || (i == 0) || (i == check->max_i) || (j == check->max_j))
			error("Invalid player position.");
		if (i != 0 && i != check->max_i && j != 0 && j != check->max_j)
		{
			if ((map[j][i - 1] == ' ') || (map[j][i + 1] == ' ')
			|| (map[j - 1][i] == ' ') || (map[j + 1][i] == ' '))
				error("Invalid player position.");
		}
		data->map.player = map[j][i];
		map[j][i] = '0';
		data->posy = i + 0.5;
		data->posx = j + 0.5;
	}
}

static void	check_map_helper_2(t_check *check, t_data *data, int i, int j)
{
	char	**map;

	map = data->map.map_array;
	if (map[j][i] != '1' && map[j][i] != '0'
	&& map[j][i] != '\n')
	{
		if (map[j][i] == ' ')
		{
			if (i != 0 && i != check->max_i && j != 0 && j != check->max_j)
			{
				if ((map[j][i - 1] == '0') || (map[j][i + 1] == '0')
				|| (map[j - 1][i] == '0') || (map[j + 1][i] == '0'))
					error("Invalid Map.");
			}
		}
	}
}

static void	norm_helper(char **map, int j, int i)
{
	if (map[j][i - 1] == '0')
		return ;
	if ((map[j][i + 1] == '0')
	|| (map[j - 1][i] == '0') || (map[j + 1][i] == '0'))
		error("Invalid Map.");
}

static void	check_map_helper_3(t_data *data, int i, int j)
{
	char	**map;

	map = data->map.map_array;
	if (i <= data->map.len[j])
	{
		if (map[j][i] == ' ')
		{
			if (j == 0)
			{
				if ((map[j][i - 1] == '0') || (map[j][i + 1] == '0')
				|| (map[j + 1][i] == '0'))
					error("Invalid Map.");
			}
			else if (j >= (data->map.map_row - 1))
			{
				if ((map[j][i - 1] == '0') || (map[j][i + 1] == '0')
				|| (map[j - 1][i] == '0'))
					error("Invalid Map.");
			}
			else
				norm_helper(map, j, i);
		}
	}
}

void	check_map(t_data *data, t_check *check)
{
	int		i;
	int		j;
	char	**map;

	j = 0;
	map = data->map.map_array;
	check->player = 0;
	check->max_i = data->map.line_length - 1;
	check->max_j = ft_arraylen(data->map.map_array) - 1;
	while (map[j])
	{
		i = 0;
		while (map[j][i])
		{
			check_map_helper(check, data, i, j);
			check_map_helper_2(check, data, i, j);
			check_map_helper_3(data, i, j);
			i++;
		}
		j++;
	}
	if (check->player != 1)
		error("One Player position allowed.");
	check_borders(data, check);
}
