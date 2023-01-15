/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 00:41:05 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/20 00:41:31 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	floor_color(t_data *data)
{
	int	i;
	int	j;
	int	floor;

	floor = (int)data->floor_color;
	i = 0;
	while (i < S_WIDTH)
	{
		j = S_HEIGHT / 2;
		while (j < S_HEIGHT)
		{
			data->buffer[j][i] = floor;
			j++;
		}
		i++;
	}
}

void	ceiling_floor_color(t_data *data)
{
	int	i;
	int	j;
	int	ceiling;

	ceiling = (int)data->ceiling_color;
	i = 0;
	while (i < S_WIDTH)
	{
		j = 0;
		while (j < S_HEIGHT)
		{
			data->buffer[j][i] = ceiling;
			j++;
		}
		i++;
	}
	floor_color(data);
}
