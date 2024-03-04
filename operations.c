/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 13:49:52 by lbartels      #+#    #+#                 */
/*   Updated: 2024/02/01 18:31:22 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*node;
	t_stack	*next;

	node = *stack;
	next = node->next;
	if (!node || !next)
		return ;
	node->next = next->next;
	next->next = node;
	*stack = next;
}

void	push(t_stack **to, t_stack **from)
{
	t_stack	*temp;

	temp = *from;
	if (!temp)
		return ;
	*from = temp->next;
	temp->next = *to;
	*to = temp;
}

void	rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	head = *stack;
	last = ps_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*head;
	t_stack	*last;

	head = *stack;
	last = ps_lstlast(head);
	while (head)
	{
		if (!head->next->next)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	last->next = *stack;
	*stack = last;
}

void	operation(t_stack **stack_a, t_stack **stack_b, char *operation)
{
	if (!strncmp("sa", operation, 2) || !strncmp("ss", operation, 2))
		swap(stack_a);
	else if (!strncmp("sb", operation, 2) || !strncmp("ss", operation, 2))
		swap(stack_b);
	else if (!strncmp("pa", operation, 2))
		push(stack_a, stack_b);
	else if (!strncmp("pb", operation, 2))
		push(stack_b, stack_a);
	else if (!strncmp("ra", operation, 2) || !strncmp("rr", operation, 3))
		rotate(stack_a);
	else if (!strncmp("rb", operation, 2) || !strncmp("rr", operation, 3))
		rotate(stack_b);
	else if (!strncmp("rra", operation, 3) || !strncmp("rrr", operation, 3))
		reverse_rotate(stack_a);
	else if (!strncmp("rrb", operation, 3) || !strncmp("rrr", operation, 3))
		reverse_rotate(stack_b);
	ft_printf("%s\n", operation);
}
