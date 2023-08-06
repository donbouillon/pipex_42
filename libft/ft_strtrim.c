/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:12:39 by slistle           #+#    #+#             */
/*   Updated: 2022/12/07 21:53:34 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	char	*res_str;

	if (!s1 || !set)
		return (ft_strdup(""));
	start = 0;
	len = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && s1[start] != '\0')
	{
		start++;
	}
	while (ft_strchr(set, s1[len]) && len > start)
	{
		len--;
	}
	len = len - start + 1;
	res_str = ft_substr((char *)s1, start, len);
	return (res_str);
}

// int main()
// {
// 	printf("%s\n",ft_strtrim("121212Th1s121212", "12"));
// 	return (0);
// }