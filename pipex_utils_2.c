/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:37:19 by slistle           #+#    #+#             */
/*   Updated: 2023/08/12 20:01:31 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	ft_error_execve(char *msg, t_pipex_var *s)
{
	int	i;

	i = 0;
	ft_printf("%s\n", msg);
	while (s->cmd[i])
		free(s->cmd[i++]);
	free(s->cmd);
	free(s->path);
	exit(1);
}
