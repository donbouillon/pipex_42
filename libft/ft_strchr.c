/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 18:21:40 by slistle           #+#    #+#             */
/*   Updated: 2022/12/07 21:52:45 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*tmp_s;

	i = 0;
	tmp_s = (char *)s;
	while (tmp_s[i] != '\0')
	{
		if ((unsigned char)tmp_s[i] == (unsigned char)c)
		{
			return (&tmp_s[i]);
		}
		i++;
	}
	if (c == '\0')
		return (&tmp_s[i]);
	return (NULL);
}
