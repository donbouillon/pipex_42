/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:39:57 by slistle           #+#    #+#             */
/*   Updated: 2022/12/07 21:49:15 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	negative;

	i = 0;
	result = 0;
	negative = 0;
	while (nptr[i] >= 1 && nptr[i] <= 32 && nptr[i] != 27)
		i++;
	if (nptr[i] == '-' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
	{
		negative = 1;
		i++;
	}
	if (nptr[i] == '+' && (nptr[i + 1] >= '0' && nptr[i + 1] <= '9'))
		i++;
	while (nptr[i] != '\0' && nptr[i] >= '0' && nptr[i] <= '9')
	{
		result = result * 10 + nptr[i] - 48;
		i++;
	}
	if (negative == 1)
		result = result * -1;
	return (result);
}
