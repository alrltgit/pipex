/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:50:55 by apple             #+#    #+#             */
/*   Updated: 2025/04/08 11:19:35 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char *strip_quotes(const char *start, size_t len)
{
    if ((start[0] == '\'' && start[len - 1] == '\'') ||
        (start[0] == '"' && start[len - 1] == '"'))
    {
        return strndup(start + 1, len - 2);
    }
    return strndup(start, len);
}

static int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

static int count_args(const char *str)
{
    int count = 0;
    int in_squote = 0, in_dquote = 0;

    while (*str)
    {
        while (*str && is_space(*str))
            str++;
        if (*str)
            count++;
        while (*str && (in_squote || in_dquote || !is_space(*str)))
        {
            if (*str == '\'' && !in_dquote)
                in_squote = !in_squote;
            else if (*str == '"' && !in_squote)
                in_dquote = !in_dquote;
            str++;
        }
    }
    return count;
}

static char **split_args(const char *str)
{
    char **result;
    int i = 0;
    const char *start;
    int in_squote = 0, in_dquote = 0;

    result = malloc(sizeof(char *) * (count_args(str) + 1));
    if (!result)
        return NULL;

    while (*str)
    {
        while (*str && is_space(*str))
            str++;
        if (*str)
        {
            start = str;
            while (*str && (in_squote || in_dquote || !is_space(*str)))
            {
                if (*str == '\'' && !in_dquote)
                    in_squote = !in_squote;
                else if (*str == '"' && !in_squote)
                    in_dquote = !in_dquote;
                str++;
            }
            result[i++] = strip_quotes(start, str - start);
        }
    }
    result[i] = NULL;
    return result;
}

void add_args_to_arr(t_cmd *c, char **argv)
{
    int i = 0;
    int j = 2;

    c->args = malloc(sizeof(char **) * (c->cmd_count + 1));
    if (!c->args)
        return;
    while (c->cmds[i] && j < c->cmd_count - 1)
    {
        c->args[i] = split_args(argv[j]);
        if (!c->args[i])
            return;
        i++;
        j++;
    }
    c->args[i] = NULL;
}
