#include "push_swap.h"

void	sort_stacks(t_stacks *stacks)
{
	push_first_two(stacks);
	sort_big_loop(stacks);
	sort_three(stacks);
	push_back_b(stacks);
	final_rotation(stacks);
}

void	sort_three(t_stacks *stacks)
{
	int	max_pos;

	max_pos = 0;
	if (stacks->a[1] > stacks->a[max_pos])
		max_pos = 1;
	if (stacks->a[2] > stacks->a[max_pos])
		max_pos = 2;
	if (max_pos == 0)
		ra(stacks);
	else if (max_pos == 1)
		rra(stacks);
	if (stacks->a[0] > stacks->a[1])
		sa(stacks);
}

void	sort_array(t_stacks *stacks)
{
	if (!allocate_b(stacks))
		return ;
	if (is_sorted(stacks->a, stacks->size_a))
	{
		free(stacks->b);
		return ;
	}
	if (stacks->size_a == 2)
	{
		if (stacks->a[0] > stacks->a[1])
			sa(stacks);
	}
	else if (stacks->size_a == 3)
		sort_three(stacks);
	else
		sort_stacks(stacks);
	free(stacks->b);
}
