/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:13:57 by apple             #+#    #+#             */
/*   Updated: 2025/04/08 19:04:26 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	//char	**cmd_folders;
	t_cmd	*c;

	if (argc < 5)
	{
		ft_printf("Not enough arguments.\n");
		exit(1);
	}
	c = malloc(sizeof(t_cmd));
	c->cmd_folders = allocate_memory(c);
	// find_command(c, argv, cmd_folders);
	if (do_commands_exist(c, argv, c->cmd_folders) == 0)
		exit(EXIT_FAILURE);
	else
	{
		find_flags(c, argv);
		create_pipe(c, argv);
	}
	// ft_printf("TEST.\n");
	free_array(c->cmd_folders);
	free(c->cmd_1);
	free(c->cmd_2);
	free(c->flag_1);
	free(c->flag_2);
	free(c);
	return (0);
}
