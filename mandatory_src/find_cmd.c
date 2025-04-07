/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:33:43 by apple             #+#    #+#             */
/*   Updated: 2025/04/07 16:49:10 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	*find_cmd_1(t_cmd *c, char **cmd_folders, char **argv)
{
	int		idx;
	char	*cmd_1;

	idx = 0;
	while (cmd_folders[idx])
	{
		cmd_1 = ft_strconcat(c, cmd_folders[idx], argv[2]);
		if (access(cmd_1, X_OK) == 0)
			break ;
		idx++;
	}
	return (cmd_1);
}

static char	*find_cmd_2(t_cmd *c, char **cmd_folders, char **argv)
{
	int		idx;
	char	*cmd_2;

	idx = 0;
	while (cmd_folders[idx])
	{
		cmd_2 = ft_strconcat(c, cmd_folders[idx], argv[3]);
		if (access(cmd_2, X_OK) == 0)
			break ;
		idx++;
	}
	return (cmd_2);
}

void	find_command(t_cmd *c, char **argv, char **cmd_folders)
{
	if (do_commands_exist(c, argv, cmd_folders) == 0)
		exit(EXIT_FAILURE);
	else
	{
		c->cmd_1 = find_cmd_1(c, cmd_folders, argv);
		c->cmd_2 = find_cmd_2(c, cmd_folders, argv);
	}
}
