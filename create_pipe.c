/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:49:04 by apple             #+#    #+#             */
/*   Updated: 2025/04/03 17:40:01 by alraltse         ###   ########.fr       */
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
    int prev_pipe;
    char *args_1[] = {c->cmd_1, "-l", NULL};
    char *args_2[] = {c->cmd_2, "-l", NULL};
    char *envp[] = {NULL};
    pid_t pid_1;
    pid_t pid_2;

    (void)argv;
    prev_pipe = STDIN_FILENO;
    pipe_fd_1 = open("infile", O_RDONLY);
    if (pipe_fd_1 < 0)
    {
        perror("Error opening pipe_fd_1.\n");
        exit(EXIT_FAILURE);
    }
    dup2(pipe_fd_1, STDIN_FILENO);
    pipe_fd_2 = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (pipe_fd_2 < 0)
    {
        perror("Error opening pipe_fd_2.\n");
        exit(EXIT_FAILURE);
    }
    dup2(pipe_fd_2, STDOUT_FILENO);
    
    if (pipe(pipe_fd) == -1) {
        perror("pipe error");
        return ;
    }
    pid_1 = fork();
    if (pid_1 < 0)
    {
        perror("Fork one failed.");
        exit(1);
    }
    else if (pid_1 == 0) // child process 1
    {
        dup2(prev_pipe, STDIN_FILENO);
        execve(c->cmd_1, args_1, envp);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
    }
    pid_2 = fork();
    if (pid_2 < 0)
    {
        ft_printf("Fork two failed.\n");
        exit(1);
    }
    else if (pid_2 == 0) // child process 2
    {
        dup2(pipe_fd[1], STDOUT_FILENO);
        execve(c->cmd_2, args_2, envp);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
    }
    prev_pipe = pipe_fd[0];
    close(pipe_fd[1]);
    while (wait(NULL) > 0);
}
