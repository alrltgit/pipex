/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:56:25 by apple             #+#    #+#             */
/*   Updated: 2025/04/09 13:12:14 by alraltse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void free_program(t_cmd *c)
{
	free_array(c->cmd_folders);
	free(c->cmd_1);
	free(c->cmd_2);
	free(c->flag_1);
	free(c->flag_2);
	free(c);
}

void	free_array(char **array)
{
	int	i;

	if (!*array)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
