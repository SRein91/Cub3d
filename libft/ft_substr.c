/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 16:14:34 by sreinhol          #+#    #+#             */
/*   Updated: 2021/07/25 16:29:37 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			i;
	int				size;
	const char		*src;
	char			*dst;

	src = s;
	size = len + 1;
	dst = ft_calloc(size, 1);
	if (!src || dst == NULL)
		return (NULL);
	if (ft_strlen(s) <= start)
		return (dst);
	i = 0;
	while (i <= len && s[i] != '\0')
	{
		dst[i] = src[i + start];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
