/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:52:55 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 18:09:00 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	skip_whitespace(const char *str, int *i)
{
	while (str[*i] == ' ' || str[*i] == '\t')
		(*i)++;
}

static void	trim_quotes_if_needed(char *token, int len)
{
	if ((token[0] == '\'' && token[len - 1] == '\'')
		|| (token[0] == '"' && token[len - 1] == '"'))
	{
		token[len - 1] = '\0';
		ft_memmove(token, token + 1, len - 1);
	}
}

static char	*extract_token(const char *str, int *i)
{
	int		start;
	int		single_q;
	int		double_q;
	int		len;
	char	*token;

	start = *i;
	single_q = 0;
	double_q = 0;
	while (str[*i])
	{
		if (str[*i] == '\'' && !double_q)
			single_q = !single_q;
		else if (str[*i] == '"' && !single_q)
			double_q = !double_q;
		else if ((str[*i] == ' ' || str[*i] == '\t') && !single_q && !double_q)
			break ;
		(*i)++;
	}
	len = *i - start;
	token = ft_substr(str, start, len);
	if (!token)
		return (NULL);
	trim_quotes_if_needed(token, len);
	return (token);
}

static char	**split_args(const char *str)
{
	char	**result;
	char	*token;
	int		i;
	int		count;

	result = malloc(sizeof(char *) * 1024);
	if (!result)
		return (NULL);
	i = 0;
	count = 0;
	while (str[i])
	{
		skip_whitespace(str, &i);
		if (!str[i])
			break ;
		token = extract_token(str, &i);
		if (!token)
			return (NULL);
		result[count++] = token;
	}
	result[count] = NULL;
	return (result);
}

void	find_flags(t_cmd *c, char **argv)
{
	char	**argv_2_arr;
	char	**argv_3_arr;
	int		len_2;
	int		len_3;

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
