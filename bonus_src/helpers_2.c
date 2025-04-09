/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:22:48 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 16:36:57 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**allocate_memory_bonus(t_cmd *c)
{
	c->cmd_folders = malloc(sizeof(char *) * (10 + 1));
	c->cmd_folders[0] = ft_strdup(PATH_HOMES_BIN);
	c->cmd_folders[1] = ft_strdup(PATH_USR_LOCAL_SBIN);
	c->cmd_folders[2] = ft_strdup(PATH_SYSTEM_USR_BIN);
	c->cmd_folders[3] = ft_strdup(USER_SBIN);
	c->cmd_folders[4] = ft_strdup(USER_BIN);
	c->cmd_folders[5] = ft_strdup(SBIN);
	c->cmd_folders[6] = ft_strdup(BIN);
	c->cmd_folders[7] = ft_strdup(USR_GAMES);
	c->cmd_folders[8] = ft_strdup(USR_LOCAL_GAMES);
	c->cmd_folders[9] = ft_strdup(SNAP_BIN);
	c->cmd_folders[10] = NULL;
	return (c->cmd_folders);
}
