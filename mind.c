/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mind.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:50:38 by sfelici           #+#    #+#             */
/*   Updated: 2025/04/05 11:50:39 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_total_cost(t_stacks *stacks, int i, int target_idx)
{
	int	cost_a;
	int	cost_b;

	if (i <= stacks->size_a / 2)
		cost_a = i;
	else
		cost_a = stacks->size_a - i;
	if (target_idx <= stacks->size_b / 2)
		cost_b = target_idx;
	else
		cost_b = stacks->size_b - target_idx;
	return (cost_a + cost_b);
}

void	find_best_move(t_stacks *stacks, int *best_idx, int *best_target)
{
	int	i;
	int	cheapest_move;
	int	target_idx;
	int	total_cost;

	cheapest_move = INT_MAX;
	*best_idx = -1;
	*best_target = -1;
	i = 0;
	while (i < stacks->size_a)
	{
		target_idx = find_target_in_b(stacks->a[i],
				stacks->b, stacks->size_b);
		total_cost = calc_total_cost(stacks, i, target_idx);
		if (total_cost < cheapest_move)
		{
			cheapest_move = total_cost;
			*best_idx = i;
			*best_target = target_idx;
		}
		i++;
	}
}

int	find_target_in_a(t_stacks *stacks, int val_b)
{
	int	closest_val;
	int	target_in_a;
	int	i;

	closest_val = INT_MAX;
	target_in_a = -1;
	i = 0;
	while (i < stacks->size_a)
	{
		if (stacks->a[i] > val_b && stacks->a[i] < closest_val)
		{
			closest_val = stacks->a[i];
			target_in_a = i;
		}
		i++;
	}
	return (target_in_a);
}

int	find_target_in_b(int val, int *b, int size_b)
{
	int	i;
	int	target_idx;

	target_idx = -1;
	i = 0;
	while (i < size_b)
	{
		if (b[i] < val && (target_idx == -1 || b[i] > b[target_idx]))
			target_idx = i;
		i++;
	}
	if (target_idx == -1)
		target_idx = get_min_index(b, size_b);
	return (target_idx);
}

int	get_min_index(int *arr, int size)
{
	int	i;
	int	min;
	int	min_idx;

	i = 1;
	min = arr[0];
	min_idx = 0;
	while (i < size)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_idx = i;
		}
		i++;
	}
	return (min_idx);
}
