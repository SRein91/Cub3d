/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdecimal_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 11:48:59 by sreinhol          #+#    #+#             */
/*   Updated: 2021/09/03 13:41:19 by sreinhol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdecimal_fd(unsigned int n, int fd)
{
	if (n == 4294967295)
	{
		ft_putstr_fd("4294967295", fd);
		return ;
	}
	else
	{
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		n = 48 + (n % 10);
	}
	write (fd, &n, 1);
}
