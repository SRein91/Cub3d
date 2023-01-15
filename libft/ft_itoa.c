/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/19 10:24:38 by sreinhol          #+#    #+#             */
/*   Updated: 2021/07/25 16:26:41 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	strl(long n)
{
	int		len;

	len = 0;
	if (n < 0)
	{
		n = n * -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*ft_strrev(char *str)
{
	int		j;
	int		i;
	char	tmp;
	int		len;

	len = ft_strlen(str);
	j = len - 1;
	i = 0;
	while (i < (len / 2))
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		j--;
		i++;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*s;

	i = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	s = ft_calloc(sizeof(char) * (strl(n) + 1), 1);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		s[strl(n) - 1] = '-';
		n = -n;
	}
	while (n != 0)
	{
		s[i++] = n % 10 + 48;
		n /= 10;
	}
	return (ft_strrev(s));
}
