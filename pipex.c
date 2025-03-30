/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:13:57 by apple             #+#    #+#             */
/*   Updated: 2025/03/30 19:37:34 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int do_commands_exist(char **argv)
{
    char *cmd_1;
    char *cmd_2;

    cmd_1 = ft_strconcat(PATH_BIN, argv[2]);
    cmd_2 = ft_strconcat(PATH_BIN, argv[3]);
    // ft_printf("cmd_1: %s\n", cmd_1);
    // ft_printf("cmd_2: %s\n", cmd_2);
    if (!access(cmd_1, F_OK) || !access(cmd_2, F_OK))
    {
        perror("One of the commands don't exist.\n");
        free(cmd_1);
        free(cmd_2);
        return (0);
    }
    ft_printf("Commands exist.\n");
    free(cmd_1);
    free(cmd_2);
    return (1);
}

int main(int argc, char **argv)
{
    do_commands_exist(argv);
    return (0);
}