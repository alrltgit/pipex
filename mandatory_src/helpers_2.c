/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 13:25:17 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 17:57:21 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	find_size_of_arr(char **argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

static char	*ft_arrcpy(char *cmd, char *str, int j)
{
	int	i;

	i = 0;
	while (str[i])
	{
		cmd[j] = str[i];
		j++;
		i++;
	}
	cmd[j] = '\0';
	return (cmd);
}

char	*ft_arrconcat(char *path, char *str)
{
	int		i;
	int		j;
	char	*cmd;

	cmd = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(str) + 2));
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
	cmd[j++] = ' ';
	ft_arrcpy(cmd, str, j);
	return (cmd);
}

char	*concat_several_flags(char *flag, char **argv_arr)
{
	int	i;

	i = 1;
	while (argv_arr[i + 1] != NULL)
	{
		flag = ft_arrconcat(flag, argv_arr[i + 1]);
		i++;
	}
	return (flag);
}

char	**create_arr_for_execve(char *cmd, char *flag)
{
	char	**argv_arr;

	argv_arr = malloc(sizeof(char *) * 3);
	if (!argv_arr)
		return (NULL);
	argv_arr[0] = ft_strdup(cmd);
	if (flag == NULL)
		argv_arr[1] = NULL;
	else
		argv_arr[1] = ft_strdup(flag);
	argv_arr[2] = NULL;
	return (argv_arr);
}
