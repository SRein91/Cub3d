/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 00:39:43 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/20 00:39:59 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	draw_helper(t_data *data)
{
	int	i;
	int	x;
	int	y;

	y = 0;
	while (y < S_HEIGHT)
	{
		x = 0;
		while (x < S_WIDTH)
		{
			data->buffer[y][x] = 0;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->img[0].img, 0, 0);
	i = 0;
	while (data->img[0].addr[i])
		data->img[0].addr[i] = 0;
	data->img[0].addr = NULL;
	data->tflag = true;
}

void	draw_scene(t_data *data)
{
	int	y;
	int	x;

	y = 0;
	while (y < S_HEIGHT)
	{
		x = 0;
		while (x < S_WIDTH)
		{
			data->img[0].addr[y * S_WIDTH + x] = data->buffer[y][x];
			x++;
		}
		y++;
	}
	draw_helper(data);
}
