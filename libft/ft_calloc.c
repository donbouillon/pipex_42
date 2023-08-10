/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:58:02 by slistle           #+#    #+#             */
/*   Updated: 2023/08/10 20:14:57 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tmp_arr;
	size_t	i;
	int		mult;

	i = 0;
	if (size < 0)
		return (NULL);
	mult = nmemb * size;
	tmp_arr = (char *)malloc((nmemb) * size);
	if (!tmp_arr)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (tmp_arr);
	if (mult / size != nmemb)
		return (NULL);
	while (i < nmemb * size)
	{
		tmp_arr[i] = 0;
		i++;
	}
	return (tmp_arr);
}
