/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apple <apple@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:47:43 by apple             #+#    #+#             */
/*   Updated: 2025/04/07 15:32:11 by apple            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_args(char ***args)
{
	int	i;
	int	j;

	if (!args)
		return ;
	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			free(args[i][j]);
			j++;
		}
		free(args[i]);
		i++;
	}
	free(args);
}

void	free_arr(char **array)
{
	int	i;

	if (!array)
		return ;
	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
