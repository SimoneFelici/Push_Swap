/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_rotators.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:51:24 by sfelici           #+#    #+#             */
/*   Updated: 2025/04/05 11:51:25 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	silent_ra(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_a > 1)
	{
		temp = stacks->a[0];
		i = 0;
		while (i < stacks->size_a - 1)
		{
			stacks->a[i] = stacks->a[i + 1];
			i++;
		}
		stacks->a[stacks->size_a - 1] = temp;
	}
}

void	silent_rb(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_b > 1)
	{
		temp = stacks->b[0];
		i = 0;
		while (i < stacks->size_b - 1)
		{
			stacks->b[i] = stacks->b[i + 1];
			i++;
		}
		stacks->b[stacks->size_b - 1] = temp;
	}
}

void	silent_rra(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_a > 1)
	{
		temp = stacks->a[stacks->size_a - 1];
		i = stacks->size_a - 1;
		while (i > 0)
		{
			stacks->a[i] = stacks->a[i - 1];
			i--;
		}
		stacks->a[0] = temp;
	}
}

void	silent_rrb(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_b > 1)
	{
		temp = stacks->b[stacks->size_b - 1];
		i = stacks->size_b - 1;
		while (i > 0)
		{
			stacks->b[i] = stacks->b[i - 1];
			i--;
		}
		stacks->b[0] = temp;
	}
}
