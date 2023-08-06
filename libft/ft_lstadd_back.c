/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 21:01:12 by slistle           #+#    #+#             */
/*   Updated: 2022/12/03 16:37:13 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		tmp = ft_lstlast(*lst);
		tmp->next = new;
	}
}

// int main()
// {
// 	t_list *l = ft_lstnew(strdup("nyacat"));
// 	t_list *n = ft_lstnew(strdup("OK"));
// 	ft_lstadd_back(&l, n);
// 	return 0;
// }