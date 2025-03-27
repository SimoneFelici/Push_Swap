#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>

typedef struct s_stacks
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stacks;

typedef struct s_stackinfo
{
	int		*stack;
	int		size;
	int		idx;
	char	name;
}	t_stackinfo;

// SWAP

void	silent_sa(t_stacks *stacks);
void	silent_sb(t_stacks *stacks);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

// ROTATE UP

void	silent_ra(t_stacks *stacks);
void	silent_rb(t_stacks *stacks);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

// ROTATE DOWN

void	silent_rra(t_stacks *stacks);
void	silent_rrb(t_stacks *stacks);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);

// PUSH

void	pb(t_stacks *stacks);
void	pa(t_stacks *stacks);

int		check_errors(int size, char **numbers);
int		has_duplicates(int *arr, int size);
void	free_split(char **split);
void	fill_array(int *array, char **argv, int size);

int		get_min_index(int *arr, int size);
int		find_target_in_b(int val, int *b, int size_b);

void	rotate_to_top(t_stacks *stacks, t_stackinfo info);

void	sort_three(t_stacks *stacks);
void	sort_array(t_stacks *stacks);
void	sort_stacks(t_stacks *stacks);

#endif
