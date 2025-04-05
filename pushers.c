/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:51:36 by sfelici           #+#    #+#             */
/*   Updated: 2025/04/05 11:51:39 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stacks *stacks)
{
	int	i;

	if (stacks->size_a > 0)
	{
		i = stacks->size_b;
		while (i > 0)
		{
			stacks->b[i] = stacks->b[i - 1];
			i--;
		}
		stacks->b[0] = stacks->a[0];
		i = 0;
		while (i < stacks->size_a - 1)
		{
			stacks->a[i] = stacks->a[i + 1];
			i++;
		}
		stacks->size_a--;
		stacks->size_b++;
		ft_printf("pb\n");
	}
}

void	pa(t_stacks *stacks)
{
	int	i;

	if (stacks->size_b > 0)
	{
		i = stacks->size_a;
		while (i > 0)
		{
			stacks->a[i] = stacks->a[i - 1];
			i--;
		}
		stacks->a[0] = stacks->b[0];
		i = 0;
		while (i < stacks->size_b - 1)
		{
			stacks->b[i] = stacks->b[i + 1];
			i++;
		}
		stacks->size_a++;
		stacks->size_b--;
		ft_printf("pa\n");
	}
}
