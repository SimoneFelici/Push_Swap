/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:51:53 by sfelici           #+#    #+#             */
/*   Updated: 2025/04/05 11:51:54 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack_up(t_stacks *stacks, t_stackinfo info)
{
	while (info.idx-- > 0)
	{
		if (info.name == 'a')
			ra(stacks);
		else
			rb(stacks);
	}
}

void	rotate_stack_down(t_stacks *stacks, t_stackinfo info)
{
	int	reverse_idx;

	reverse_idx = info.size - info.idx;
	while (reverse_idx-- > 0)
	{
		if (info.name == 'a')
			rra(stacks);
		else
			rrb(stacks);
	}
}

void	rotate_to_top(t_stacks *stacks, t_stackinfo info)
{
	if (info.idx <= info.size / 2)
		rotate_stack_up(stacks, info);
	else
		rotate_stack_down(stacks, info);
}

void	push_one_b_to_a(t_stacks *stacks)
{
	int			val_b;
	int			target_in_a;
	t_stackinfo	info_a;

	val_b = stacks->b[0];
	target_in_a = find_target_in_a(stacks, val_b);
	if (target_in_a == -1)
		target_in_a = get_min_index(stacks->a, stacks->size_a);
	info_a.stack = stacks->a;
	info_a.size = stacks->size_a;
	info_a.idx = target_in_a;
	info_a.name = 'a';
	rotate_to_top(stacks, info_a);
	pa(stacks);
}

void	rotate_both(t_stacks *stacks, t_stackinfo a, t_stackinfo b)
{
	while (a.idx > 0 && b.idx > 0 && a.idx <= a.size / 2 && b.idx <= b.size / 2)
	{
		rr(stacks);
		a.idx--;
		b.idx--;
	}
	while (a.idx < a.size && b.idx < b.size \
		&& a.idx > a.size / 2 && b.idx > b.size / 2)
	{
		rrr(stacks);
		a.idx++;
		b.idx++;
	}
	if (a.idx <= a.size / 2)
		while (a.idx-- > 0)
			ra(stacks);
	else
		while ((a.size - a.idx++) > 0)
			rra(stacks);
	if (b.idx <= b.size / 2)
		while (b.idx-- > 0)
			rb(stacks);
	else
		while ((b.size - b.idx++) > 0)
			rrb(stacks);
}
