/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:15:17 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 16:37:58 by alraltse         ###   ########.fr       */
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
	ft_printf("test1\n");
	add_args_to_arr(c, argv);
	ft_printf("test2\n");
	create_pipe_bonus(c);
	ft_printf("test3\n");
	// free(c->cmds);
	// free_args(c->args_bonus);
	// free_arr(c->cmd_folders);
	// free(c);
	return (0);
}
