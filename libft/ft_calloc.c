/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 11:38:22 by sreinhol          #+#    #+#             */
/*   Updated: 2021/07/25 16:26:04 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char			*p;
	unsigned int	nb;
	unsigned int	i;

	nb = count * size;
	p = malloc(nb);
	if (!p)
		return (NULL);
	i = 0;
	while (nb--)
	{
		p[i] = 0;
		i++;
	}
	return ((void *)p);
}
