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
