/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:13:57 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 18:10:34 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	t_cmd	*c;

	if (argc < 5)
	{
		ft_printf("Not enough arguments.\n");
		exit(1);
	}
	c = malloc(sizeof(t_cmd));
	c->cmd_folders = allocate_memory(c);
	if (do_commands_exist(c, argv, c->cmd_folders) == 0)
	{
		free_array(c->cmd_folders);
		free(c);
		exit(EXIT_SUCCESS);
	}
	else
	{
		find_flags(c, argv);
		create_pipe(c, argv);
		free_program(c);
	}
	return (0);
}
