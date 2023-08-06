/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gleb <gleb@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:49:54 by gleb              #+#    #+#             */
/*   Updated: 2023/07/29 12:50:43 by gleb             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void child_process(int fd_input, int fd_output, char **cmd1) {
    int fd_pipe[2];

    if (pipe(fd_pipe) == -1)
        ft_exit_error("Pipe error");

    pid_t id = fork();
    if (id == -1)
        ft_exit_error("Fork error");

    if (id == 0) { // Child process 1
        close(fd_pipe[0]);
        dup2(fd_input, STDIN_FILENO);
        dup2(fd_pipe[1], STDOUT_FILENO);
        close(fd_input);
        close(fd_output);
        execvp(cmd1[0], cmd1);
        ft_exit_error("Command 1 execution error");
    }

    close(fd_pipe[1]);
    dup2(fd_pipe[0], STDIN_FILENO);
    close(fd_input);
    close(fd_output);
}

void parent_process(int fd_output, char **cmd2) {
    dup2(fd_output, STDOUT_FILENO);
    execvp(cmd2[0], cmd2);
    ft_exit_error("Command 2 execution error");
}

void ft_pipex(int fd_input, int fd_output, char **cmd1, char **cmd2) {
    child_process(fd_input, fd_output, cmd1);
    parent_process(fd_output, cmd2);
}

int main(int argc, char **argv) {
    int fd_input, fd_output;
    char **cmd1, **cmd2;

    if (argc != 5)
        ft_exit_error("Usage: ./pipex file1 cmd1 cmd2 file2");

    fd_input = open(argv[1], O_RDONLY);
    if (fd_input == -1)
        ft_exit_error("File 1 opening error");

    fd_output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_output == -1)
        ft_exit_error("File 2 opening error");

    cmd1 = ft_split(argv[2], ' ');
    cmd2 = ft_split(argv[3], ' ');
    if (!cmd1 || !cmd2)
        ft_exit_error("Memory allocation error");

    ft_pipex(fd_input, fd_output, cmd1, cmd2);
    ft_exit_error("Command execution error");
}


// Add other utility functions (ft_split, ft_strtrim, ft_free_split) as mentioned in pipex.h