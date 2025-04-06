/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 19:15:17 by apple             #+#    #+#             */
/*   Updated: 2025/04/06 23:13:12 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int argc, char **argv)
{
	t_cmd	*c;

	if (argc < 5)
	{
		ft_printf("Not enough arguments.");
		exit(1);
	}
	c = malloc(sizeof(t_cmd));
    c->cmd_count = argc;
    add_cmds_to_arr(c, argv);
    return (0);
}