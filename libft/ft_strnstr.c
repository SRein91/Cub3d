/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:56:07 by sreinhol          #+#    #+#             */
/*   Updated: 2021/07/25 22:33:46 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	j = 0;
	while (j <= len && haystack[j] != '\0')
	{
		i = 0;
		while (needle[i] && haystack[j] && needle[i] == haystack[j])
		{
			i++;
			j++;
		}
		if (needle[i] == '\0' && j <= len)
			return ((char *)&haystack[j - i]);
		j = j - i + 1;
	}
	return (NULL);
}
