/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:13:57 by apple             #+#    #+#             */
/*   Updated: 2025/04/07 16:50:06 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	char	**cmd_folders;
	t_cmd	*c;

	if (argc < 5)
	{
		ft_printf("Not enough arguments.\n");
		exit(1);
	}
	c = malloc(sizeof(t_cmd));
	cmd_folders = allocate_memory(c);
	find_command(c, argv, cmd_folders);
	find_flags(c, argv);
	create_pipe(c, argv);
	free(c);
	return (0);
}
