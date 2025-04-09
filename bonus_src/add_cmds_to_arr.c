/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmds_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:42:16 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 16:52:25 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	split_till_space(t_cmd *c, char **cmd_folders)
{
	int		idx;
	int		i;
	char	*cmd_path;

	i = 0;
	while (c->cmds[i])
	{
		idx = 0;
		while (cmd_folders[idx])
		{
			cmd_path = ft_strconcat_bonus(c, cmd_folders[idx], c->cmds[i]);
			if (access(cmd_path, X_OK) == 0)
			{
				free(c->cmds[i]);
				c->cmds[i] = cmd_path;
				break ;
			}
			free(cmd_path);
			idx++;
		}
		i++;
	}
}

void	add_cmds_to_arr(t_cmd *c, char **argv)
{
	int	i;
	int	j;

	c->cmds = malloc(sizeof(char *) * (c->cmd_count - 2));
	if (!c->cmds)
		return ;
	i = 2;
	j = 0;
	while (i < c->cmd_count - 1)
	{
		c->cmds[j] = ft_strdup(argv[i]);
		if (!c->cmds)
			return ;
		i++;
		j++;
	}
	c->cmds[j] = NULL;
	split_till_space(c, c->cmd_folders);
}
