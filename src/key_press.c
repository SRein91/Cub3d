/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 19:21:13 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/20 19:35:12 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static void	move_back_no_wall(t_data *data)
{
	if (data->down)
	{
		if (data->map.map_array[(int)(data->posx - data->dirx
				* (data->move_speed * 2))][(int)(data->posy)] != '1')
			data->posx -= data->dirx * data->move_speed;
		if (data->map.map_array[(int)(data->posx)][(int)(data->posy - data->diry
				* (data->move_speed * 2))] != '1')
			data->posy -= data->diry * data->move_speed;
	}
}

static void	strafe_left_and_right(t_data *data)
{
	if (data->sleft)
	{
		if (data->map.map_array[(int)(data->posx - data->diry
				* (data->move_speed * 2))][(int)(data->posy)] != '1' )
			data->posx -= data->diry * data->move_speed;
		if (data->map.map_array[(int)(data->posx)][(int)(data->posy + data->dirx
				* (data->move_speed * 2))] != '1')
			data->posy += data->dirx * data->move_speed ;
	}
	if (data->sright)
	{
		if (data->map.map_array[(int)(data->posx + data->diry
				* (data->move_speed * 2))][(int)(data->posy)] != '1')
			data->posx += data->diry * data->move_speed;
		if (data->map.map_array[(int)(data->posx)][(int)(data->posy - data->dirx
				* (data->move_speed * 2))] != '1')
			data->posy -= data->dirx * data->move_speed;
	}
}

static void	rotate_left(t_data *data, double olddirx, double oldplanex)
{
	if (data->rleft)
	{
		data->dirx = data->dirx * cos(data->rot_speed)
			- data->diry * sin(data->rot_speed);
		data->diry = olddirx * sin(data->rot_speed)
			+ data->diry * cos(data->rot_speed);
		data->planex = data->planex * cos(data->rot_speed)
			- data->planey * sin(data->rot_speed);
		data->planey = oldplanex * sin(data->rot_speed)
			+ data->planey * cos(data->rot_speed);
	}
}

static void	rotate_left_and_right(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dirx;
	oldplanex = data->planex;
	if (data->rright)
	{
		data->dirx = data->dirx * cos(-data->rot_speed)
			- data->diry * sin(-data->rot_speed);
		data->diry = olddirx * sin(-data->rot_speed)
			+ data->diry * cos(-data->rot_speed);
		data->planex = data->planex * cos(-data->rot_speed)
			- data->planey * sin(-data->rot_speed);
		data->planey = oldplanex * sin(-data->rot_speed)
			+ data->planey * cos(-data->rot_speed);
	}
	rotate_left(data, olddirx, oldplanex);
}

int	key_press(t_data *data)
{
	if (data->up == true)
	{
		if (data->map.map_array[(int)(data->posx + data->dirx
				* (data->move_speed * 2))][(int)(data->posy)] != '1')
			data->posx += data->dirx * data->move_speed;
		if (data->map.map_array[(int)(data->posx)][(int)(data->posy + data->diry
				* (data->move_speed * 2))] != '1')
			data->posy += data->diry * data->move_speed;
	}
	move_back_no_wall(data);
	strafe_left_and_right(data);
	rotate_left_and_right(data);
	return (0);
}
