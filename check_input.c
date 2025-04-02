#include "push_swap.h"

bool	is_valid_number(const char *arg)
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

bool	check_sign_and_zero(const char *arg, int *sign, int *i)
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

long long	ps_atol_no_sign(const char *str)
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
