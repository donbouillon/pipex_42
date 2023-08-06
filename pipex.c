/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 15:49:54 by gleb              #+#    #+#             */
/*   Updated: 2023/08/06 21:27:52 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void execute_cmd(char *cmd, int input_fd, int output_fd) {
    pid_t pid = fork();
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        if (input_fd != STDIN_FILENO) {
            dup2(input_fd, STDIN_FILENO);
            close(input_fd);
        }
        if (output_fd != STDOUT_FILENO) {
            dup2(output_fd, STDOUT_FILENO);
            close(output_fd);
        }
        execlp("sh", "sh", "-c", cmd, NULL);
        perror("execvp");
        exit(EXIT_FAILURE);
    }
}

void execute_pipeline(char *infile, char *cmd1, char *cmd2, char *outfile) {
    int pipe_fd[2];
    if (pipe(pipe_fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    execute_cmd(cmd1, open(infile, O_RDONLY), pipe_fd[1]);
    close(pipe_fd[1]);

    int infile_fd = open(outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (infile_fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    execute_cmd(cmd2, pipe_fd[0], infile_fd);
    close(pipe_fd[0]);

    wait(NULL);
    wait(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s infile \"cmd1\" \"cmd2\" outfile\n", argv[0]);
        return EXIT_FAILURE;
    }

    execute_pipeline(argv[1], argv[2], argv[3], argv[4]);

    return EXIT_SUCCESS;
}


// #include "includes/pipex.h"

// void child_process(int fd_input, int fd_output, char **cmd1)
// {
//     int fd_pipe[2]; // Use an array of two integers

//     if (pipe(fd_pipe) == -1)
//         ft_exit_error("Error\nPipe error");

//     id_t id = fork();
//     if (id == -1)
//         ft_exit_error("Error\nFork error");

//     if (id == 0) { // Child process 1
//         close(fd_pipe[0]);
//         dup2(fd_input, STDIN_FILENO);
//         dup2(fd_pipe[1], STDOUT_FILENO);
//         close(fd_input);
//         close(fd_output);
//         execvp(cmd1[0], cmd1);
//         ft_exit_error("Error\nCommand 1 execution");
//     }

//     close(fd_pipe[1]);
//     dup2(fd_pipe[0], STDIN_FILENO);
//     close(fd_output);
// }

// void parent_process(int fd_output, char **cmd2)
// {
//     dup2(fd_output, STDOUT_FILENO);
//     execvp(cmd2[0], cmd2);
//     ft_exit_error("Error\nCommand 2 execution");
// }

// void ft_pipex(int fd_input, int fd_output, char **cmd1, char **cmd2)
// {
//     child_process(fd_input, fd_output, cmd1);
//     parent_process(fd_output, cmd2);
// }

// int main(int argc, char **argv)
// {
//     int     fd_input;
//     int     fd_output;
//     char    **cmd1;
//     char    **cmd2;

//     if (argc != 5)
//         ft_exit_error("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile");

//     fd_input = open(argv[1], O_RDONLY);
//     if (fd_input == -1)
//         ft_exit_error("Error\nFile 1 opening error");

//     cmd1 = ft_split_cmd(argv[2]);
//     cmd2 = ft_split_cmd(argv[3]);
//     if (!cmd1 || !cmd2)
//         ft_exit_error("Error\nMemory allocation error");

//     fd_output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd_output == -1)
//         ft_exit_error("Error\nFile 2 opening error");

//     ft_pipex(fd_input, fd_output, cmd1, cmd2);
//     ft_exit_error("Error\nCommand execution error");
// }