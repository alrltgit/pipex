/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:49:04 by apple             #+#    #+#             */
/*   Updated: 2025/04/02 16:33:22 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int *create_pipefd_arr(int pipe_fd_1, int pipe_fd_2)
{
    int *pipe_fd_arr;

    pipe_fd_arr = malloc(sizeof(int) * 2);
    pipe_fd_arr[0] = pipe_fd_1;
    pipe_fd_arr[1] = pipe_fd_2;
    return (pipe_fd_arr);
}

// void redirect_to_pipe(int pipe_fd, int fd)
// {
//     dup2(pipe_fd, fd);
//     close(pipe_fd);
// }

void create_pipe(t_cmd *c, char **argv)
{
    int pipe_fd_1;
    int pipe_fd_2;
    int pipe_fd[2];
    char *args_1[] = {c->cmd_1, "-l", NULL};
    char *args_2[] = {c->cmd_2, "-l", NULL};
    char *envp[] = {NULL};
    pid_t pid_1;
    pid_t pid_2;

    (void)c;
    (void)argv;
    if (pipe(pipe_fd) == -1) {
        perror("pipe error");
        return ;
    }
    pid_1 = fork();
    if (pid_1 < 0)
    {
        perror("Fork one failed.");
        return ;
    }
    else if (pid_1 == 0) // child process 1
    {
        pipe_fd_1 = open(argv[1], O_RDWR);
        if (pipe_fd_1 < 0)
        {
            perror("Error opening pipe_fd_1.\n");
            exit(EXIT_FAILURE);
        }
        pipe_fd_1 = dup(STDIN_FILENO);
        pipe_fd[1] = dup(pipe_fd_1);
        ft_printf("buffer: %s\n", get_next_line(pipe_fd_1));
        execve(c->cmd_1, args_1, envp);
    }
    // ft_printf("argv[1]: %s", argv[1]);
    pid_2 = fork();
    if (pid_2 < 0)
    {
        ft_printf("Fork two failed.\n");
        return ;
    }
    else if (pid_2 == 0) // child process 2
    {
        pipe_fd_2 = open(argv[4], O_WRONLY);
        if (pipe_fd_2 < 0)
        {
            perror("Error opening pipe_fd_2.\n");
            exit(EXIT_FAILURE);
        }
        // pipe_fd[0] = dup(pipe_fd[1]);
        pipe_fd_2 = dup(pipe_fd[0]);
        execve(c->cmd_2, args_2, envp);
    }
    close(pipe_fd[0]);
    close(pipe_fd[1]);

    // waitpid(pid_1, NULL, 0);
    // waitpid(pid_2, NULL, 0);
}
