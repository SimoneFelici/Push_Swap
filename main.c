/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfelici <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 11:50:28 by sfelici           #+#    #+#             */
/*   Updated: 2025/04/05 11:50:31 by sfelici          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
