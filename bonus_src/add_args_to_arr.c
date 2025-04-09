/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:50:55 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 17:19:45 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void add_args_to_arr(t_cmd *c, char **argv)
{
    int i;
    
    i = 0;
    (void)argv;
    c->args_bonus = malloc(sizeof(char **) * (c->cmd_count - 2));
    if (!c->args_bonus)
        return;
    while (c->cmds[i])
    {
        c->args_bonus[i] = ft_split(c->cmds[i], ' ');
        if (!c->args_bonus[i])
            return;
        i++;
    }
    c->args_bonus[i] = NULL;
    int k = 0;
    int s = 0;
    while (c->args_bonus[k])
    {
        while (c->args_bonus[k][s])
        {
            ft_printf("c->args_bonus[%d]: %s\n", k, c->args_bonus[k][s]);
            s++;
        }
        k++;
    }
}
