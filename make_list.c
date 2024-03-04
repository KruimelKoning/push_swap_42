/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_list.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 13:49:50 by lbartels      #+#    #+#                 */
/*   Updated: 2024/02/01 17:41:16 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(char *str)
{
	long	num;
	int		i;
	long	min;

	num = 0;
	i = 0;
	min = 1;
	if (ft_strlen(str) > 11)
		return (1);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			min = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	num = num * min;
	if (num > INT_MAX || num < INT_MIN)
		return (1);
	return (0);
}

int	check_duplicates(char **argv)
{
	int		i;
	int		j;

	i = 0;
	while (argv[i])
	{
		j = i + 1;
		while (argv[j])
		{
			if (!strncmp(argv[i], argv[j], ft_strlen(argv[i]) + 1))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_argv(char **argv)
{
	int	i;
	int	j;
	int	ret;

	i = 0;
	while (argv[i])
	{
		j = 0;
		if (!argv[i][0])
			return (-1);
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j])
				&& !(((argv[i][j] == '-' || argv[i][j] == '+') && !j)))
				return (-1);
			j++;
		}
		if (ft_atol(argv[i]))
			return (-1);
		i++;
	}
	if (check_duplicates(argv))
		return (-1);
	return (0);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

t_stack	**make_list(int argc, char **argv)
{
	t_stack	**stack;
	t_stack	*new;
	char	**args;
	int		i;
	int		number;

	args = &argv[1];
	if (check_argv(args) == -1)
		return (NULL);
	stack = ft_calloc(1, sizeof(t_stack *));
	i = 0;
	while (args[i])
	{
		number = ft_atoi(args[i]);
		new = ps_lstnew(number);
		new->index = -1;
		ps_lstadd_back(stack, new);
		i++;
	}
	return (stack);
}
