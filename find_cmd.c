/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 16:33:43 by apple             #+#    #+#             */
/*   Updated: 2025/04/01 16:36:17 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

static char	*find_cmd_1(char **cmd_folders, char **argv)
{
	int		    idx;
    char    *cmd_1;

	idx = 0;
	while (cmd_folders[idx])
	{
		cmd_1 = ft_strconcat(cmd_folders[idx], argv[2]);
		if (access(cmd_1, X_OK) == 0)
            break ;
		idx++;
	}
	return (cmd_1);
}

static char	*find_cmd_2(char **cmd_folders, char **argv)
{
	int		    idx;
    char    *cmd_2;

	idx = 0;
	while (cmd_folders[idx])
	{
		cmd_2 = ft_strconcat(cmd_folders[idx], argv[3]);
		if (access(cmd_2, X_OK) == 0)
            break ;
		idx++;
	}
	return (cmd_2);
}

void find_command(t_cmd *c, char **argv, char **cmd_folders)
{
    if (do_commands_exist(c, argv, cmd_folders) == 0)
        exit(EXIT_FAILURE);
    else
    {
        c->cmd_1 = find_cmd_1(cmd_folders, argv);
        c->cmd_2 = find_cmd_2(cmd_folders, argv);
        ft_printf("c->cmd_1: %s\n", c->cmd_1);
        ft_printf("c->cmd_2: %s\n", c->cmd_2);
    }
}