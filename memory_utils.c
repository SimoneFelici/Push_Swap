/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:51:46 by sfelici           #+#    #+#             */
/*   Updated: 2025/04/05 11:51:47 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

bool	allocate_b(t_stacks *stacks)
{
	int	*temp_b;

	temp_b = (int *)malloc(sizeof(int) * stacks->size_a);
	if (!temp_b)
		return (false);
	stacks->b = temp_b;
	stacks->size_b = 0;
	return (true);
}
