/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:33:43 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 12:59:35 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	find_command(t_cmd *c, char **argv, char **cmd_folders)
{
	// char *temp_1;
	// char *temp_2;

	if (do_commands_exist(c, argv, cmd_folders) == 0)
	{
		free(c->cmd_1);
		free(c->cmd_2);
		free_array(c->cmd_folders);
		free(c);
		exit(EXIT_FAILURE);
	}
	// else
	// {
	// 	temp_1 = find_cmd_1(c, cmd_folders, argv);
	// 	temp_2 = find_cmd_2(c, cmd_folders, argv);
	// 	c->cmd_1 = ft_strdup(temp_1);
	// 	c->cmd_2 = ft_strdup(temp_2);
	// 	free(temp_1);
	// 	free(temp_2);
	// }
}
