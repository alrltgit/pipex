/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:12:22 by apple             #+#    #+#             */
/*   Updated: 2025/04/14 16:50:00 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

# define PATH_HOMES_BIN "/nfs/homes/alraltse/bin/"
# define PATH_USR_LOCAL_SBIN "/usr/local/sbin/"
# define PATH_SYSTEM_USR_BIN "/usr/local/bin/"
# define USER_SBIN "/usr/sbin/"
# define USER_BIN "/usr/bin/"
# define SBIN "/sbin/"
# define BIN "/bin/"
# define USR_GAMES "/usr/games/"
# define USR_LOCAL_GAMES "/usr/local/games/"
# define SNAP_BIN "/snap/bin/"

typedef struct s_cmd
{
	char	**cmd_folders;
	char	*cmd_1;
	char	*cmd_2;
	char	*flag_1;
	char	*flag_2;
	char	**args_1;
	char	**args_2;
	int		pipe_fd_1;
	int		pipe_fd_2;
}	t_cmd;

char	*ft_strconcat(t_cmd *c, char *path, char *str);
char	**allocate_memory(t_cmd *c);
void	free_array(char **array);
void	fd_is_open(t_cmd *c, int pipe_fd_2);
int		cmd_1_is_valid(t_cmd *c, char **cmd_folders, char **argv);
int		cmd_2_is_valid(t_cmd *c, char **cmd_folders, char **argv);
int		do_commands_exist(t_cmd *c, char **argv, char **cmd_folders);
int		create_pipe(t_cmd *c, char **argv);
char	**create_arr_for_execve(char *cmd, char *flag);
int		find_flags(t_cmd *c, char **argv);
char	*concat_several_flags(char *flag, char **argv_arr);
char	*ft_arrconcat(char *path, char *str);
int		find_size_of_arr(char **argv);
void	free_program(t_cmd *c);

#endif
