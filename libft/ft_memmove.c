/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 19:03:08 by slistle           #+#    #+#             */
/*   Updated: 2022/12/07 21:52:11 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*new_dest;
	unsigned const char	*new_src;

	i = 0;
	new_dest = dest;
	new_src = src;
	if ((!dest && !src) || n == 0)
		return (dest);
	if (dest > src)
	{
		while (n-- > 0)
			new_dest[n] = new_src[n];
	}
	else
	{
		while (n > i)
		{
			new_dest[i] = new_src[i];
			i++;
		}
	}
	return (dest);
}
