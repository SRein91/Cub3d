/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 17:30:45 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/21 21:22:11 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_image(data->mlx_ptr, data->img[0].img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	while (i < 4)
	{
		free(data->texture[i]);
		i++;
	}
	free(data->texture);
	exit(0);
}

void	error_free4(char *msg, t_data *data)
{
	if (data->map.no != NULL)
		(free(&data->map.no));
	if (data->map.so != NULL)
		(free(&data->map.so));
	if (data->map.we != NULL)
		(free(&data->map.we));
	if (data->map.ea != NULL)
		(free(&data->map.ea));
	if (data->map.floor_color != NULL)
		(free(&data->map.floor_color));
	if (data->map.ceiling_color != NULL)
		(free(&data->map.ceiling_color));
	ft_free_array(data->map.map_array);
	error(msg);
}
