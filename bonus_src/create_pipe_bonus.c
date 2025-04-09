/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:45:13 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 17:09:27 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// static void	exit_process_bonus(void)
// {
// 	int	status;
// 	int	exit_code;
// 	int	code;

// 	status = 0;
// 	exit_code = 0;
// 	while (wait(&status) > 0)
// 	{
// 		if (WIFEXITED(status))
// 		{
// 			code = WEXITSTATUS(status);
// 			if (code != 0)
// 				exit_code = code;
// 		}
// 		else if (WIFSIGNALED(status))
// 			exit_code = 1;
// 	}
// 	exit(exit_code);
// }

static void	call_pipe(t_cmd *c, int *pipe_fd, int i)
{
	if (pipe(pipe_fd) == -1 && i != c->cmd_count - 1)
	{
		perror("Pipe failed.\n");
		exit(EXIT_FAILURE);
	}
}

static void	handle_child_process(t_cmd *c, int fd, int *pipe_fd, int i)
{
	int		outfile;
	char	*envp[1];

	dup2(fd, STDIN_FILENO);
	if (i == c->cmd_count - 1)
	{
		outfile = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		fd_is_open_bonus(outfile);
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
	}
	else
	{
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
	if (i != 0)
		close(fd);
	if (i < c->cmd_count - 1)
		close(pipe_fd[0]);
	envp[0] = NULL;
	execve(c->cmds[i], c->args_bonus[i], envp);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

int	handle_pipe_fds(int *pipe_fd, int fd)
{
	close(pipe_fd[1]);
	fd = pipe_fd[0];
	return (fd);
}

void	create_pipe_bonus(t_cmd *c)
{
	int		fd;
	int		pipe_fd[2];
	int		i;
	pid_t	pid;

	fd = open("infile", O_RDONLY);
	fd_is_open_bonus(fd);
	i = 0;
	c->cmd_count -= 3;
	while (i < c->cmd_count)
	{
		call_pipe(c, pipe_fd, i);
		pid = fork();
		did_fork_fail(pid);
		if (pid == 0)
			handle_child_process(c, fd, pipe_fd, i);
		if (i != 0)
			close(fd);
		if (i != c->cmd_count - 1)
			fd = handle_pipe_fds(pipe_fd, fd);
		i++;
	}
	while (wait(NULL) > 0)
			;
	// exit_process_bonus();
}
