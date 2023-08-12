/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:18:08 by gleb              #+#    #+#             */
/*   Updated: 2023/08/12 18:38:42 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"
#include "string.h"

void	ft_exit_error(char *msg)
{
	ft_printf("%s\n", msg);
	exit(1);
}

void	no_path(char *msg)
{
	perror(msg);
	exit(1);
}

char	*path_finder(char *cmd, char **envp, t_pipex_var *s)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
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

char	*direct_path(char *cmd, t_pipex_var *s)
{

	s->path = ft_strdup(cmd);
		if (access(s->path, X_OK) == 0)
			return (s->path);
		free(s->path);
	return (NULL);
}

void	ft_error_execve(char *msg, t_pipex_var *s)
{
	int	i;

	i = 0;
	ft_printf("%s\n", msg);
	while (s->cmd[i])
			free(s->cmd[i++]);
		free(s->cmd);
	free(s->path);
}

void	execute(char *argv, char **envp, t_pipex_var *s)
{
	int	i;

	i = 0;
	if (argv[i] == '\"' && argv[ft_strlen(argv) - 1] == '\"')
		s->cmd = remove_quotes(argv);
	else
	{
		s->cmd = ft_split(argv, ' ');
		if (!s->cmd)
		{
			write(2, "Error\nallocation failed\n", ft_strlen("Error\nallocation failed\n"));
			exit(1);
		}
		else if (!*(s->cmd))
		{
			free(s->cmd);
			write(2, "Error\ncommand not found\n", ft_strlen("Error\ncommand not found\n"));
			exit(1);
		}
	}
	i = 0;
	s->path = direct_path(argv, s);
	if (!s->path)
		s->path = path_finder(s->cmd[0], envp, s);
	if (!s->path)
	{
		while (s->cmd[i])
			free(s->cmd[i++]);
		free(s->cmd);
		no_path("Error\ncommand not found");
		exit(1);
	}
	if (execve(s->path, s->cmd, envp) == -1)
		ft_error_execve("Error\nexecve\n\n\n\n", s);
}



