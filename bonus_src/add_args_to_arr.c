/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_args_to_arr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 09:50:55 by apple             #+#    #+#             */
/*   Updated: 2025/04/07 14:28:45 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	add_args_to_arr(t_cmd *c, char **argv)
{
	int	i;
	int	j;

	c->args = malloc(sizeof(char **) * (c->cmd_count + 1));
	if (!c->args)
		return ;
	i = 0;
	j = 2;
	while (c->cmds[i] && j < c->cmd_count - 1)
	{
		c->args[i] = ft_split(argv[j], ' ');
		if (!c->args[i])
			return ;
		i++;
		j++;
	}
	c->args[i] = NULL;
}
