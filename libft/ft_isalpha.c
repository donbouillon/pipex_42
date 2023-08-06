/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:06:04 by slistle           #+#    #+#             */
/*   Updated: 2022/11/09 21:48:25 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int alphabet)
{
	int	result;

	if (alphabet >= 'A' && alphabet <= 'Z')
	{
		result = 1;
	}
	else if (alphabet >= 'a' && alphabet <= 'z')
	{
		result = 2;
	}
	else
		result = 0;
	return (result);
}
