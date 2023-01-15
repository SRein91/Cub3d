/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 20:34:39 by dtamulis          #+#    #+#             */
/*   Updated: 2022/06/21 21:27:05 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	init_utils(t_data *data, t_ray *ray, int x)
{
	ray->camerax = 2 * x / (double)S_WIDTH - 1;
	ray->raydirx = data->dirx + data->planex * ray->camerax;
	ray->raydiry = data->diry + data->planey * ray->camerax;
	ray->mapx = (int)data->posx;
	ray->mapy = (int)data->posy;
	ray->deltadistx = fabs(1 / ray->raydirx);
	ray->deltadisty = fabs(1 / ray->raydiry);
	ray->hit = 0;
	ray->texnum = 0;
	ray->lineheight = (int)(S_HEIGHT / ray->perpwalldist);
	ray->drawstart = -ray->lineheight / 2 + S_HEIGHT / 2;
	ray->drawend = ray->lineheight / 2 + S_HEIGHT / 2;
}

static void	perform_dda_helper(t_data *data, t_ray *ray)
{
	ray->sidedisty += ray->deltadisty;
	ray->mapy += ray->stepy;
	ray->side = 1;
	if (data->map.map_array[ray->mapx][ray->mapy] == '1')
	{
		ray->hit = 1;
		if (ray->mapy > data->posy)
			ray->texnum = 1;
		else
			ray->texnum = 3;
	}
}

static void	perform_dda(t_data *data, t_ray *ray)
{
	if (ray->sidedistx < ray->sidedisty)
	{
		ray->sidedistx += ray->deltadistx;
		ray->mapx += ray->stepx;
		ray->side = 0;
		if (data->map.map_array[ray->mapx][ray->mapy] == '1')
		{
			ray->hit = 1;
			if (ray->mapx > data->posx)
				ray->texnum = 2;
			else
				ray->texnum = 0;
		}
	}
	else
		perform_dda_helper(data, ray);
}

int	main_loop(t_data *data)
{
	t_ray	ray;
	int		x;

	if (data->tflag == true)
	{
		mlx_destroy_image(data->mlx_ptr, data->img[0].img);
		data->img[0].img = mlx_new_image(data->mlx_ptr, S_WIDTH, S_HEIGHT);
	data->img[0].addr = (int *)mlx_get_data_addr(data->img[0].img,
				&data->img[0].bpp, &data->img[0].sl, &data->img[0].endian);
	}
	ceiling_floor_color(data);
	x = 0;
	while (x++ < S_WIDTH)
	{
		init_utils(data, &ray, x);
		calculate_step(data, &ray);
		while (ray.hit == 0)
			perform_dda(data, &ray);
		calculate_scene(data, &ray, x);
	}
	mini_map(data);
	draw_scene(data);
	key_press(data);
	mouse_move(data);
	return (0);
}
