#include "push_swap.h"

void	silent_sa(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_a >= 2)
	{
		temp = stacks->a[0];
		stacks->a[0] = stacks->a[1];
		stacks->a[1] = temp;
	}
}

void	silent_sb(t_stacks *stacks)
{
	int	temp;

	if (stacks->size_b >= 2)
	{
		temp = stacks->b[0];
		stacks->b[0] = stacks->b[1];
		stacks->b[1] = temp;
	}
}

void	sa(t_stacks *stacks)
{
	(void)stacks->b;
	(void)stacks->size_b;
	silent_sa(stacks);
	ft_printf("sa\n");
}

void	sb(t_stacks *stacks)
{
	(void)stacks->a;
	(void)stacks->size_a;
	silent_sb(stacks);
	ft_printf("sb\n");
}

void	ss(t_stacks *stacks)
{
	if (stacks->size_a >= 2 && stacks->size_b >= 2)
	{
		silent_sa(stacks);
		silent_sb(stacks);
		ft_printf("ss\n");
	}
}

void	silent_ra(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_a > 1)
	{
		temp = stacks->a[0];
		i = 0;
		while (i < stacks->size_a - 1)
		{
			stacks->a[i] = stacks->a[i + 1];
			i++;
		}
		stacks->a[stacks->size_a - 1] = temp;
	}
}

void	silent_rb(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_b > 1)
	{
		temp = stacks->b[0];
		i = 0;
		while (i < stacks->size_b - 1)
		{
			stacks->b[i] = stacks->b[i + 1];
			i++;
		}
		stacks->b[stacks->size_b - 1] = temp;
	}
}

void	silent_rra(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_a > 1)
	{
		temp = stacks->a[stacks->size_a - 1];
		i = stacks->size_a - 1;
		while (i > 0)
		{
			stacks->a[i] = stacks->a[i - 1];
			i--;
		}
		stacks->a[0] = temp;
	}
}

void	silent_rrb(t_stacks *stacks)
{
	int	temp;
	int	i;

	if (stacks->size_b > 1)
	{
		temp = stacks->b[stacks->size_b - 1];
		i = stacks->size_b - 1;
		while (i > 0)
		{
			stacks->b[i] = stacks->b[i - 1];
			i--;
		}
		stacks->b[0] = temp;
	}
}

void	ra(t_stacks *stacks)
{
	(void)stacks->b;
	(void)stacks->size_b;
	silent_ra(stacks);
	ft_printf("ra\n");
}

void	rb(t_stacks *stacks)
{
	(void)stacks->a;
	(void)stacks->size_a;
	silent_rb(stacks);
	ft_printf("rb\n");
}

void	rra(t_stacks *stacks)
{
	(void)stacks->b;
	(void)stacks->size_b;
	silent_rra(stacks);
	ft_printf("rra\n");
}

void	rrb(t_stacks *stacks)
{
	(void)stacks->a;
	(void)stacks->size_a;
	silent_rrb(stacks);
	ft_printf("rrb\n");
}

void	rr(t_stacks *stacks)
{
	silent_ra(stacks);
	silent_rb(stacks);
	ft_printf("rr\n");
}

void	rrr(t_stacks *stacks)
{
	silent_rra(stacks);
	silent_rrb(stacks);
	ft_printf("rrr\n");
}

void	pb(t_stacks *stacks)
{
	int	i;

	if (stacks->size_a > 0)
	{
		i = stacks->size_b;
		while (i > 0)
		{
			stacks->b[i] = stacks->b[i - 1];
			i--;
		}
		stacks->b[0] = stacks->a[0];
		i = 0;
		while (i < stacks->size_a - 1)
		{
			stacks->a[i] = stacks->a[i + 1];
			i++;
		}
		stacks->size_a--;
		stacks->size_b++;
		ft_printf("pb\n");
	}
}

void	pa(t_stacks *stacks)
{
	int	i;

	if (stacks->size_b > 0)
	{
		i = stacks->size_a;
		while (i > 0)
		{
			stacks->a[i] = stacks->a[i - 1];
			i--;
		}
		stacks->a[0] = stacks->b[0];
		i = 0;
		while (i < stacks->size_b - 1)
		{
			stacks->b[i] = stacks->b[i + 1];
			i++;
		}
		stacks->size_a++;
		stacks->size_b--;
		ft_printf("pa\n");
	}
}

static long long	ps_atol_no_sign(const char *str)
{
	long long	res;
	int			i;

	res = 0;
	i = 0;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (res);
}

