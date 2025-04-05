/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:50:48 by sfelici           #+#    #+#             */
/*   Updated: 2025/04/05 11:50:51 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_first_two(t_stacks *stacks)
{
	pb(stacks);
	pb(stacks);
}

void	sort_big_loop(t_stacks *stacks)
{
	int			best_idx;
	int			best_target;
	t_stackinfo	info_a;
	t_stackinfo	info_b;

	while (stacks->size_a > 3)
	{
		find_best_move(stacks, &best_idx, &best_target);
		info_a.stack = stacks->a;
		info_a.size = stacks->size_a;
		info_a.idx = best_idx;
		info_a.name = 'a';
		info_b.stack = stacks->b;
		info_b.size = stacks->size_b;
		info_b.idx = best_target;
		info_b.name = 'b';
		rotate_both(stacks, info_a, info_b);
		pb(stacks);
	}
}

void	push_back_b(t_stacks *stacks)
{
	while (stacks->size_b > 0)
		push_one_b_to_a(stacks);
}

void	final_rotation(t_stacks *stacks)
{
	int			final_min_idx;
	t_stackinfo	info_a;

	final_min_idx = get_min_index(stacks->a, stacks->size_a);
	info_a.stack = stacks->a;
	info_a.size = stacks->size_a;
	info_a.idx = final_min_idx;
	info_a.name = 'a';
	rotate_to_top(stacks, info_a);
}
