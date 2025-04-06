/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmds_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:42:16 by apple             #+#    #+#             */
/*   Updated: 2025/04/06 23:14:07 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void add_cmds_to_arr(t_cmd *c, char **argv)
{
    int i;
    int j;
    c->cmds = malloc(sizeof(char *) * (c->cmd_count + 1));
    if (!c->cmds)
        return ;
    i = 2;
    j = 0;
    while (i < c->cmd_count - 1)
    {
        c->cmds[j] = ft_strdup(argv[i]);
        if (!c->cmds)
            return ;
        i++;
        j++;
    }
    c->cmds[j] = NULL;
    // i = 0;
    // while (c->cmds[i])
    // {
    //     ft_printf("c->cmds[%d]: %s\n", i, c->cmds[i]);
    //     i++;
    // }
}