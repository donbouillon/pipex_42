/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:09:19 by slistle           #+#    #+#             */
/*   Updated: 2023/03/15 23:03:21 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(unsigned char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int n)
{
	int	sign;

	sign = 0;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (n < 0)
	{
		ft_putchar('-');
		n *= -1;
		sign = 1;
	}
	if (n >= 10)
		return (ft_putnbr(n / 10) + ft_putnbr(n % 10) + sign);
	return (ft_putchar(n + 48) + sign);
}

int	ft_u_putnbr(unsigned int n)
{
	if (n >= 10)
		return (ft_putnbr(n / 10) + ft_putnbr(n % 10));
	return (ft_putchar(n + 48));
}

int	ft_dec_to_hex(unsigned long n)
{
	if (n > 15)
		return (ft_dec_to_hex(n / 16) + ft_dec_to_hex(n % 16));
	else
	{
		if (n < 10)
			return (ft_putchar(n + 48));
		else
			return (ft_putchar(n % 10 + 97));
	}
}

int	ft_cap_dec_to_hex(unsigned long n)
{
	if (n > 15)
		return (ft_cap_dec_to_hex(n / 16) + ft_cap_dec_to_hex(n % 16));
	else
	{
		if (n < 10)
			return (ft_putchar(n + 48));
		else
			return (ft_putchar(n % 10 + 65));
	}
}
