/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 16:39:38 by lbartels      #+#    #+#                 */
/*   Updated: 2024/02/01 16:34:27 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_operation(t_stack **stack_a, t_stack **stack_b)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		if (!strncmp("sa", operation, 2) || !strncmp("ss", operation, 2))
			swap(stack_a);
		else if (!strncmp("sb", operation, 2) || !strncmp("ss", operation, 2))
			swap(stack_b);
		else if (!strncmp("pa", operation, 2))
			push(stack_a, stack_b);
		else if (!strncmp("pb", operation, 2))
			push(stack_b, stack_a);
		else if (!strncmp("rra", operation, 3) || !strncmp("rrr", operation, 3))
			reverse_rotate(stack_a);
		else if (!strncmp("rrb", operation, 3) || !strncmp("rrr", operation, 3))
			reverse_rotate(stack_b);
		else if (!strncmp("ra", operation, 2) || !strncmp("rr", operation, 2))
			rotate(stack_a);
		else if (!strncmp("rb", operation, 2) || !strncmp("rr", operation, 2))
			rotate(stack_b);
		operation = get_next_line(0);
	}
	free(operation);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	char	*line;

	stack_b = (t_stack **)ft_calloc(1, sizeof(t_stack *));
	*stack_b = NULL;
	stack_a = make_list(argc, argv);
	if (!stack_a)
	{
		free_stack(stack_b);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	do_operation(stack_a, stack_b);
	if (!is_sorted(stack_a, stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
