/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 23:08:36 by slistle           #+#    #+#             */
/*   Updated: 2023/08/09 17:10:03 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str_res;

	i = 0;
	str_res = NULL;
	if (!s || len == 0 || start >= ft_strlen(s))
		return (NULL);
	if (len == start || len < ft_strlen(s))
		str_res = (char *)malloc(len + 1);
	else if (len <= ft_strlen(s))
		str_res = (char *)malloc(len - start + 1);
	else if (len > ft_strlen(s))
		str_res = (char *)malloc(ft_strlen(s) + 1);
	if (!str_res)
		return (NULL);
	while (i < len && s[i] != '\0')
	{
		str_res[i] = s[start + i];
		i++;
	}
	str_res[i] = '\0';
	return (str_res);
}
