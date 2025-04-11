/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:49:04 by apple             #+#    #+#             */
/*   Updated: 2025/04/11 19:01:06 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	create_child_process_2(t_cmd *c,
	int *pipe_fd, char **args_2, char **argv)
{
	pid_t	pid_2;
	char	*envp[1];

	c->pipe_fd_2 = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	fd_is_open(c, c->pipe_fd_2);
	envp[0] = NULL;
	pid_2 = fork();
	if (pid_2 < 0)
	{
		ft_printf("Fork two failed.\n");
		exit(1);
	}
	else if (pid_2 == 0)
	{
		dup2(pipe_fd[0], STDIN_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		dup2(c->pipe_fd_2, STDOUT_FILENO);
		close(c->pipe_fd_2);
		execve(c->cmd_2, args_2, envp);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}

static void	create_child_process_1(t_cmd *c,
	int *pipe_fd, char **args_1, char **argv)
{
	char	*envp[1];
	pid_t	pid_1;

	c->pipe_fd_1 = open(argv[1], O_RDONLY);
	fd_is_open(c, c->pipe_fd_1);
	envp[0] = NULL;
	pid_1 = fork();
	if (pid_1 < 0)
	{
		perror("Fork one failed.");
		exit(1);
	}
	else if (pid_1 == 0)
	{
		dup2(c->pipe_fd_1, STDIN_FILENO);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[0]);
		close(pipe_fd[1]);
		close(c->pipe_fd_1);
		execve(c->cmd_1, args_1, envp);
		perror("execve failed");
		exit(EXIT_FAILURE);
	}
}

static void	close_fds(int *pipe_fd, int pipe_fd_1, int pipe_fd_2)
{
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	close(pipe_fd_1);
	close(pipe_fd_2);
}

void	create_pipe(t_cmd *c, char **argv)
{
	int		pipe_fd[2];

	(void)argv;
	c->args_1 = create_arr_for_execve(c->cmd_1, c->flag_1);
	c->args_2 = create_arr_for_execve(c->cmd_2, c->flag_2);
	if (pipe(pipe_fd) == -1)
	{
		perror("pipe error");
		exit(1);
	}
	c->pipe_fd_1 = 0;
	create_child_process_1(c, pipe_fd, c->args_1, argv);
	c->pipe_fd_2 = 0;
	create_child_process_2(c, pipe_fd, c->args_2, argv);
	close_fds(pipe_fd, c->pipe_fd_1, c->pipe_fd_2);
	while (wait(NULL) > 0)
		;
	free_array(c->args_1);
	free_array(c->args_2);
}
