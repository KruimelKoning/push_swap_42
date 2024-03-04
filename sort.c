/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 14:30:14 by lbartels      #+#    #+#                 */
/*   Updated: 2024/01/31 16:40:34 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_length(t_stack **stack)
{
	t_stack	*head;
	int		i;

	head = *stack;
	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*head;
	int		list_length;
	int		i;
	int		j;

	head = *stack_a;
	list_length = get_length(stack_a);
	if (list_length <= 5)
		simple_sort(stack_a, stack_b, list_length);
	i = 0;
	while (is_sorted(stack_a, stack_b) && i < 32)
	{
		j = 0;
		while (j++ < list_length)
		{
			head = *stack_a;
			if (((head->index >> i) & 1) == 1)
				operation(stack_a, stack_b, "ra");
			else if (is_sorted(stack_a, stack_b))
				operation(stack_a, stack_b, "pb");
		}
		while (get_length(stack_b))
			operation(stack_a, stack_b, "pa");
		i++;
	}
}
