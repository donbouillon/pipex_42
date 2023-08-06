/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:04:50 by slistle           #+#    #+#             */
/*   Updated: 2022/12/07 21:53:22 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp_s1;
	unsigned char	*tmp_s2;
	int				result;

	tmp_s1 = (unsigned char *)s1;
	tmp_s2 = (unsigned char *)s2;
	i = 0;
	result = 0;
	if (n == 0)
		return (result);
	while (tmp_s1[i] != '\0' && --n > 0 && (tmp_s1[i] == tmp_s2[i]))
	{
		i++;
	}
	return (tmp_s1[i] - tmp_s2[i]);
}
