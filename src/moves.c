/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:32:25 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/13 17:08:16 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//	Pushes the top element of src stack to dst stack
void	push(t_stack **src, t_stack **dst, char id, int print)
{
	t_stack	*first_src;
	t_stack	*first_dst;
	t_stack	*swap;

	if (!src || !*src)
		return ;
	first_src = *src;
	first_dst = *dst;
	swap = first_src;
	*src = first_src->next;
	swap->next = first_dst;
	*dst = swap;
	if (print)
	{
		if (id == 'a')
			write(1, "pa\n", 3);
		else
			write(1, "pb\n", 3);
	}
}

//	Swaps the first two elements of the stack
//	\returns
//	a pointer to the new first element of the stack
t_stack	*swap(t_stack **stack, char id, int print)
{
	t_stack	*first;
	t_stack	*swap;

	if (!stack || !*stack || !(*stack)->next)
		return (*stack);
	first = *stack;
	if (first->next)
	{
		swap = first->next;
		first->next = swap->next;
		swap->next = first;
		first = swap;
	}
	if (print)
	{
		if (id == 'a')
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
	return (first);
}

//	Rotates the stack by moving the first element to the last position
//	\returns
//	a pointer to the new first element of the stack
t_stack	*rotate(t_stack **stack, char id, int print)
{
	t_stack	*swap;
	t_stack	*first;

	if (!stack || !*stack || !(*stack)->next)
		return (*stack);
	first = *stack;
	swap = first;
	while (swap->next)
		swap = swap->next;
	swap->next = first;
	swap = first->next;
	first->next = NULL;
	if (print)
	{
		if (id == 'a')
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
	return (swap);
}

//	Reverse rotates the stack by moving the last element to the first position
//	\returns
//	a pointer to the new first element of the stack
t_stack	*rev_rotate(t_stack	**stack, char id, int print)
{
	t_stack	*swap;
	t_stack	*temp;
	t_stack	*first;

	if (!stack || !*stack || !(*stack)->next)
		return (*stack);
	first = *stack;
	swap = first;
	temp = first;
	while (swap->next)
		swap = swap->next;
	while (temp->next && temp->next != swap)
		temp = temp->next;
	swap->next = first;
	temp->next = NULL;
	if (print)
	{
		if (id == 'a')
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
	return (swap);
}
