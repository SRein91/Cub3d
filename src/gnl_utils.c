/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 18:17:16 by sreinhol          #+#    #+#             */
/*   Updated: 2022/06/11 17:22:24 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

size_t	ft_strlen(const char *str)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_strdup(const char *str)
{
	size_t	len;
	size_t	i;
	char	*dest;

	if (str == NULL)
		return (NULL);
	len = ft_strlen(str);
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (0);
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*new;

	if (!s1 || !s2)
		return (0);
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (0);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	return (new);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	str_len;
	char	*sub_str;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
		return (NULL);
	sub_str = (char *)malloc(len + 1);
	if (sub_str == NULL)
		return (NULL);
	i = 0;
	str_len = ft_strlen(s);
	while (i < len && (i + start) < str_len)
	{
		sub_str[i] = s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

void	gnl(char **str, int in, bool map, t_check *check)
{
	if (map == true)
	{
		free((*str));
		(*str) = NULL;
		(*str) = get_next_line(in);
		return ;
	}
	if (map == false)
	{
		free((*str));
		(*str) = NULL;
		(*str) = get_next_line(in);
		check->control++;
		return ;
	}
}
