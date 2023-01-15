/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:10:50 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/21 17:38:34 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

void	error(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}

void	error_free(char *msg, char *str)
{
	free(str);
	error(msg);
}

void	error_free2(char *msg, char **str)
{
	ft_free_array(str);
	error(msg);
}

void	ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

void	error_free3(char *msg, t_data *data)
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
	error(msg);
}
