/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 13:46:14 by sreinhol          #+#    #+#             */
/*   Updated: 2021/07/25 16:28:51 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		size;
	char	*s;

	size = ft_strlen(s1) + 1;
	s = malloc(size);
	if (!s)
		return (NULL);
	ft_strlcpy(s, s1, (size));
	return (s);
}
