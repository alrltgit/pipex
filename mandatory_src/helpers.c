/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:22:48 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 17:57:26 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	fd_is_open(int pipe_fd_2)
{
	if (pipe_fd_2 < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

static size_t	size_of_str(char *str)
{
	size_t	len;

	len = 0;
	while (str[len] != ' ' && str[len])
		len++;
	return (len);
}

char	*ft_strcpy(char *cmd, char *str, int j)
{
	int	i;

	i = 0;
	while (str[i] != ' ' && str[i])
	{
		cmd[j] = str[i];
		j++;
		i++;
	}
	cmd[j] = '\0';
	return (cmd);
}

char	*ft_strconcat(t_cmd *c, char *path, char *str)
{
	int		i;
	int		j;
	char	*cmd;

	(void)c;
	cmd = malloc(sizeof(char) * (ft_strlen(path) + size_of_str(str) + 1));
	if (!cmd)
	{
		perror("Allocation failed.\n");
		return (NULL);
	}
	j = 0;
	i = 0;
	while (path[i])
	{
		cmd[j] = path[i];
		i++;
		j++;
	}
	return (ft_strcpy(cmd, str, j));
}

char	**allocate_memory(t_cmd *c)
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
