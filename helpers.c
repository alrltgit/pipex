/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:22:48 by apple             #+#    #+#             */
/*   Updated: 2025/03/31 17:53:12 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

static size_t size_of_str(char *str)
{
    size_t len;
    
    len = 0;
    while (str[len] != ' ' && str[len])
        len++;
    return (len);
}

char	*ft_strconcat(char *path, char *str)
{
	int i;
    int j;
    char *cmd;

    cmd = malloc(sizeof(char) * (ft_strlen(path) + size_of_str(str) + 1));
    if (!cmd)
    {
        perror("Allocation failed.\n");
        return (NULL);
    }
    j = 0;
    i = 0;
    while (path[i])
    {
        cmd[j] = path[i];
        i++;
        j++;
    }
    i = 0;
    while (str[i] != ' ' && str[i])
    {
        cmd[j] = str[i];
        j++;
        i++;
    }
    cmd[j] = '\0';
    return (cmd);
}

static void add_to_arr(char **cmd_folders)
{
    cmd_folders[0] = PATH_USR_LOCAL_BIN;
    cmd_folders[1] = PATH_USR_LOCAL_SBIN;
    cmd_folders[2] = PATH_SYSTEM_USR_BIN;
    cmd_folders[3] = PATH_USR_BIN;
    cmd_folders[4] = BIN;
    cmd_folders[5] = USR_SBIN;
    cmd_folders[6] = SBIN;
    cmd_folders[7] = USER_BIN;
    cmd_folders[8] = SECURITY_LOCAL_BIN;
    cmd_folders[9] = SECURITY_USER_BIN;
    cmd_folders[10] = BOOTSTRAP_BIN;
    cmd_folders[11] = LIBRARY_BIN;
    cmd_folders[12] = NULL;
}

char **allocate_memory()
{
    char **cmd_folders;
    
    cmd_folders = malloc(sizeof(char *) * (12 + 1));
    cmd_folders[0] = malloc(sizeof(char) * ft_strlen(PATH_USR_LOCAL_BIN));
    cmd_folders[1] = malloc(sizeof(char) * ft_strlen(PATH_USR_LOCAL_SBIN));
    cmd_folders[2] = malloc(sizeof(char) * ft_strlen(PATH_SYSTEM_USR_BIN));
    cmd_folders[3] = malloc(sizeof(char) * ft_strlen(PATH_USR_BIN));
    cmd_folders[4] = malloc(sizeof(char) * ft_strlen(BIN));
    cmd_folders[5] = malloc(sizeof(char) * ft_strlen(USR_SBIN));
    cmd_folders[6] = malloc(sizeof(char) * ft_strlen(SBIN));
    cmd_folders[7] = malloc(sizeof(char) * ft_strlen(USER_BIN));
    cmd_folders[8] = malloc(sizeof(char) * ft_strlen(SECURITY_LOCAL_BIN));
    cmd_folders[9] = malloc(sizeof(char) * ft_strlen(SECURITY_USER_BIN));
    cmd_folders[10] = malloc(sizeof(char) * ft_strlen(BOOTSTRAP_BIN));
    cmd_folders[11] = malloc(sizeof(char) * ft_strlen(LIBRARY_BIN));
    add_to_arr(cmd_folders);
    return (cmd_folders);
}
