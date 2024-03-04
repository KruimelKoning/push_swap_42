/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 13:49:47 by lbartels      #+#    #+#                 */
/*   Updated: 2024/02/01 17:12:43 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_b = (t_stack **)ft_calloc(1, sizeof(t_stack *));
	*stack_b = NULL;
	stack_a = make_list(argc, argv);
	if (!stack_a)
	{
		free_stack(stack_b);
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	get_index(stack_a);
	if (!is_sorted(stack_a, stack_b))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	radix_sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
