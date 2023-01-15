/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_identifiers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 18:09:34 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/21 18:49:18 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	check_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			return (1);
		i++;
	}
	return (0);
}

static char	*helper(t_check *check, char *str)
{
	char	**string;
	char	*save;
	int		input;

	save = NULL;
	string = ft_split(str, ' ');
	free(str);
	check->identifiers++;
	if (string == NULL)
		error_free2("Texture input couldn't be splitted correctly", string);
	if (ft_arraylen(string) != 2)
		error_free2("Wrong format for texture input", string);
	if (string[1][ft_strlen(string[1]) - 1] == '\n')
		save = ft_strtrim(string[1], "\n");
	ft_free_array(string);
	input = open(save, O_RDONLY);
	if (input < 0)
		error("Invalid texture file.");
	close(input);
	check->control++;
	check->str = get_next_line(check->fd);
	return (save);
}

static void	norm_helper(t_data *data, t_check *check)
{
	if (!(ft_strncmp((check->str), "EA ", 3)))
	{
		if (data->map.ea != NULL)
			error("Duplicated identifier");
		data->map.ea = helper(check, check->str);
	}
	if (!(ft_strncmp((check->str), "F ", 2)))
	{
		if (data->map.floor_color != NULL)
			error("Duplicated color");
		data->map.floor_color = check->str;
		save_colors(data, check, check->str, 'F');
	}
	if (!(ft_strncmp((check->str), "C ", 2)))
	{
		if (data->map.ceiling_color != NULL)
			error("Duplicated color");
		data->map.ceiling_color = check->str;
		save_colors(data, check, check->str, 'C');
	}
}

void	save_map_info(t_data *data, t_check *check)
{
	if (!(ft_strncmp((check->str), "NO ", 3)))
	{
		if (data->map.no != NULL)
			error("Duplicated identifier");
		data->map.no = helper(check, check->str);
	}
	if (!(ft_strncmp((check->str), "SO ", 3)))
	{
		if (data->map.so != NULL)
			error("Duplicated identifier");
		data->map.so = helper(check, check->str);
	}
	if (!(ft_strncmp((check->str), "WE ", 3)))
	{
		if (data->map.we != NULL)
			error("Duplicated identifier");
		data->map.we = helper(check, check->str);
	}
	norm_helper(data, check);
}

void	get_identifiers(t_data *data, t_check *check)
{
	int	i;

	i = 0;
	if (!ft_strncmp((check->str), "NO ", 3)
		|| !ft_strncmp((check->str), "SO ", 3)
		|| !ft_strncmp((check->str), "WE ", 3)
		|| !ft_strncmp((check->str), "EA ", 3)
		|| !ft_strncmp((check->str), "F ", 2)
		|| !ft_strncmp((check->str), "C ", 2)
		|| check_spaces(check->str))
	{
		if (!ft_strncmp((check->str), "NO ", 3)
			|| !ft_strncmp((check->str), "SO ", 3)
			|| !ft_strncmp((check->str), "WE ", 3)
			|| !ft_strncmp((check->str), "EA ", 3)
			|| !ft_strncmp((check->str), "F ", 2)
			|| !ft_strncmp((check->str), "C ", 2))
			save_map_info(data, check);
		else
			gnl(&check->str, check->fd, false, check);
	}
	else
		error_free3("Invalid input.", data);
}
