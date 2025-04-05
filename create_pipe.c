/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:49:04 by apple             #+#    #+#             */
/*   Updated: 2025/04/05 16:27:34 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"


void create_pipe(t_cmd *c, char **argv)
{
    int pipe_fd_1;
    int pipe_fd_2;
    int pipe_fd[2];
    char *args_1[] = {c->cmd_1, c->flag_1, NULL};
    char *args_2[] = {c->cmd_2, c->flag_2, NULL};
    char *envp[] = {NULL};
    pid_t pid_1;
    pid_t pid_2;

    (void)argv;
    pipe_fd_1 = open("infile", O_RDONLY);
    if (pipe_fd_1 < 0)
    {
        perror("Error opening pipe_fd_1.\n");
        exit(EXIT_FAILURE);
    }
    pipe_fd_2 = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (pipe_fd_2 < 0)
    {
        perror("Error opening pipe_fd_2.\n");
        exit(EXIT_FAILURE);
    }
    if (pipe(pipe_fd) == -1)
    {
        perror("pipe error");
        exit(1);
    }
    pid_1 = fork();
    if (pid_1 < 0)
    {
        perror("Fork one failed.");
        exit(1);
    }
    else if (pid_1 == 0)
    {
        dup2(pipe_fd_1, STDIN_FILENO);
        dup2(pipe_fd[1], STDOUT_FILENO);
        close(pipe_fd[0]);
        close(pipe_fd[1]);
        close(pipe_fd_1);
        execve(c->cmd_1, args_1, envp);
        perror("execve failed");
        exit(EXIT_FAILURE);
    }
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
        dup2(pipe_fd_2, STDOUT_FILENO);
        close(pipe_fd_2);
        execve(c->cmd_2, args_2, envp);
        perror("execve failed");
        exit(EXIT_FAILURE); // Ensure child process exits
    }
    close(pipe_fd[0]);
    close(pipe_fd[1]);
    close(pipe_fd_1);
    close(pipe_fd_2);
    
    while (1)
    {
        pid_t pid = wait(NULL);
        if (pid == -1)
        {
            if (errno == ECHILD)
                break;
            else
            {
                perror("wait error");
                exit(EXIT_FAILURE);
            }
        }
    }
}
