/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:06:41 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/10 21:59:12 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//	Returns the position of the node with the given index in the stack
//	\returns
//	the position (int) if found, -1 if not found
int	check_position(t_stack **stack, int index)
{
	int		i;
	t_stack	*temp;

	i = 1;
	temp = *stack;
	while (temp && temp->index != index)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

//	Returns a pointer to the node with the biggest index in the stack
//	\returns
//	a pointer to the node with the biggest index, NULL if stack is empty
t_stack	*biggest_node(t_stack **stack)
{
	t_stack	*biggest;
	t_stack	*temp;

	temp = *stack;
	biggest = temp;
	while (temp)
	{
		if (temp->index > biggest->index)
			biggest = temp;
		temp = temp->next;
	}
	return (biggest);
}

//	Sorts a stack of three elements
void	sort_three(t_stack **stack)
{
	t_stack	*biggest;

	biggest = biggest_node(stack);
	if (biggest == *stack)
		*stack = rotate(stack, 'a', 1);
	else if ((*stack)->next == biggest)
		*stack = rev_rotate(stack, 'a', 1);
	if ((*stack)->index > (*stack)->next->index)
		*stack = swap(stack, 'a', 1);
}

//	Sorts a stack of four elements
void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	while (list_size(*stack_a) > 3)
	{
		if ((*stack_a)->index != 0)
		{
			if (check_position(stack_a, 0) <= (list_size(*stack_a) / 2))
				*stack_a = rotate(stack_a, 'a', 1);
			else
				*stack_a = rev_rotate(stack_a, 'a', 1);
		}
		if ((*stack_a)->index == 0)
			push(stack_a, stack_b, 'b', 1);
	}
	if (!is_sorted(stack_a))
		sort_three(stack_a);
	push(stack_b, stack_a, 'a', 1);
}

//	Sorts a stack of five elements
void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	target;

	target = 0;
	while (target < 2)
	{
		while ((*stack_a)->index != target)
		{
			if (check_position(stack_a, target) <= list_size(*stack_a) / 2)
				*stack_a = rotate(stack_a, 'a', 1);
			else
				*stack_a = rev_rotate(stack_a, 'a', 1);
		}
		push(stack_a, stack_b, 'b', 1);
		target++;
	}
	if (!is_sorted(stack_a))
		sort_three(stack_a);
	if ((*stack_b)->next && (*stack_b)->index < (*stack_b)->next->index)
		*stack_b = swap(stack_b, 'b', 1);
	push(stack_b, stack_a, 'a', 1);
	push(stack_b, stack_a, 'a', 1);
}
