/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:18:49 by gleb              #+#    #+#             */
/*   Updated: 2023/08/09 23:32:07 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define STDIN 0
# define STDOUT 1

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct pipex_var_s
{
	pid_t	pid1;
	pid_t	pid2;
	int		outfile;
	int		infile;
	int		fd[2];
	char	**dir_paths;
	char	*path;
	char	*path_except_cmd;
	char	**cmd;
}	t_pipex_var;

void	parent_process(char **argv, char **envp, int *fd);
void	child_process(char **argv, char **envp, t_pipex_var *s);
int		child_process_two(char **argv, t_pipex_var *s);
void	execute(char *argv, char **envp, t_pipex_var *s);
char	**remove_quotes(char *argv);
char	*path_finder(char *cmd, char **envp, t_pipex_var *s);
void	ft_exit_error(char *msg);
void	check_line(char *argv);
void	precautions(int argc, char **argv, t_pipex_var *s);
void	close_and_wait(t_pipex_var *s);
void	second_process(char **argv, char **envp, t_pipex_var *s);
void	first_process(char **argv, char **envp, t_pipex_var *s);
void	initialization(t_pipex_var *s);
void	no_path(char *msg, t_pipex_var *s);


#endif
