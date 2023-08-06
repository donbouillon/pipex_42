/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 22:12:35 by slistle           #+#    #+#             */
/*   Updated: 2022/11/11 20:41:12 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int alnum)
{
	int	result;

	result = 0;
	if (alnum >= '0' && alnum <= '9')
	{
		result = 1;
	}
	else if ((alnum >= 'A' && alnum <= 'Z') || (alnum >= 'a' && alnum <= 'z'))
	{
		result = 1;
	}
	return (result);
}
