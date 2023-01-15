/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 11:58:44 by sreinhol          #+#    #+#             */
/*   Updated: 2021/07/25 16:28:12 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*csrc;
	char	*cdst;

	csrc = (char *)src;
	cdst = (char *)dst;
	if (csrc == cdst)
		return (dst);
	if (csrc < cdst)
	{
		csrc = csrc + (len - 1);
		cdst = cdst + (len - 1);
		while (len--)
		{
			*cdst-- = *csrc--;
		}
	}
	else
	{
		while (len--)
			*cdst++ = *csrc++;
	}
	return (dst);
}
