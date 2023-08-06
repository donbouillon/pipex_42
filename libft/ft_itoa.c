/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 21:27:04 by slistle           #+#    #+#             */
/*   Updated: 2022/12/07 21:50:41 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_minus(int *n, int *minus)
{
	if (*n < 0)
	{
		*n = *n * -1;
		*minus = 1;
	}
	else
		*minus = 0;
	return (*n);
}

static int	ft_num_len(int n, int *ten, int minus)
{
	int	i;

	i = 1;
	*ten = 1;
	while (n / 10 >= 1)
	{
		n = n / 10;
		*ten = *ten * 10;
		i++;
	}
	if (minus == 1 && n < 10)
		i++;
	if (n == 0)
		i = 1;
	return (i);
}

static char	*ft_memory(int i)
{
	char	*res_str;

		res_str = (char *)malloc(i + 1);
	if (!res_str)
		return (NULL);
	return (res_str);
}

char	*ft_itoa(int n)
{
	int		n_max;
	int		i;
	int		minus;
	int		ten;
	char	*res_str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	n_max = ft_is_minus(&n, &minus);
	i = ft_num_len(n, &ten, minus);
	res_str = ft_memory(i);
	if (!res_str)
		return (NULL);
	if (minus == 1)
		res_str[0] = '-';
	while (minus < i)
	{
		n = n_max / ten;
		n_max = n_max % ten;
		ten = ten / 10;
		res_str[minus] = n + 48;
		minus++;
	}
	res_str[minus] = '\0';
	return (res_str);
}

// int main()
// {
// 	printf("[%s]", ft_itoa(-5859));
// 	// ft_itoa(-543);
// 	return (0);
// }