/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:25:17 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 15:33:54 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**create_arr_for_execve(char *cmd, char *flag)
{
	char	**argv_arr;

	argv_arr = malloc(sizeof(char *) * 3);
	if (!argv_arr)
		return (NULL);
	argv_arr[0] = ft_strdup(cmd);
	if (flag == NULL)
		argv_arr[1] = NULL;
	else
		argv_arr[1] = ft_strdup(flag);
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
