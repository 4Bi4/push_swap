/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:32:25 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/04 18:20:28 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*swap(t_stack **stack)
{
	int		swap;
	t_stack *first;

	first = *stack;
	swap = first->value;
	first->value = first->next->value;
	first->next->value = swap;
	return (first);
}