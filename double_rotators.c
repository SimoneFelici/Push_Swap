/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_rotators.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:50:18 by sfelici           #+#    #+#             */
/*   Updated: 2025/04/05 11:50:20 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stacks *stacks)
{
	silent_ra(stacks);
	silent_rb(stacks);
	write(1, "rr\n", 3);
}

void	rrr(t_stacks *stacks)
{
	silent_rra(stacks);
	silent_rrb(stacks);
	write(1, "rrr\n", 4);
}
