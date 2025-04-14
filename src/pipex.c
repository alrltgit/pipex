/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:13:57 by apple             #+#    #+#             */
/*   Updated: 2025/04/14 15:59:05 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	check_code(int exit_code)
{
	if (exit_code == 1)
		exit(1);
	else
		exit(0);
}

static void	argv_is_valid(int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("The amount of arguments is not correct.\n");
		exit(1);
	}
	if ((argv[2][0] == '\0') || (argv[3][0] == '\0'))
	{
		ft_printf("The argument is not correct.\n");
		exit(1);
	}
}

int	main(int argc, char **argv)
{
	t_cmd	*c;
	int		exit_code;

	argv_is_valid(argc, argv);
	c = malloc(sizeof(t_cmd));
	c->cmd_folders = allocate_memory(c);
	if (do_commands_exist(c, argv, c->cmd_folders) == 0)
	{
		free_array(c->cmd_folders);
		free(c);
		exit(EXIT_FAILURE);
	}
	else
	{
		find_flags(c, argv);
		exit_code = create_pipe(c, argv);
		free_program(c);
		check_code(exit_code);
	}
	return (0);
}
