/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lbartels <lbartels@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/29 13:49:56 by lbartels      #+#    #+#                 */
/*   Updated: 2024/01/31 16:43:19 by lbartels      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>

# include "libft/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*ps_lstnew(int number);
void	ps_lstadd_back(t_stack **lst, t_stack *new);
t_stack	*ps_lstlast(t_stack *lst);
t_stack	**make_list(int argc, char **argv);
void	free_stack(t_stack **stack);

int		is_sorted(t_stack **stack_a, t_stack **stack_b);

void	get_index(t_stack	**stack);

int		get_length(t_stack **stack);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

void	simple_sort(t_stack **stack_a, t_stack **stack_b, int list_length);

void	swap(t_stack **stack);
void	push(t_stack **to, t_stack **from);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);
void	operation(t_stack **stack_a, t_stack **stack_b, char *operation);

#endif