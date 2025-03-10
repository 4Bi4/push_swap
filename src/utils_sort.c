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

void	sort_three(t_stack **stack)
{
	t_stack	*biggest;

	biggest = biggest_node(stack);
	if (biggest == *stack)
		*stack = rotate(stack, 'a');
	else if ((*stack)->next == biggest)
		*stack = rev_rotate(stack, 'a');
	if ((*stack)->index > (*stack)->next->index)
		*stack = swap(stack, 'a');
}

void	sort_four(t_stack **stack_a, t_stack **stack_b)
{
	while (list_size(*stack_a) > 3)
	{
		if ((*stack_a)->index != 0)
		{
			if (check_position(stack_a, 0) <= (list_size(*stack_a) / 2))
				*stack_a = rotate(stack_a, 'a');
			else
				*stack_a = rev_rotate(stack_a, 'a');
		}
		if ((*stack_a)->index == 0)
			push(stack_a, stack_b, 'b');
	}
	if (is_sorted(stack_a) != 0)
	{
		sort_three(stack_a);
	}
	push(stack_b, stack_a, 'a');
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	target;

	target = 0;
	while (target < 2)
	{
		if ((*stack_a)->index != target)
		{
			while ((*stack_a)->index != target)
			{
				if (check_position(stack_a, target) <= list_size(*stack_a) / 2)
					*stack_a = rotate(stack_a, 'a');
				else
					*stack_a = rev_rotate(stack_a, 'a');
			}
			push(stack_a, stack_b, 'b');
		}
		target++;
	}
	if (is_sorted(stack_a) != 0)
		sort_three(stack_a);
	if ((*stack_b)->next && (*stack_b)->index < (*stack_b)->next->index)
		*stack_b = swap(stack_b, 'b');
	push(stack_b, stack_a, 'a');
	push(stack_b, stack_a, 'a');
}
