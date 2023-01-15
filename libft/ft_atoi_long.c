/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/17 10:34:19 by sreinhol          #+#    #+#             */
/*   Updated: 2021/11/16 20:20:59 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi_long(char *str)
{
	int			i;
	int			flag;
	long int	nb;

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
