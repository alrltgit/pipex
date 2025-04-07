/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:25:17 by apple             #+#    #+#             */
/*   Updated: 2025/04/07 16:49:42 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**create_arr_for_execve(char *cmd, char *flag)
{
	char	**argv_arr;

	argv_arr = malloc(sizeof(char *) * 3);
	if (!argv_arr)
		return (NULL);
	argv_arr[0] = cmd;
	argv_arr[1] = flag;
	argv_arr[2] = NULL;
	return (argv_arr);
}

void	fd_is_open(int pipe_fd_2)
{
	if (pipe_fd_2 < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}
