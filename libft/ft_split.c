/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:13:53 by slistle           #+#    #+#             */
/*   Updated: 2022/12/07 22:25:30 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_local_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str_res;

	i = 0;
	str_res = NULL;
	if (!s || len == 0 || start >= ft_strlen(s))
		return (ft_strdup(""));
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

static int	char_count(char const *s, char c, int i)
{
	int	char_count;

	char_count = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0' && s[i] != c)
	{
		char_count++;
		i++;
	}
	return (char_count);
}

static int	word_count(char const *s, char c)
{
	int	word_count;
	int	i;

	i = 0;
	word_count = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			word_count++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (word_count);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		tmp_i;
	int		j;
	char	**res_str;

	i = 0;
	j = 0;
	res_str = (char **)malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!s || !res_str)
		return (NULL);
	while (j < word_count(s, c))
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
		{
			tmp_i = char_count(s, c, i);
			res_str[j] = ft_local_substr(s, i, tmp_i);
			j++;
		}
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	res_str[j] = NULL;
	return (res_str);
}

// void	ft_print_result(char const *s)
// {
// 	int		len;

// 	len = 0;
// 	while (s[len])
// 		len++;
// 	write(1, s, len);
// }

// int main()
// {
// 	char	**tabstr;
// 	int		i;
// 	i = 0;
// 	tabstr = NULL;
// 	char	*s = "      split       this for   me  !       ";
// 	char	**expected = (char*[6]){"split", "this", "for", "me", "!", NULL};
// 	char	**result = ft_split(s, ' ');
// 	while (*result) {
// 			printf("%d", (strcmp(*result, *expected)));
// 			result++;
// 			expected++;
// 			}
// 	{
// 		// if (!(tabstr = ft_split("", ' ')))
// 		// 	ft_print_result("NULL");
// 		// else
// 		// 	if (!tabstr[0])
// 		// 		ft_print_result("ok\n");
// 			// while (tabstr[i] != NULL)
// 			// {
// 			// 	ft_print_result(tabstr[i]);
// 			// 	write(1, "\n", 1);
// 			// 	i++;
// 			// }
// 	}
// }