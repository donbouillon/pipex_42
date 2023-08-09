/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:18:08 by gleb              #+#    #+#             */
/*   Updated: 2023/08/09 23:35:05 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"
#include "string.h"

void	ft_exit_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	no_path(char *msg, t_pipex_var *s)
{
	ft_printf("%s\n", msg);
	dup2(s->infile, STDOUT);
	dup2(s->fd[1], STDIN);
	exit(1);
}

char	*path_finder(char *cmd, char **envp, t_pipex_var *s)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (envp[i] == NULL)
		no_path("ty pidor", s);
	s->dir_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (s->dir_paths[i])
	{
		s->path_except_cmd = ft_strjoin(s->dir_paths[i], "/");
		s->path = ft_strjoin(s->path_except_cmd, cmd);
		free(s->path_except_cmd);
		if (access(s->path, X_OK) == 0)
			return (s->path);
		free(s->path);
		i++;
	}
	i = 0;
	while (s->dir_paths[i])
		free(s->dir_paths[i++]);
	free(s->dir_paths);
	return (NULL);
}

char	**remove_quotes(char *argv)
{
	char	**ret;
	int		i;

	ret = malloc(sizeof(char *) * 3);
	if (!ret)
		return (NULL);
	i = 0;
	while (argv[i] != ' ' && argv[i])
		i++;
	ret[0] = ft_substr(argv, 0, i);
	i += 2;
	ret[1] = ft_substr(argv, i, ft_strlen(argv) - i - 1);
	ret[2] = 0;
	return (ret);
}

void	check_line(char *argv)
{
	if (ft_strlen(argv) < 2)
		ft_exit_error("no commands\n");
}

void	execute(char *argv, char **envp, t_pipex_var *s)
{
	int	i;

	i = 0;
	if (argv[i] == '\"' && argv[ft_strlen(argv) - 1] == '\"')
		s->cmd = remove_quotes(argv);
	else
		s->cmd = ft_split(argv, ' ');
	i = 0;
	s->path = path_finder(s->cmd[0], envp, s);
	if (!s->path)
	{
		while (s->cmd[i])
			free(s->cmd[i++]);
		free(s->cmd);
		ft_exit_error("Error\n$PATH :(");
	}
	if (execve(s->path, s->cmd, envp) == -1)
		ft_exit_error("Error\nexecve");
}
