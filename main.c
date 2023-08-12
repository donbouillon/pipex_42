/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slistle <slistle@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 22:45:03 by slistle           #+#    #+#             */
/*   Updated: 2023/08/12 23:11:51 by slistle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	t_pipex_var	s;

	precautions(argc, &s);
	initialization(&s);
	first_process(argv, envp, &s);
	second_process(argv, envp, &s);
	close_and_wait(&s);
	return (0);
}
