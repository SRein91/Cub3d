/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:22:04 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/21 21:19:37 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	is_rgb(char *rgb)
{
	int	i;

	i = ft_atoi(rgb);
	if (i < 0 || i > 255)
		return (FAILED);
	return (SUCCESS);
}

static void	convert_rgb(t_data *data, char **rgb, char c)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	if (c == 'C')
		data->ceiling_color = (r << 16 | g << 8 | b);
	if (c == 'F')
		data->floor_color = (r << 16 | g << 8 | b);
}

int	check_color(t_data *data, char **rgb, char c)
{
	size_t	i;
	int		j;

	j = 0;
	if (ft_arraylen(rgb) != 3 || rgb[2][0] == '\n')
		return (FAILED);
	while (rgb[j])
	{
		i = 0;
		while (rgb[j][i])
		{
			if (!ft_isdigit(rgb[j][i]))
				return (FAILED);
			i++;
		}
		if (ft_strlen(rgb[j]) > 3 || is_rgb(rgb[j]))
			return (FAILED);
		j++;
	}
	convert_rgb(data, rgb, c);
	return (SUCCESS);
}

void	save_colors(t_data *data, t_check *check, char *str, char c)
{
	char	**temp_color;
	char	**temp_rgb;
	int		i;

	i = -1;
	check->identifiers++;
	if (str[ft_strlen(str) - 1] == '\n')
		str = ft_strtrim(str, "\n");
	temp_color = ft_split(str, ' ');
	free(str);
	if (temp_color == NULL)
		error_free2("Color input couldn't be splitted correctly.", temp_color);
	if (ft_arraylen(temp_color) != 2)
		error_free2("Wrong format for color input.", temp_color);
	temp_rgb = ft_split(temp_color[1], ',');
	ft_free_array(temp_color);
	if (temp_rgb == NULL)
		error_free2("Color input couldn't be splitted correctly.", temp_rgb);
	if (check_color(data, temp_rgb, c) == FAILED)
		error_free2("Wrong format for color input.", temp_rgb);
	ft_free_array(temp_rgb);
	check->control++;
	check->str = get_next_line(check->fd);
	return ;
}
