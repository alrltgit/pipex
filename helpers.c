/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:22:48 by apple             #+#    #+#             */
/*   Updated: 2025/04/04 16:29:20 by apple            ###   ########.fr       */
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

void find_flags(t_cmd *c, char **argv)
{
    char **argv_2_arr;
    char **argv_3_arr;

    argv_2_arr = ft_split(argv[2], ' ');
    argv_3_arr = ft_split(argv[3], ' ');
    c->flag_1 = argv_2_arr[1];
    c->flag_2 = argv_3_arr[1];
    ft_printf("c->flag_1: %s\n", c->flag_1);
    ft_printf("c->flag_2: %s\n", c->flag_2);
    free(argv_2_arr);
    free(argv_3_arr);
}

char	*ft_strconcat(t_cmd *c, char *path, char *str)
{
	int i;
    int j;
    char *cmd;

    (void)c;
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
    cmd_folders[0] = PATH_HOMES_BIN;
    cmd_folders[1] = PATH_USR_LOCAL_SBIN;
    cmd_folders[2] = PATH_SYSTEM_USR_BIN;
    cmd_folders[3] = USER_SBIN;
    cmd_folders[4] = USER_BIN;
    cmd_folders[5] = SBIN;
    cmd_folders[6] = BIN;
    cmd_folders[7] = USR_GAMES;
    cmd_folders[8] = USR_LOCAL_GAMES;
    cmd_folders[9] = SNAP_BIN;
    cmd_folders[10] = NULL;
}

char **allocate_memory()
{
    char **cmd_folders;
    
    cmd_folders = malloc(sizeof(char *) * (10 + 1));
    cmd_folders[0] = malloc(sizeof(char) * ft_strlen(PATH_HOMES_BIN));
    cmd_folders[1] = malloc(sizeof(char) * ft_strlen(PATH_USR_LOCAL_SBIN));
    cmd_folders[2] = malloc(sizeof(char) * ft_strlen(PATH_SYSTEM_USR_BIN));
    cmd_folders[3] = malloc(sizeof(char) * ft_strlen(USER_SBIN));
    cmd_folders[4] = malloc(sizeof(char) * ft_strlen(USER_BIN));
    cmd_folders[5] = malloc(sizeof(char) * ft_strlen(SBIN));
    cmd_folders[6] = malloc(sizeof(char) * ft_strlen(BIN));
    cmd_folders[7] = malloc(sizeof(char) * ft_strlen(USR_GAMES));
    cmd_folders[8] = malloc(sizeof(char) * ft_strlen(USR_LOCAL_GAMES));
    cmd_folders[9] = malloc(sizeof(char) * ft_strlen(SNAP_BIN));
    add_to_arr(cmd_folders);
    return (cmd_folders);
}
