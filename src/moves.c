/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:32:25 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/09 17:35:19 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*swap(t_stack **stack)
{
	t_stack	*swap;
	t_stack *first;

	first = *stack;
	if (first->next)
	{
		swap = first->next;
		first->next = swap->next;
		swap->next = first;
		first = swap;
	}
	return (first);
}

t_stack	*rotate(t_stack **stack)
{
	t_stack	*swap;
	t_stack	*first;

	first = *stack;
	swap = first;
	while (swap->next)
		swap = swap->next;
	swap->next = first;
	swap = first->next;
	first->next = NULL;
	return (swap);
}

t_stack	*rev_rotate(t_stack	**stack)
{
	t_stack	*swap;
	t_stack	*temp;
	t_stack	*first;

	first = *stack;
	swap = first;
	temp = first;
	while (swap->next)
		swap = swap->next;
	while (temp->next && temp->next != swap)
		temp = temp->next;
	swap->next = first;
	temp->next = NULL;
	return (swap);
}

void	push(t_stack **src, t_stack **dst)
{
	t_stack	*first_src;
	t_stack	*first_dst;
	t_stack	*swap;

	first_src = *src;
	first_dst = *dst;
	swap = first_src;
	*src = first_src->next;
	swap->next = first_dst;
	*dst = swap;
}
