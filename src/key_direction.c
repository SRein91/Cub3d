/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_direction.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 17:29:48 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/20 17:42:52 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	key_dir_on(int key, t_data *data)
{
	if (key == KEY_W)
		data->up = true;
	if (key == KEY_S)
		data->down = true;
	if (key == KEY_A)
		data->sleft = true;
	if (key == KEY_D)
		data->sright = true;
	if (key == KEY_RIGHT)
		data->rright = true;
	if (key == KEY_LEFT)
		data->rleft = true;
	if (key == KEY_ESC)
		ft_exit(data);
	return (0);
}

int	key_dir_off(int key, t_data *data)
{
	if (key == KEY_W)
		data->up = false;
	if (key == KEY_S)
		data->down = false;
	if (key == KEY_A)
		data->sleft = false;
	if (key == KEY_D)
		data->sright = false;
	if (key == KEY_RIGHT)
		data->rright = false;
	if (key == KEY_LEFT)
		data->rleft = false;
	if (key == KEY_ESC)
		ft_exit(data);
	return (0);
}
