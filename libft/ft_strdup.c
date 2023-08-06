/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:38:09 by slistle           #+#    #+#             */
/*   Updated: 2022/12/07 21:52:50 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	char	*cp_str;

	i = 0;
	while (s[i] != '\0')
		i++;
	cp_str = (char *)malloc(i + 1);
	if (!cp_str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		cp_str[i] = s[i];
		i++;
	}
	cp_str[i] = '\0';
	return (cp_str);
}
