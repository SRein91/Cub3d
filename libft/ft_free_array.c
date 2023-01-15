/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/07 20:54:10 by sreinhol          #+#    #+#             */
/*   Updated: 2022/01/29 23:14:40 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//function to free strings
void	ft_free_array(char **input)
{
	int	i;

	i = 0;
	if (input == NULL)
		return ;
	while (input[i] != NULL)
	{
		free(input[i]);
		input[i] = NULL;
		i++;
	}
	free(input);
	input = NULL;
}
