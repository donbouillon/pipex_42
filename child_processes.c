/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_processes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 22:20:30 by slistle           #+#    #+#             */
/*   Updated: 2023/08/12 20:02:39 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	child_process(char **argv, char **envp, t_pipex_var *s)
{
	s->infile = open(argv[1], O_RDONLY, 0644);
	if (s->infile == -1)
	{
		ft_printf("Error\nInfile\n");
		close(s->fd[0]);
		close(s->fd[1]);
		exit(1);
	}
	close(s->fd[0]);
	dup2(s->infile, STDIN);
	close(s->infile);
	dup2(s->fd[1], STDOUT);
	close(s->fd[1]);
	execute(argv[2], envp, s);
}

int	child_process_two(char **argv, t_pipex_var *s)
{
	s->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (s->outfile == -1)
	{
		ft_printf("Error\nOutfile\n");
		close(s->fd[0]);
		close(s->fd[1]);
		exit(1);
	}
	close(s->fd[1]);
	dup2(s->fd[0], STDIN);
	dup2(s->outfile, STDOUT);
	close(s->fd[0]);
	close(s->outfile);
	return (0);
}
