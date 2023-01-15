/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 00:32:38 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/20 20:14:44 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	mouse_move_helper_1(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dirx;
	oldplanex = data->planex;
	data->dirx = data->dirx * cos(-(data->rot_speed / 1.5))
		- data->diry * sin(-(data->rot_speed / 1.5));
	data->diry = olddirx * sin(-(data->rot_speed / 1.5))
		+ data->diry * cos(-(data->rot_speed / 1.5));
	data->planex = data->planex * cos(-(data->rot_speed / 1.5))
		- data->planey * sin(-(data->rot_speed / 1.5));
	data->planey = oldplanex * sin(-(data->rot_speed / 1.5))
		+ data->planey * cos(-(data->rot_speed / 1.5));
}

void	mouse_move_helper_2(t_data *data)
{
	double	olddirx;
	double	oldplanex;

	olddirx = data->dirx;
	oldplanex = data->planex;
	data->dirx = data->dirx * cos(data->rot_speed / 1.5)
		- data->diry * sin(data->rot_speed / 1.5);
	data->diry = olddirx * sin(data->rot_speed / 1.5)
		+ data->diry * cos(data->rot_speed / 1.5);
	data->planex = data->planex * cos(data->rot_speed / 1.5)
		- data->planey * sin(data->rot_speed / 1.5);
	data->planey = oldplanex * sin(data->rot_speed / 1.5)
		+ data->planey * cos(data->rot_speed / 1.5);
}

void	mouse_move(t_data *data)
{
	mlx_mouse_get_pos(data->win_ptr, &data->mouse_x, &data->mouse_y);
	if (data->mouse_x > S_WIDTH / 2)
		mouse_move_helper_1(data);
	else if (data->mouse_x < S_WIDTH / 2)
		mouse_move_helper_2(data);
	mlx_mouse_move(data->win_ptr, S_WIDTH / 2, S_HEIGHT / 2);
}
