/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:52:55 by apple             #+#    #+#             */
/*   Updated: 2025/04/05 16:30:40 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

static int	find_size_of_arr(char **argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	return (len);
}

char	*ft_arrcpy(char *cmd, char *str, int j)
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

	cmd = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(str) + 1));
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

void	concat_several_flags(t_cmd *c, char **argv_arr)
{
	int	i;

	i = 1;
	while (argv_arr[i + 1] != NULL)
	{
		c->flag_1 = ft_arrconcat(c->flag_1, argv_arr[i + 1]);
		i++;
	}
}

void	find_flags(t_cmd *c, char **argv)
{
	char	**argv_2_arr;
	char	**argv_3_arr;
	int		len_2;
	int		len_3;

	argv_2_arr = ft_split(argv[2], ' ');
	argv_3_arr = ft_split(argv[3], ' ');
	len_2 = find_size_of_arr(argv_2_arr);
	len_3 = find_size_of_arr(argv_3_arr);
	if (len_2 == 1)
		c->flag_1 = NULL;
	else
		c->flag_1 = argv_2_arr[1];
	if (len_3 == 1)
		c->flag_2 = NULL;
	else
		c->flag_2 = argv_3_arr[1];
	if (len_2 > 2)
		concat_several_flags(c, argv_2_arr);
	if (len_3 > 2)
		concat_several_flags(c, argv_3_arr);
	free(argv_2_arr);
	free(argv_3_arr);
}
