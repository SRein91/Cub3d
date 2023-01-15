/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 18:08:23 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/21 16:45:27 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	make_frame(t_data *data, t_mini *mini)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 100)
	{
		j = 0;
		while (j < 100)
		{
			data->buffer[mini->midh - 50 + i][mini->midw - 50 + j]
				= (data->ceiling_color >> 1) & 8355711;
			j++;
		}
		i++;
	}
}

static void	norm_helper(t_data *data, int x, int y, t_mini *mini)
{
	if (!(((int)data->posx - x) < 0)
		&& !(((int)data->posy + y) >= data->map.line_length))
	{
		if (data->map.map_array[((int)data->posx) - x][((int)data->posy) + y] &&
			data->map.map_array[((int)data->posx) - x]
				[((int)data->posy) + y] == '1')
			data->buffer[mini->midh - x][mini->midw + y] = (mini->white >> 1);
	}
	if (!(((int)data->posx - x) < 0) && !(((int)data->posy - y) < 0))
	{
		if (data->map.map_array[((int)data->posx) - x][((int)data->posy) - y] &&
		data->map.map_array[((int)data->posx) - x]
			[((int)data->posy) - y] == '1')
		data->buffer[mini->midh - x][mini->midw - y] = (mini->white >> 1);
	}
}

static void	make_minimap(t_data *data, int x, int y, t_mini *mini)
{
	if (!(((int)data->posx + x) >= data->map.map_row)
		&& !(((int)data->posy + y) >= data->map.line_length))
	{
		if (data->map.map_array[((int)data->posx) + x][((int)data->posy) + y]
			&& data->map.map_array[((int)data->posx) + x]
				[((int)data->posy) + y] == '1')
			data->buffer[mini->midh + x][mini->midw + y] = (mini->white >> 1);
	}
	if (!(((int)data->posx + x) >= data->map.map_row)
		&& !(((int)data->posy - y) < 0))
	{
		if (data->map.map_array[((int)data->posx) + x][((int)data->posy) - y]
			&& data->map.map_array[((int)data->posx) + x]
				[((int)data->posy) - y] == '1')
			data->buffer[mini->midh + x][mini->midw - y] = (mini->white >> 1);
	}
	norm_helper(data, x, y, mini);
}

static void	init_minimap(t_mini *mini)
{
	mini->midh = ((S_HEIGHT / 3) + (S_HEIGHT / 18)) / 2;
	mini->midw = ((S_WIDTH / 3) + (S_WIDTH / 18)) / 2;
	mini->white = 0xFFFFFF;
	mini->red = 0xd83a12;
	mini->k = mini->midh - 2;
	mini->l = mini->midw - 2;
	mini->x = 0;
	mini->y = 0;
	mini->i = 0;
	mini->j = 0;
}

void	mini_map(t_data *data)
{
	t_mini	mini;

	init_minimap(&mini);
	make_frame(data, &mini);
	while (mini.x < 50)
	{
		mini.y = 0;
		while (mini.y < 50)
		{
			make_minimap(data, mini.x, mini.y, &mini);
			mini.y++;
		}
		mini.x++;
	}
	while (mini.i < 5)
	{
		mini.j = 0;
		while (mini.j < 5)
		{
			data->buffer[mini.k + mini.i][mini.l + mini.j] = mini.red;
			mini.j++;
		}
		mini.i++;
	}
}
