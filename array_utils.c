#include "push_swap.h"

int	is_sorted(int *array, int size)
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

bool	fill_and_check_numbers(int size, char **numbers, int *temp)
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
