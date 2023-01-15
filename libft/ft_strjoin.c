/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 19:19:22 by sreinhol          #+#    #+#             */
/*   Updated: 2022/02/11 19:50:51 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1len;
	int		s2len;
	int		len;
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	len = (s1len + s2len + 1);
	str = ft_calloc(len, 1);
	if (!str)
		return (NULL);
	else
	{
		ft_strlcpy(str, s1, len);
		ft_strlcat(str, s2, len);
	}
	return (str);
}
