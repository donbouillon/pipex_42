/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:49:54 by gleb              #+#    #+#             */
/*   Updated: 2023/08/12 18:47:08 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	initialization(t_pipex_var *s)
{
	s->pid1 = -5;
	s->pid2 = -5;
	s->infile = 0;
	s->outfile = 0;
}

void	first_process(char **argv, char **envp, t_pipex_var *s)
{
	s->pid1 = fork();
	if (s->pid1 == -1)
		ft_exit_error("Error\nfork");
	if (s->pid1 == 0)
		child_process(argv, envp, s);
}

void	second_process(char **argv, char **envp, t_pipex_var *s)
{
	child_process_two(argv, s);
	s->pid2 = fork();
	if (s->pid2 == -1)
		ft_exit_error("Error\nfork");
	if (s->pid2 == 0)
		execute(argv[3], envp, s);
}

void	close_and_wait(t_pipex_var *s)
{
	close(s->outfile);
	close(s->infile);
	close(s->fd[0]);
	close(s->fd[1]);
	waitpid(s->pid1, NULL, 0);
	waitpid(s->pid2, NULL, 0);
}

void	precautions(int argc, t_pipex_var *s)
{
	if (argc != 5)
		ft_exit_error("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile\n");
	// if (ft_strlen(argv[2]) < 2 || ft_strlen(argv[3]) < 2)
	// 	ft_exit_error("no commands\n");
	if (pipe(s->fd) == -1)
		ft_exit_error("Error\npipe");
}
