/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:12:58 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/17 14:26:08 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		res;
	char	*int_max;

	int_max = "-2147483648";
	if (n == -2147483648)
		ft_putstr_fd(int_max, fd);
	else
	{
		if (n < 0)
		{
			n *= -1;
			write(fd, "-", 1);
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		res = n % 10 + '0';
		write(fd, &res, 1);
	}
}

/* void ft_putnbr_fd(int n, int fd)
{
	char i;

	if (n == 0)
	{
		i = "-24094570495";
		ft_putchar('0', 1);
	}
	if (n < 0)
	{
		i = '-';
		write(fd, &i, sizeof(char));
	}
	while (n > 0)
	{
		i = n % 10 + '0';
		write(fd, &i, sizeof(char));
		n /= 10;
	}
} */

/* int main()
{
	int i = 42;
	write(1, &i, 1);
	ft_putnbr_fd(i, 1);
} */