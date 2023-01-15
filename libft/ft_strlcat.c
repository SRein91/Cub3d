/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:01:56 by sreinhol          #+#    #+#             */
/*   Updated: 2021/07/25 16:29:05 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	counter;
	size_t	offset;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstsize <= dstlen)
		return (dstsize + srclen);
	counter = 0;
	offset = dstlen;
	while (src[counter] != '\0')
	{
		if (offset == dstsize - 1)
			break ;
		dst[offset] = src[counter];
		offset++;
		counter++;
	}
	dst[offset] = '\0';
	return (dstlen + srclen);
}
