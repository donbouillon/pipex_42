/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 16:14:24 by slistle           #+#    #+#             */
/*   Updated: 2022/12/07 21:53:11 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t				l_dst;
	size_t				l_src;
	size_t				i;

	if ((!dst || !src) && size == 0)
		return (0);
	l_dst = ft_strlen(dst);
	l_src = ft_strlen(src);
	i = 0;
	if (size <= l_dst || size == 0)
		return (l_src + size);
	while (src[i] != '\0' && i + l_dst < size - 1)
	{
		dst[l_dst + i] = src[i];
		i++;
	}
	dst[l_dst + i] = '\0';
	return (l_dst + l_src);
}
