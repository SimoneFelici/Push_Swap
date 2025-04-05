/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:49:59 by sfelici           #+#    #+#             */
/*   Updated: 2025/04/05 11:50:00 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void		silent_sa(t_stacks *stacks);
void		silent_sb(t_stacks *stacks);
void		sa(t_stacks *stacks);
void		sb(t_stacks *stacks);
void		ss(t_stacks *stacks);

// ROTATE UP

void		silent_ra(t_stacks *stacks);
void		silent_rb(t_stacks *stacks);
void		ra(t_stacks *stacks);
void		rb(t_stacks *stacks);

// ROTATE DOWN

void		silent_rra(t_stacks *stacks);
void		silent_rrb(t_stacks *stacks);
void		rra(t_stacks *stacks);
void		rrb(t_stacks *stacks);
void		rotate_both(t_stacks *stacks, t_stackinfo a, t_stackinfo b);
void		rr(t_stacks *stacks);
void		rrr(t_stacks *stacks);

// PUSH

void		pb(t_stacks *stacks);
void		pa(t_stacks *stacks);

// OTHER

bool		is_all_digits(const char *str);
bool		is_valid_number(const char *arg);
int			is_sorted(int *array, int size);
int			check_errors(int size, char **numbers);
int			has_duplicates(int *arr, int size);
void		free_split(char **split);
void		fill_array(int *array, char **argv, int size);
bool		fill_and_check_numbers(int size, char **numbers, int *temp);
bool		check_sign_and_zero(const char *arg, int *sign, int *i);
long long	ps_atol_no_sign(const char *str);
bool		allocate_b(t_stacks *stacks);
void		final_rotation(t_stacks *stacks);
void		push_back_b(t_stacks *stacks);
void		sort_big_loop(t_stacks *stacks);
void		push_first_two(t_stacks *stacks);
void		find_best_move(t_stacks *stacks, int *best_idx, int *best_target);
void		push_one_b_to_a(t_stacks *stacks);
int			calc_total_cost(t_stacks *stacks, int i, int target_idx);
void		rotate_stack_down(t_stacks *stacks, t_stackinfo info);
void		rotate_stack_up(t_stacks *stacks, t_stackinfo info);

int			get_min_index(int *arr, int size);
int			find_target_in_b(int val, int *b, int size_b);
int			find_target_in_a(t_stacks *stacks, int val_b);

void		rotate_to_top(t_stacks *stacks, t_stackinfo info);

void		sort_three(t_stacks *stacks);
void		sort_array(t_stacks *stacks);
void		sort_stacks(t_stacks *stacks);

#endif
