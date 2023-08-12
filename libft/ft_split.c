/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 23:13:53 by slistle           #+#    #+#             */
/*   Updated: 2023/08/12 16:46:35 by slistle          ###   ########.fr       */
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

// void	ft_free_strs(char **strs)
// {
// 	int	i;

// 	i = 0;
// 	while (strs && strs[i])
// 	{
// 		free(strs[i]);
// 		i++;
// 	}
// 	free(strs);
// }

// static int	ft_count_word(char const *s, char c)
// {
// 	int	i;
// 	int	j;
// 	int	k;

// 	i = 0;
// 	k = 0;
// 	while (s[i])
// 	{
// 		while (s[i] && s[i] == c)
// 			i++;
// 		j = 0;
// 		while (s[i] && s[i] != c)
// 		{
// 			i++;
// 			j++;
// 		}
// 		if (j > 0)
// 			k++;
// 		while (s[i] && s[i] == c)
// 			i++;
// 	}
// 	return (k);
// }

// static int	ft_word_len(char const *s, char c, int i)
// {
// 	int	j;

// 	j = 0;
// 	while (s[i] && s[i] == c)
// 		i++;
// 	while (s[i] && s[i] != c)
// 	{
// 		i++;
// 		j++;
// 	}
// 	return (j);
// }

// static char	**ft_split2(char const *s, char **strs, char c, int i)
// {
// 	int	j;
// 	int	k;

// 	j = 0;
// 	while (j < ft_countw(s, c))
// 	{
// 		strs[j] = malloc(sizeof(char) * (ft_word_len(s, c, i) + 1));
// 		if (!strs[j])
// 			return (ft_free_strs(strs), NULL);
// 		k = 0;
// 		while (s[i] && s[i] == c)
// 			i++;
// 		while (s[i] && s[i] != c)
// 		{
// 			strs[j][k] = s[i];
// 			i++;
// 			k++;
// 		}
// 		strs[j][k] = '\0';
// 		j++;
// 	}
// 	strs[j] = NULL;
// 	return (strs);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**strs;
// 	int		i;

// 	if (!s)
// 		return (write(2, "split : we cant split NULL\n", 28), NULL);
// 	strs = malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
// 	if (!strs)
// 		return (NULL);
// 	i = 0;
// 	return (ft_split2(s, strs, c, i));
// }