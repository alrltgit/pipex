/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:31:30 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 18:30:01 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	cmd_1_is_valid(t_cmd *c, char **cmd_folders, char **argv)
{
	int		idx;
	int		flag_1;
	char	*temp_result;

	idx = 0;
	flag_1 = 0;
	while (cmd_folders[idx])
	{
		temp_result = ft_strconcat(c, cmd_folders[idx], argv[2]);
		c->cmd_1 = ft_strdup(temp_result);
		if (access(c->cmd_1, X_OK) == 0)
		{
			flag_1 = 1;
			free(temp_result);
			return (flag_1);
		}
		idx++;
		free(c->cmd_1);
		free(temp_result);
	}
	return (flag_1);
}

int	cmd_2_is_valid(t_cmd *c, char **cmd_folders, char **argv)
{
	int		idx;
	int		flag_2;
	char	*temp_result;

	idx = 0;
	flag_2 = 0;
	while (cmd_folders[idx])
	{
		temp_result = ft_strconcat(c, cmd_folders[idx], argv[3]);
		c->cmd_2 = ft_strdup(temp_result);
		if (access(c->cmd_2, X_OK) == 0)
		{
			flag_2 = 1;
			free(temp_result);
			return (flag_2);
		}
		idx++;
		free(c->cmd_2);
		free(temp_result);
	}
	free(c->cmd_1);
	return (flag_2);
}

int	do_commands_exist(t_cmd *c, char **argv, char **cmd_folders)
{
	if (cmd_1_is_valid(c, cmd_folders, argv) == 0
		|| cmd_2_is_valid(c, cmd_folders, argv) == 0)
	{
		if (cmd_1_is_valid(c, cmd_folders, argv) == 0)
			ft_printf("Command doesn't exist: %s\n", argv[2]);
		else
		{
			free(c->cmd_1);
			ft_printf("Command doesn't exist: %s\n", argv[3]);
		}
		return (0);
	}
	return (1);
}
