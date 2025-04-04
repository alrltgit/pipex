/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:13:57 by apple             #+#    #+#             */
/*   Updated: 2025/04/04 16:08:09 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int main(int argc, char **argv)
{
    char	**cmd_folders;
    t_cmd *c;

    (void)argc;
    c = malloc(sizeof(t_cmd));
	cmd_folders = allocate_memory();
    find_command(c, argv, cmd_folders);
    find_flags(c, argv);
    create_pipe(c, argv);
    free(c);
    return (0);
}