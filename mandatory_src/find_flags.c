/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:52:55 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 16:43:14 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

static char	**split_args(const char *str)
{
	char	**result = NULL;
	int		i = 0;
	int		start = 0;
	int		in_single = 0;
	int		in_double = 0;
	int		count = 0;

	result = malloc(sizeof(char *) * 1024);
	if (!result)
		return (NULL);
	while (str[i])
	{
		while (str[i] == ' ' || str[i] == '\t')
			i++;

		if (!str[i])
			break;

		start = i;
		in_single = 0;
		in_double = 0;

		while (str[i])
		{
			if (str[i] == '\'' && !in_double)
				in_single = !in_single;
			else if (str[i] == '\"' && !in_single)
				in_double = !in_double;
			else if ((str[i] == ' ' || str[i] == '\t') && !in_single && !in_double)
				break;
			i++;
		}
		int len = i - start;
		char *token = ft_strdup(str + start);
		if (!token)
			return (NULL);
		if ((token[0] == '\'' && token[len - 1] == '\'') || (token[0] == '"' && token[len - 1] == '"'))
		{
			token[len - 1] = '\0';
			ft_memmove(token, token + 1, len - 1);
		}

		result[count++] = token;
	}
	result[count] = NULL;
	return (result);
}

void find_flags(t_cmd *c, char **argv)
{
	char **argv_2_arr;
	char **argv_3_arr;
    int len_2;
    int len_3;

    argv_2_arr = split_args(argv[2]);
    argv_3_arr = split_args(argv[3]);
    len_2 = find_size_of_arr(argv_2_arr);
    len_3 = find_size_of_arr(argv_3_arr);

    if (len_2 > 1)
        c->flag_1 = concat_several_flags(ft_strdup(argv_2_arr[1]), argv_2_arr);
    else
        c->flag_1 = NULL;

    if (len_3 > 1)
        c->flag_2 = concat_several_flags(ft_strdup(argv_3_arr[1]), argv_3_arr);
    else
        c->flag_2 = NULL;
    free_array(argv_2_arr);
    free_array(argv_3_arr);
}
