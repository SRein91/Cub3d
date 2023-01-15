/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 17:42:38 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/21 17:35:51 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static char	*copy_map(char *str, t_data *data, int len)
{
	char	*string;
	int		i;
	int		start;

	i = 0;
	if ((len + 1) == data->map.line_length)
	{
		string = ft_strdup(str);
		return (string);
	}
	start = len;
	string = (char *)ft_calloc((data->map.line_length), sizeof(char));
	if (!string)
		return (0);
	string = (char *)ft_memcpy(string, str, (len + 1));
	while (start < (data->map.line_length - 2))
	{
		string[start] = ' ';
		start++;
	}
	string[start] = '\n';
	return (string);
}

static void	fill_map_helper(t_data *data, t_check *check, int i, int j)
{
	data->map.len[i] = (int)ft_strlen(check->str) - 1;
	data->map.map_array[j] = copy_map(check->str, data, data->map.len[i]);
	if (data->map.map_array[j] == NULL)
		error_free3("malloc error", data);
	gnl(&check->str, check->fd, true, check);
}

static void	malloc_map_array(t_data *data)
{
	data->map.map_array = ft_calloc(data->map.map_row + 1, sizeof(char *));
	if (data->map.map_array == NULL)
		error_free3("malloc error", data);
	data->map.len = malloc(sizeof(int) * (data->map.map_row));
	if (data->map.len == NULL)
		error_free4("malloc error", data);
}

void	helper(t_data *data, char *input, t_check *check)
{
	check->fd = open(input, O_RDONLY);
	gnl(&check->str, check->fd, true, check);
	malloc_map_array(data);
}

void	fill_map(t_data *data, char *input, t_check *check)
{
	int	i;
	int	j;

	i = 0;
	helper(data, input, check);
	while (check->str)
	{
		while (i < check->control)
		{
			gnl(&check->str, check->fd, true, check);
			i++;
		}
		i = 0;
		j = 0;
		while (i < data->map.map_row)
		{
			fill_map_helper(data, check, i, j);
			i++;
			j++;
		}
		data->map.map_array[j] = NULL;
		break ;
	}
	close(check->fd);
}
