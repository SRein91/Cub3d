/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 20:14:52 by sreinhol          #+#    #+#             */
/*   Updated: 2022/01/30 19:01:23 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getbeg(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1);
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[i]) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	ft_getend(const char *s1, const char *set)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(s1) - 1;
	i = 0;
	while (i < len)
	{
		if (ft_strchr(set, s1[len - i]) == 0)
			break ;
		i++;
	}
	return (len - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int				beg;
	int				end;
	char			*newstr;

	if (!s1 || !set)
		return (NULL);
	beg = ft_getbeg(s1, set);
	end = ft_getend(s1, set);
	if (end <= beg)
		return (ft_strdup(""));
	newstr = ft_substr(s1, beg, (end - beg + 1));
	return (newstr);
}
