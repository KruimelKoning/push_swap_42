/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 16:34:58 by lbartels      #+#    #+#                 */
/*   Updated: 2024/01/31 16:44:19 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ps_lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

t_stack	*ps_lstnew(int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->number = number;
	new->next = NULL;
	return (new);
}

void	ps_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*current;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	current = *lst;
	while (current->next)
	{
		current = current->next;
	}
	current->next = new;
}

int	is_sorted(t_stack **stack_a, t_stack **stack_b)
{
	int		previous;
	t_stack	*head;

	if (*stack_b)
		return (1);
	previous = INT_MIN;
	head = *stack_a;
	while (head)
	{
		if (head->number < previous)
			return (1);
		previous = head->number;
		head = head->next;
	}
	return (0);
}

void	free_stack(t_stack **stack)
{
	t_stack	*head;
	t_stack	*next;

	head = *stack;
	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
	free(stack);
}
