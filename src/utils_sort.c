/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:06:41 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/10 17:51:18 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

t_stack	*sort_three(t_stack **stack)
{
	t_stack	*biggest;

	biggest = biggest_node(stack);
	if (biggest == *stack)
		*stack = rotate(stack, 'a');
	else if ((*stack)->next == biggest)
		*stack = rev_rotate(stack, 'a');
	if ((*stack)->index > (*stack)->next->index)
		*stack = swap(stack, 'a');
	return (*stack);
}

//t_stack	*sort_four(t_stack **stack_a, t_stack **stack_b)
//{
//	while (list_size(*stack_a) > 3)
//	{
//		if ((*stack_a)->index != 0)
//		{
//			if (detect_index_position(stack_a, 0) <= (list_size(*stack_a) / 2))
//				ra(stack_a, true);
//			else
//				rra(stack_a, true);
//		}
//		if ((*stack_a)->index == 0)
//			pb(stack_b, stack_a, true);
//	}
//	if (!is_sorted(stack_a))
//	{
//		sort_three_node(stack_a);
//	}
//	pa(stack_a, stack_b, true);
//}