/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:22:48 by apple             #+#    #+#             */
/*   Updated: 2025/04/07 13:15:49 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	add_to_arr(char **cmd_folders)
{
	cmd_folders[0] = PATH_HOMES_BIN;
	cmd_folders[1] = PATH_USR_LOCAL_SBIN;
	cmd_folders[2] = PATH_SYSTEM_USR_BIN;
	cmd_folders[3] = USER_SBIN;
	cmd_folders[4] = USER_BIN;
	cmd_folders[5] = SBIN;
	cmd_folders[6] = BIN;
	cmd_folders[7] = USR_GAMES;
	cmd_folders[8] = USR_LOCAL_GAMES;
	cmd_folders[9] = SNAP_BIN;
	cmd_folders[10] = NULL;
}

char	**allocate_memory_bonus(t_cmd *c)
{
	c->cmd_folders = malloc(sizeof(char *) * (10 + 1));
	c->cmd_folders[0] = malloc(sizeof(char) * ft_strlen(PATH_HOMES_BIN));
	c->cmd_folders[1] = malloc(sizeof(char) * ft_strlen(PATH_USR_LOCAL_SBIN));
	c->cmd_folders[2] = malloc(sizeof(char) * ft_strlen(PATH_SYSTEM_USR_BIN));
	c->cmd_folders[3] = malloc(sizeof(char) * ft_strlen(USER_SBIN));
	c->cmd_folders[4] = malloc(sizeof(char) * ft_strlen(USER_BIN));
	c->cmd_folders[5] = malloc(sizeof(char) * ft_strlen(SBIN));
	c->cmd_folders[6] = malloc(sizeof(char) * ft_strlen(BIN));
	c->cmd_folders[7] = malloc(sizeof(char) * ft_strlen(USR_GAMES));
	c->cmd_folders[8] = malloc(sizeof(char) * ft_strlen(USR_LOCAL_GAMES));
	c->cmd_folders[9] = malloc(sizeof(char) * ft_strlen(SNAP_BIN));
	add_to_arr(c->cmd_folders);
	return (c->cmd_folders);
}
