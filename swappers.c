/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swappers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:50:58 by sfelici           #+#    #+#             */
/*   Updated: 2025/04/05 11:50:59 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_a >= 2)
	{
		temp = stacks->a[0];
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = temp;
	}
	ft_printf("sa\n");
}
