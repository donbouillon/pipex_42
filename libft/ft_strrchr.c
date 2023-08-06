/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 20:23:09 by slistle           #+#    #+#             */
/*   Updated: 2022/12/07 21:53:30 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		j;
	char	*res_s;
	char	*tmp_s;

	i = 0;
	j = -1;
	tmp_s = (char *)s;
	res_s = tmp_s;
	while (tmp_s[i] != '\0')
	{
		if ((unsigned char)tmp_s[i] == (unsigned char)c)
		{
			j = i;
		}
		i++;
	}
	if (j == -1)
	{
		res_s = NULL;
		j = tmp_s[i];
	}
	if (c == '\0')
		return (&tmp_s[i]);
	return (&res_s[j]);
}
