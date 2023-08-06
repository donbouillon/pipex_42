/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleb <gleb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:26:24 by slistle           #+#    #+#             */
/*   Updated: 2023/07/23 17:45:11 by gleb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	ft_putstr(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}

size_t	ft_strlen(char *str)
{
	size_t	c;

	c = 0;
	if (!str)
		return (0);
	while (str[c] != '\0')
		c++;
	return (c);
}

int	ft_putaddr(long long n)
{
	if (n == 0)
		return (write(1, "(nil)", 5));
	else
		return (ft_putstr("0x"), ft_dec_to_hex(n) + 2);
}

int	specifiers(va_list value, char content)
{
	if (content == '%')
		return (write(1, &content, 1));
	else if (content == 'c')
		return (ft_putchar(va_arg(value, int)));
	else if (content == 's')
		return (ft_putstr(va_arg(value, char *)));
	else if (content == 'p')
		return (ft_putaddr(va_arg(value, long long)));
	else if (content == 'd' || content == 'i')
		return (ft_putnbr(va_arg(value, int)));
	else if (content == 'u')
		return (ft_u_putnbr(va_arg(value, unsigned int)));
	else if (content == 'X')
		return (ft_cap_dec_to_hex(va_arg(value, unsigned int)));
	else if (content == 'x')
		return (ft_dec_to_hex(va_arg(value, unsigned int)));
	return (0);
}

int	ft_printf(const char *param, ...)
{
	va_list	value;
	int		i;
	int		nb_char;

	i = 0;
	nb_char = 0;
	va_start(value, param);
	while (param[i] != '\0')
	{
		if (param[i] == '%')
		{
			i++;
			nb_char += specifiers(value, param[i]);
		}
		else
			nb_char += ft_putchar(param[i]);
		i++;
	}
	va_end(value);
	return (nb_char);
}
