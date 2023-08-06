/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 11:18:08 by gleb              #+#    #+#             */
/*   Updated: 2023/08/06 21:12:16 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"
#include <string.h>

void	ft_exit_error(char *msg)
{
    ft_printf("%s\n", msg);
    exit(1); 
}

char **ft_split_cmd(char *cmd)
{
    // Count the number of arguments in the command
    int num_args = 0;
    for (char *c = cmd; *c != '\0'; c++) {
        if (*c == ' ')
            num_args++;
    }
    num_args++; // Include the command itself as an argument

    char **cmd_array = (char **)malloc(sizeof(char *) * (num_args + 1));
    if (!cmd_array)
        return NULL;

    // Tokenize the command and store arguments in cmd_array
    int i = 0;
    char *token = strtok(cmd, " ");
    while (token != NULL) {
        cmd_array[i] = ft_strdup(token);
        token = strtok(NULL, " ");
        i++;
    }
    cmd_array[i] = NULL; // Null-terminate the array

    return cmd_array;
}
