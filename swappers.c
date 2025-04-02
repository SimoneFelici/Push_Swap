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
