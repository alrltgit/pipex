/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:31:30 by apple             #+#    #+#             */
/*   Updated: 2025/04/04 15:56:59 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int	cmd_1_is_valid(t_cmd *c, char **cmd_folders, char **argv)
{
	int		idx;
	int		flag_1;

	idx = 0;
	flag_1 = 0;
	while (cmd_folders[idx])
	{
		c->cmd_1 = ft_strconcat(c, cmd_folders[idx], argv[2]);
		if (access(c->cmd_1, X_OK) == 0)
		{
			flag_1 = 1;
			return(flag_1);
		}
		idx++;
	}
	return (flag_1);
}

int	cmd_2_is_valid(t_cmd *c, char **cmd_folders, char **argv)
{
	int		idx;
	int		flag_2;

	idx = 0;
	flag_2 = 0;
	while (cmd_folders[idx])
	{
		c->cmd_2 = ft_strconcat(c, cmd_folders[idx], argv[3]);
		if (access(c->cmd_2, X_OK) == 0)
		{
			flag_2 = 1;
			return (flag_2);
		}
		idx++;
	}
	return (flag_2);
}

int	do_commands_exist(t_cmd *c, char **argv, char **cmd_folders)
{
	if (cmd_1_is_valid(c, cmd_folders, argv) == 0 || cmd_2_is_valid(c, cmd_folders, argv) == 0)
	{
		if (cmd_1_is_valid(c, cmd_folders, argv) == 0)
			ft_printf("Command doesn't exist: %s\n", argv[2]);
		else
			ft_printf("Command doesn't exist: %s\n", argv[3]);
        return (0);
	}
	return (1);
}
