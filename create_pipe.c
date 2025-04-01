/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 17:49:04 by apple             #+#    #+#             */
/*   Updated: 2025/04/01 13:57:40 by alraltse         ###   ########.fr       */
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

void redirect_stdin_to_pipe_fd_1(int pipe_fd_1)
{
    int fd;

    fd = 0;
    dup2(pipe_fd_1, fd);
    close(pipe_fd_1);
}

void redirect_stdout_to_pipe_fd_2(int pipe_fd_2)
{
    int fd;

    fd = 1;
    dup2(pipe_fd_2, fd);
    close(pipe_fd_2);
}

void create_pipe(char **argv)
{
    int pipe_fd_1;
    int pipe_fd_2;
    char buffer[20];
    int *pipe_fd_arr;
    // size_t nbytes_read;
    pid_t pid;

    pipe_fd_1 = open(argv[1], O_RDONLY);
    if (pipe_fd_1 < 0)
        pipe_fd_1 = open("infile", O_CREAT | O_RDONLY, 0644);
    pipe_fd_2 = open(argv[4], O_RDWR);
    if (pipe_fd_2 < 0)
        pipe_fd_2 = open("outfile", O_CREAT | O_RDWR, 0644);
    pipe_fd_arr = create_pipefd_arr(pipe_fd_1, pipe_fd_2);
    // redirect standard input to pipe_fd_1 file descriptor
    redirect_stdin_to_pipe_fd_1(pipe_fd_1);
    // redirect standard output to pipe_fd_2 file descriptor
    redirect_stdout_to_pipe_fd_2(pipe_fd_2);
    // nbytes_read = read(STDIN_FILENO, buffer, sizeof(buffer));
    // if (nbytes_read < 0)
    // {
    //     perror("Read failed");
    //     return ;
    // }
    // ft_printf("Read from stdin: %s\n", buffer);
    // add pipe_fd_1 and pipe_fd_2 into an array
    // pipe_fd_arr = create_pipefd_arr(pipe_fd_1, pipe_fd_2);
    // int i = 0;
    // while (i < 2)
    // {
    //     ft_printf("pipe_fd: %d\n", pipe_fd_arr[i]);
    //     i++;
    // }
    // create a parent and a child processes
    pid = fork();
    if (pid < 0)
    {
        ft_printf("Fork failed.\n");
        return ;
    }
    else if (pid == 0)
    {
        // ft_printf("The child process PID: %d\n", getpid());
        close(pipe_fd_2);
        write(pipe_fd_1, STDIN_FILENO, sizeof(buffer));
        close(pipe_fd_1);
    }
    else
    {
        // ft_printf("Parent process PID: %d\nChild process PID: %d\n", getpid(), pid);
        close(pipe_fd_1);
        read(pipe_fd_2, buffer, sizeof(buffer));
        close(pipe_fd_2);
    }
    pipe(pipe_fd_arr);
}
