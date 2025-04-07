/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:44:51 by apple             #+#    #+#             */
/*   Updated: 2025/04/07 16:17:33 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

char	*ft_strconcat_bonus(t_cmd *c, char *path, char *str)
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

void	fd_is_open_bonus(int pipe_fd_2)
{
	if (pipe_fd_2 < 0)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}
}

void	did_fork_fail(pid_t pid)
{
	if (pid < 0)
	{
		perror("Fork failed.\n");
		exit(EXIT_FAILURE);
	}
}
