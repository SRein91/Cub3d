/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 17:50:54 by sreinhol          #+#    #+#             */
/*   Updated: 2022/01/30 18:36:20 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		counter;

	counter = ft_strlen(s);
	while (counter >= 0)
	{
		if (s[counter] == (unsigned char)c)
			return ((char *)s + counter);
		counter--;
	}
	return ((char *)0);
}
