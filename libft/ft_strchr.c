/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 16:50:26 by sreinhol          #+#    #+#             */
/*   Updated: 2022/01/27 20:06:25 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*str;
	size_t			i;

	str = (unsigned char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == '\0' && (unsigned char)c == '\0')
	{
		return ((char *) &s[i]);
	}
	return (NULL);
}
