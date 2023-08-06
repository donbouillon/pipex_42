/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 21:39:46 by slistle           #+#    #+#             */
/*   Updated: 2022/11/30 00:34:53 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		j;
	char	*res_s;

	i = 0;
	j = ft_strlen(s);
	res_s = (char *)malloc(j + 1);
	if (!res_s)
		return (NULL);
	while (s[i] != '\0')
	{
		res_s[i] = f(i, s[i]);
		i++;
	}
	res_s[i] = '\0';
	return (res_s);
}
