/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 21:56:09 by slistle           #+#    #+#             */
/*   Updated: 2022/12/07 21:51:46 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (lst)
	{
		lst->content = content;
		lst->next = NULL;
	}
	return (lst);
}

// int main(void)
// {
// t_list node1 =ft_lstnew(5);
// t_list node2 =ft_lstnew(6);
// }
