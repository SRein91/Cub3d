/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_textures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 16:49:33 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/20 17:26:12 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	load_img(t_data *data, int *texture, char *tex, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(data->mlx_ptr, tex,
			&img->width, &img->height);
	if (img->img == NULL)
		error_free3("Could not open texture file", data);
	img->addr = (int *)mlx_get_data_addr(img->img,
			&img->bpp, &img->sl, &img->endian);
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			texture[img->width * y + x] = img->addr[img->width * y + x];
			x++;
		}
		y++;
	}
	mlx_destroy_image(data->mlx_ptr, img->img);
}

static int	malloc_textures(t_data *data, int i, int j)
{
	data->texture = (int **)malloc(sizeof(int *) * 4);
	if (!(data->texture))
		return (FAILED);
	while (i < 4)
	{
		data->texture[i] = (int *)malloc(sizeof(int)
				* (TEX_HEIGHT * TEX_WIDTH + 1));
		if (!(data->texture[i]))
			return (FAILED);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		while (j < TEX_HEIGHT * TEX_WIDTH)
		{
			data->texture[i][j] = 0;
			j++;
		}
		i++;
	}
	return (0);
}

static int	get_textures(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if ((malloc_textures(data, i, j)) == FAILED)
		return (FAILED);
	while (i < S_HEIGHT)
	{
		j = 0;
		while (j < S_WIDTH)
		{
			data->buffer[i][j] = 0;
			j++;
		}
		i++;
	}
	load_img(data, data->texture[0], data->map.no, &data->img[1]);
	load_img(data, data->texture[1], data->map.ea, &data->img[2]);
	load_img(data, data->texture[2], data->map.so, &data->img[3]);
	load_img(data, data->texture[3], data->map.we, &data->img[4]);
	return (0);
}

static void	helper(t_data *data)
{
	if (data->map.player == 'E')
	{
		data->dirx = 0;
		data->diry = 1;
		data->planex = 0.66;
		data->planey = 0;
	}
	if (data->map.player == 'W')
	{
		data->dirx = 0;
		data->diry = -1;
		data->planex = -0.66;
		data->planey = 0;
	}
}

void	init_player_map(t_data *data)
{
	helper(data);
	if (data->map.player == 'N')
	{
		data->dirx = -1;
		data->diry = 0;
		data->planex = 0;
		data->planey = 0.66;
	}
	if (data->map.player == 'S')
	{
		data->dirx = 1;
		data->diry = 0;
		data->planex = 0;
		data->planey = -0.66;
	}
	data->bits_per_pixel = 0;
	data->line_length = 0;
	data->addr = NULL;
	data->move_speed = 0.05;
	data->rot_speed = 0.05;
	data->time = 0;
	data->old_time = 0;
	get_textures(data);
}
