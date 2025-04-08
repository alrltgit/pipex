/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:50:55 by apple             #+#    #+#             */
/*   Updated: 2025/04/08 13:40:13 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void add_args_to_arr(t_cmd *c, char **argv)
{
    int i = 0;
    int j = 2;

    (void)argv;
    c->args = malloc(sizeof(char **) * (c->cmd_count + 1));
    if (!c->args)
        return;
    while (c->cmds[i] && j < c->cmd_count - 1)
    {
        c->args[i] = ft_split(c->cmds[i], ' ');
        if (!c->args[i])
            return;
        i++;
        j++;
    }
    c->args[i] = NULL;
}
