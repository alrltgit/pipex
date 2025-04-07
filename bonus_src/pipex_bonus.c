/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:15:17 by apple             #+#    #+#             */
/*   Updated: 2025/04/07 15:33:09 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv)
{
	t_cmd	*c;

	if (argc < 5)
	{
		ft_printf("Not enough arguments.");
		exit(1);
	}
	c = malloc(sizeof(t_cmd));
	c->cmd_count = argc;
	c->cmd_folders = allocate_memory_bonus(c);
	add_cmds_to_arr(c, argv);
	add_args_to_arr(c, argv);
	create_pipe_bonus(c);
	free(c->cmds);
	free_args(c->args);
	free_arr(c->cmd_folders);
	free(c);
	return (0);
}
