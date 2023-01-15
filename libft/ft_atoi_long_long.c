/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long_long.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 23:05:20 by sreinhol          #+#    #+#             */
/*   Updated: 2022/01/31 23:05:43 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi_long_long(char *str)
{
	int			i;
	int			flag;
	long long	nb;

	flag = 1;
	nb = 0;
	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == 45 && ft_isdigit(str[i + 1]))
	{
		flag *= -1;
		i++;
	}
	while (str[i] == 43 && ft_isdigit(str[i + 1]))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	nb *= flag;
	return (nb);
}
