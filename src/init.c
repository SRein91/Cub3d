/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 21:15:59 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/21 21:26:07 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	init_map_and_check(t_data *data, t_check *check, char *input)
{
	data->map.line_length = 0;
	data->map.no = NULL;
	data->map.so = NULL;
	data->map.we = NULL;
	data->map.ea = NULL;
	data->map.ceiling_color = NULL;
	data->map.floor_color = NULL;
	data->map.map_row = 0;
	data->tflag = false;
	data->up = false;
	data->down = false;
	data->sleft = false;
	data->sright = false;
	data->rleft = false;
	data->rright = false;
	check->identifiers = 0;
	check->control = 0;
	check->map_started = false;
	check->fd = open(input, O_RDONLY);
	check->str = get_next_line(check->fd);
	if (!check->str)
		error_free("Empty .cub file", check->str);
}

int	init_data(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	data->mlx_ptr = NULL;
	data->win_ptr = NULL;
	data->addr = NULL;
	return (SUCCESS);
}
