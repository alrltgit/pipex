/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:13:57 by apple             #+#    #+#             */
/*   Updated: 2025/03/31 23:01:04 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void find_command(t_cmd *c, char **argv, char **cmd_folders)
{
    if (do_commands_exist(c, argv, cmd_folders) == 0)
        exit(EXIT_FAILURE);
    // else
    // {
    //     ft_printf("c->cmd_1: %s\n", c->cmd_1);
    //     ft_printf("c->cmd_2: %s\n", c->cmd_2);
    // }
}

int main(int argc, char **argv)
{
    char	**cmd_folders;
    t_cmd *c;

    (void)argc;
    c = malloc(sizeof(t_cmd));
	cmd_folders = allocate_memory();
    find_command(c, argv, cmd_folders);
    create_pipe(argv);
    free(c);
    return (0);
}