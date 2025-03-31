/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 17:12:22 by apple             #+#    #+#             */
/*   Updated: 2025/03/31 16:32:28 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include "libft/libft.h"

#define PATH_USR_LOCAL_BIN "/usr/local/bin/"
#define PATH_USR_LOCAL_SBIN "/usr/local/sbin/"
#define PATH_SYSTEM_USR_BIN "/System/Cryptexes/App/usr/bin/"
#define PATH_USR_BIN "/usr/bin/"
#define BIN "/bin/"
#define USR_SBIN "/usr/sbin/"
#define SBIN "/sbin/"
#define USER_BIN "/Users/apple/Library/Python/3.9/bin/"
#define SECURITY_LOCAL_BIN "/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/local/bin/"
#define SECURITY_USER_BIN "/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/bin/"
#define BOOTSTRAP_BIN "/var/run/com.apple.security.cryptexd/codex.system/bootstrap/usr/appleinternal/bin/"
#define LIBRARY_BIN "/Library/Apple/usr/bin/"

char	*ft_strconcat(char *path, char *str);
char    **allocate_memory();
void    free_array(char **array);

int cmd_1_is_valid(char **cmd_folders, char **argv);
int cmd_2_is_valid(char **cmd_folders, char **argv);
int do_commands_exist(char **argv);

#endif