static bool	is_all_digits(const char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

static bool	check_sign_and_zero(const char *arg, int *sign, int *i)
{
	*sign = 1;
	*i = 0;
	if (arg[*i] == '-' || arg[*i] == '+')
	{
		if (!arg[*i + 1])
			return (false);
		if (arg[*i + 1] == '0')
			return (false);
		if (arg[*i] == '-')
			*sign = -1;
		(*i)++;
	}
	else if (arg[*i] == '0' && arg[*i + 1] != '\0')
		return (false);
	return (true);
}

static bool	is_valid_number(const char *arg)
{
	long long	num;
	int			sign;
	int			i;

	if (!arg || !*arg)
		return (false);
	if (!check_sign_and_zero(arg, &sign, &i))
		return (false);
	if (!is_all_digits(&arg[i]))
		return (false);
	num = ps_atol_no_sign(&arg[i]) * sign;
	if (num < (long long)INT_MIN || num > (long long)INT_MAX)
		return (false);
	return (true);
}

int	has_duplicates(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static bool	fill_and_check_numbers(int size, char **numbers, int *temp)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (!is_valid_number(numbers[i]))
			return (false);
		temp[i] = ft_atoi(numbers[i]);
		i++;
	}
	return (true);
}

int	check_errors(int size, char **numbers)
{
	int	*temp;

	if (size == 0)
		return (1);
	temp = (int *)malloc(sizeof(int) * size);
	if (!temp)
		return (1);
	if (!fill_and_check_numbers(size, numbers, temp))
	{
		free(temp);
		return (1);
	}
	if (has_duplicates(temp, size))
	{
		free(temp);
		return (1);
	}
	free(temp);
	return (0);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	fill_array(int *array, char **argv, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = ft_atoi(argv[i]);
		i++;
	}
}

static int	is_sorted(int *array, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (array[i] > array[i + 1])
			return (0);
		i++;
	}
	return (1);
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

static void	rotate_stack_up(t_stacks *stacks, t_stackinfo info)
{
	while (info.idx-- > 0)
	{
		if (info.name == 'a')
			ra(stacks);
		else
			rb(stacks);
	}
}

static void	rotate_stack_down(t_stacks *stacks, t_stackinfo info)
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

static void	push_first_two(t_stacks *stacks)
{
	pb(stacks);
	pb(stacks);
}

static int	find_target_in_a(t_stacks *stacks, int val_b)
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

static void	push_one_b_to_a(t_stacks *stacks)
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

static void	push_back_b(t_stacks *stacks)
{
	while (stacks->size_b > 0)
		push_one_b_to_a(stacks);
}

static int	calc_total_cost(t_stacks *stacks, int i, int target_idx)
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

static void	find_best_move(t_stacks *stacks, int *best_idx, int *best_target)
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

static void	sort_big_loop(t_stacks *stacks)
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
		rotate_to_top(stacks, info_a);
		info_b.stack = stacks->b;
		info_b.size = stacks->size_b;
		info_b.idx = best_target;
		info_b.name = 'b';
		rotate_to_top(stacks, info_b);
		pb(stacks);
	}
}

static void	final_rotation(t_stacks *stacks)
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

void	sort_stacks(t_stacks *stacks)
{
	push_first_two(stacks);
	sort_big_loop(stacks);
	sort_three(stacks);
	push_back_b(stacks);
	final_rotation(stacks);
}

static bool	allocate_b(t_stacks *stacks)
{
	int	*temp_b;

	temp_b = (int *)malloc(sizeof(int) * stacks->size_a);
	if (!temp_b)
		return (false);
	stacks->b = temp_b;
	stacks->size_b = 0;
	return (true);
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

static char	**parse_args(int argc, char **argv, t_stacks *stacks)
{
	char	**numbers;

	if (argc == 2)
	{
		numbers = ft_split(argv[1], ' ');
		stacks->size_a = 0;
		while (numbers[stacks->size_a])
			stacks->size_a++;
	}
	else
	{
		numbers = &argv[1];
		stacks->size_a = argc - 1;
	}
	return (numbers);
}

static bool	handle_errors_and_alloc(int argc, char **numbers, t_stacks *stacks)
{
	if (check_errors(stacks->size_a, numbers))
	{
		ft_putstr_fd("Error\n", 2);
		if (argc == 2)
			free_split(numbers);
		return (true);
	}
	stacks->a = (int *)malloc(sizeof(int) * stacks->size_a);
	if (!stacks->a)
		return (true);
	return (false);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**numbers;

	if (argc < 2)
		return (1);
	numbers = parse_args(argc, argv, &stacks);
	if (handle_errors_and_alloc(argc, numbers, &stacks))
		return (1);
	fill_array(stacks.a, numbers, stacks.size_a);
	sort_array(&stacks);
	if (argc == 2)
		free_split(numbers);
	free(stacks.a);
	return (0);
}
