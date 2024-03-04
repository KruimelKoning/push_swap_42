/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple_sort.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/31 14:49:56 by lbartels      #+#    #+#                 */
/*   Updated: 2024/02/01 18:29:38 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_distance(t_stack **stack_a, int index)
{
	t_stack	*head;
	int		distance;

	head = *stack_a;
	distance = 0;
	while (head)
	{
		if (head->index == index)
			break ;
		distance++;
		head = head->next;
	}
	return (distance);
}

void	sort_three(t_stack **stack_a, int i)
{
	t_stack	*head;

	head = *stack_a;
	if (head->index == (0 + i) && head->next->index == (2 + i))
	{
		operation(stack_a, NULL, "rra");
		operation(stack_a, NULL, "sa");
	}
	else if (head->index == (1 + i) && head->next->index == (2 + i))
		operation(stack_a, NULL, "rra");
	else if (head->index == (1 + i) && head->next->index == (0 + i))
		operation(stack_a, NULL, "sa");
	else if (head->index == (2 + i) && head->next->index == (1 + i))
	{
		operation(stack_a, NULL, "sa");
		operation(stack_a, NULL, "rra");
	}
	else if (head->index == (2 + i) && head->next->index == (0 + i))
	{
		operation(stack_a, NULL, "rra");
		operation(stack_a, NULL, "rra");
	}
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;

	distance = get_distance(stack_a, 0);
	if (distance == 1)
		operation(stack_a, stack_b, "sa");
	if (distance == 2)
	{
		operation(stack_a, stack_b, "rra");
		operation(stack_a, stack_b, "rra");
	}
	if (distance == 3)
		operation(stack_a, stack_b, "rra");
	operation(stack_a, stack_b, "pb");
	sort_three(stack_a, 1);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	distance;
	int	i;

	i = 0;
	while (i < 2)
	{
		distance = get_distance(stack_a, i);
		if (distance == 1)
			operation(stack_a, stack_b, "sa");
		if (distance == 2)
		{
			operation(stack_a, stack_b, "ra");
			operation(stack_a, stack_b, "ra");
		}
		else if ((distance + i) == 3)
		{
			operation(stack_a, stack_b, "rra");
			operation(stack_a, stack_b, "rra");
		}
		else if ((distance + i) == 4)
			operation(stack_a, stack_b, "rra");
		operation(stack_a, stack_b, "pb");
		i++;
	}
	sort_three(stack_a, 2);
}

void	simple_sort(t_stack **stack_a, t_stack **stack_b, int list_length)
{
	if (list_length == 2)
		operation(stack_a, stack_b, "sa");
	else if (list_length == 3)
		sort_three(stack_a, 0);
	else if (list_length == 4)
	{
		sort_four(stack_a, stack_b);
		operation(stack_a, stack_b, "pa");
	}
	else if (list_length == 5)
	{
		sort_five(stack_a, stack_b);
		operation(stack_a, stack_b, "pa");
		operation(stack_a, stack_b, "pa");
	}
}
