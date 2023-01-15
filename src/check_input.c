/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 19:03:13 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/21 21:19:49 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

static int	check_ext(char *filename)
{
	char	*ending;

	ending = ft_strdup(&filename[ft_strlen(filename) - 4]);
	if (ft_strncmp(ending, ".cub", 3))
	{
		free(ending);
		return (SUCCESS);
	}
	free(ending);
	return (FAILED);
}

static void	check_all_identifiers(int i)
{
	char	*str;
	int		counter;
	t_check	*check;

	check = NULL;
	str = get_next_line(i);
	counter = 0;
	while (str)
	{
		if (!ft_strncmp((str), "NO ", 3)
			|| !ft_strncmp((str), "SO ", 3)
			|| !ft_strncmp((str), "WE ", 3)
			|| !ft_strncmp((str), "EA ", 3)
			|| !ft_strncmp((str), "F ", 2)
			|| !ft_strncmp((str), "C ", 2))
			counter++;
		gnl(&str, i, true, check);
	}
	if (counter != 6)
		error("Invalid Input");
}

int	check_input(int argc, char **argv)
{
	int	input;

	if (argc == 1)
		error("no map specified.");
	if (argc > 2)
		error("too many arguments.");
	if (!(check_ext(argv[1])))
		error("map file extension should be .cub");
	input = open(argv[1], O_RDONLY);
	if (input < 0)
		error("Invalid .cub file");
	check_all_identifiers(input);
	close(input);
	return (SUCCESS);
}
