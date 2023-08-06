/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:18:49 by gleb              #+#    #+#             */
/*   Updated: 2023/08/06 20:58:29 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"


void	ft_exit_error(char *msg);
char	**ft_split_cmd(char *cmd);
void	ft_pipex(int fd_input, int fd_output, char **cmd1, char **cmd2);
void	parent_process(int fd_output, char **cmd2);
void	child_process(int fd_input, int fd_output, char **cmd1);
void	ft_exit_error(char *msg);
void	ft_free_cmd_array(char **cmd_array);



#endif
