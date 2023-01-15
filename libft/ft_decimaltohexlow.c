/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimaltohexlow.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 12:53:03 by sreinhol          #+#    #+#             */
/*   Updated: 2021/09/03 23:03:45 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_decimaltohexlow(unsigned long n, int *count)
{
	unsigned long	tmp;
	char			hexnum;

	hexnum = 0;
	tmp = 0;
	if (n == 0)
		return ;
	ft_decimaltohexlow(n / 16, count);
	tmp = n % 16;
	if (tmp < 10)
		hexnum = (tmp + 48);
	else
		hexnum = ('a' + (tmp - 10));
	write(1, &hexnum, 1);
	(*count)++;
}
