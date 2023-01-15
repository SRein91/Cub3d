/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 00:36:56 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/20 00:37:46 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	calculate_step(t_data *data, t_ray *ray)
{
	if (ray->raydirx < 0)
	{
		ray->stepx = -1;
		ray->sidedistx = (data->posx - ray->mapx) * ray->deltadistx;
	}
	else
	{
		ray->stepx = 1;
		ray->sidedistx = (ray->mapx + 1.0 - data->posx) * ray->deltadistx;
	}
	if (ray->raydiry < 0)
	{
		ray->stepy = -1;
		ray->sidedisty = (data->posy - ray->mapy) * ray->deltadisty;
	}
	else
	{
		ray->stepy = 1;
		ray->sidedisty = (ray->mapy + 1.0 - data->posy) * ray->deltadisty;
	}
}

static double	calculate_distance(t_data *data, t_ray *ray)
{
	double	wallx;

	if (ray->side == 0)
		ray->perpwalldist = (ray->sidedistx - ray->deltadistx);
	else
		ray->perpwalldist = (ray->sidedisty - ray->deltadisty);
	if (ray->drawstart < 0)
		ray->drawstart = 0;
	if (ray->drawend >= S_HEIGHT)
		ray->drawend = S_HEIGHT - 1;
	if (ray->side == 0)
		wallx = data->posy + ray->perpwalldist * ray->raydiry;
	else
		wallx = data->posx + ray->perpwalldist * ray->raydirx;
	wallx -= floor(wallx);
	return (wallx);
}

void	calculate_scene(t_data *data, t_ray *ray, int x)
{
	double	step;
	double	texpos;
	int		y;
	int		texy;
	int		color;

	ray->texx = (int)(calculate_distance(data, ray) * (double)TEX_WIDTH);
	if (ray->side == 0 && ray->raydirx > 0)
		ray->texx = TEX_WIDTH - ray->texx - 1;
	if (ray->side == 1 && ray->raydiry < 0)
		ray->texx = TEX_WIDTH - ray->texx - 1;
	step = 1.0 * TEX_HEIGHT / ray->lineheight;
	texpos = (ray->drawstart - S_HEIGHT / 2 + ray->lineheight / 2) * step;
	y = ray->drawstart;
	while (y < ray->drawend)
	{
		texy = (int)texpos & (TEX_HEIGHT - 1);
		texpos += step;
		color = data->texture[ray->texnum][TEX_HEIGHT * texy + ray->texx];
		if (ray->side == 1)
			color = (color >> 1) & 8355711;
		data->buffer[y][x] = color;
		y++;
	}
}
