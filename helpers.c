/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 18:22:48 by apple             #+#    #+#             */
/*   Updated: 2025/03/30 19:15:34 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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