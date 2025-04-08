/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:33:43 by apple             #+#    #+#             */
/*   Updated: 2025/04/08 18:34:39 by alraltse         ###   ########.fr       */
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
	char *temp_1;
	char *temp_2;

	if (do_commands_exist(c, argv, cmd_folders) == 0)
		exit(EXIT_FAILURE);
	else
	{
		temp_1 = find_cmd_1(c, cmd_folders, argv);
		temp_2 = find_cmd_2(c, cmd_folders, argv);
		c->cmd_1 = ft_strdup(temp_1);
		c->cmd_2 = ft_strdup(temp_2);
		free(temp_1);
		free(temp_2);
	}
}
