/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_double.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 21:45:57 by sreinhol          #+#    #+#             */
/*   Updated: 2022/01/25 21:47:52 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_double(char **s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != NULL)
		i++;
	return (i);
}
