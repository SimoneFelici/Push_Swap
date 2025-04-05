/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotators.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:52:08 by sfelici           #+#    #+#             */
/*   Updated: 2025/04/05 11:52:10 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks)
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
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
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
	ft_printf("rb\n");
}

void	rra(t_stacks *stacks)
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
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
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
	ft_printf("rrb\n");
}
