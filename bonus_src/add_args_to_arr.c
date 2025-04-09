/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:50:55 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 17:35:27 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static int count_args(char *str)
{
    int count = 0;
    int in_quotes = 0;
    int in_braces = 0;

    while (*str)
    {
        while (*str && (*str == ' ' || *str == '\t'))
            str++;
        if (*str)
            count++;
        while (*str && (in_quotes || in_braces || (*str != ' ' && *str != '\t')))
        {
            if (*str == '"' || *str == '\'')
                in_quotes = !in_quotes;
            if (*str == '{')
                in_braces = 1;
            if (*str == '}')
                in_braces = 0;
            str++;
        }
    }
    return count;
}

static char **split_args(char *str)
{
    int in_quotes = 0;
    int in_braces = 0;
    char **result;
    int i = 0;
    char *start;

    result = malloc(sizeof(char *) * (count_args(str) + 1));
    if (!result)
        return NULL;
    while (*str)
    {
        while (*str && (*str == ' ' || *str == '\t'))
            str++;
        if (*str)
        {
            start = str;
            while (*str && (in_quotes || in_braces || (*str != ' ' && *str != '\t')))
            {
                if (*str == '"' || *str == '\'')
                    in_quotes = !in_quotes;
                if (*str == '{')
                    in_braces = 1;
                if (*str == '}')
                    in_braces = 0;
                str++;
            }
            result[i] = strndup(start, str - start);
            if (!result[i])
                return NULL;
            i++;
        }
    }
    result[i] = NULL;
    return result;
}

void add_args_to_arr(t_cmd *c, char **argv)
{
    int i = 0;
    int j = 2;

    c->args_bonus = malloc(sizeof(char **) * (c->cmd_count + 1));
    if (!c->args_bonus)
        return;
    while (c->cmds[i] && j < c->cmd_count - 1)
    {
        c->args_bonus[i] = split_args(argv[j]);
        if (!c->args_bonus[i])
            return;
        i++;
        j++;
    }
    c->args_bonus[i] = NULL;
}

// void add_args_to_arr(t_cmd *c, char **argv)
// {
//     int i;
    
//     i = 0;
//     (void)argv;
//     c->args_bonus = malloc(sizeof(char **) * (c->cmd_count - 2));
//     if (!c->args_bonus)
//         return;
//     while (c->cmds[i])
//     {
//         c->args_bonus[i] = ft_split(c->cmds[i], ' ');
//         if (!c->args_bonus[i])
//             return;
//         i++;
//     }
//     c->args_bonus[i] = NULL;
//     int k = 0;
//     int s = 0;
//     while (c->args_bonus[k])
//     {
//         while (c->args_bonus[k][s])
//         {
//             ft_printf("c->args_bonus[%d]: %s\n", k, c->args_bonus[k][s]);
//             s++;
//         }
//         k++;
//     }
// }
