/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 23:08:04 by slistle           #+#    #+#             */
/*   Updated: 2023/03/15 23:01:35 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "ft_printf.h"

int		ft_putchar(unsigned char c);
int		ft_putnbr(int n);
int		ft_u_putnbr(unsigned int n);
int		ft_dec_to_hex(unsigned long n);
int		ft_cap_dec_to_hex(unsigned long n);
int		ft_putstr(char *s);
int		ft_putaddr(long long address);
size_t	ft_strlen(char *str);
int		specifiers(va_list value, char content);
int		ft_printf(const char *param, ...);

#endif