/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   index.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 13:49:41 by lbartels      #+#    #+#                 */
/*   Updated: 2024/01/31 16:38:37 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_lowest(t_stack **stack)
{
	t_stack	*head;
	t_stack	*lowest;
	int		got_lowest;

	head = *stack;
	lowest = NULL;
	got_lowest = 0;
	while (head)
	{
		if (head->index == -1 && (!got_lowest || head->number < lowest->number))
		{
			lowest = head;
			got_lowest = 1;
		}
		head = head->next;
	}
	return (lowest);
}

void	get_index(t_stack	**stack)
{
	t_stack	*head;
	int		index;

	head = get_lowest(stack);
	index = 0;
	while (head)
	{
		head->index = index++;
		head = get_lowest(stack);
	}
}
