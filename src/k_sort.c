/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:00:10 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/12 19:58:20 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		ft_sqrroot(int n)
{
	int	i;
	
	i = 0;
	if (n == 0)
		return (0);
	if (n < 0)
		return (-1);
	while (i * i <= n)
		i++;
	return (i - 1);
}

void	first_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	range;

	i = 0;
	range = (ft_sqrroot(list_size(*stack_a)) * 1.4);	// range = sqrroot of total size + 40% of it
	while (*stack_a)
	{
		
		if ((*stack_a)->index <= i)
		{
			push(stack_a, stack_b, 'b');
			*stack_b = rotate(stack_b, 'b');
			i++;
		}
		else if ((*stack_a)->index > i && (*stack_a)->index <= (i + range))
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else
			*stack_a = rotate(stack_a, 'a');
	}
	return ;
}

void	second_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		position;
	int		size;
	t_stack	*biggest;

	size = 0;
	position = 0;
	biggest = NULL;
	while (*stack_b)
	{
		size = list_size(*stack_b);
		biggest = biggest_node(stack_b);
		position = check_position(stack_b, biggest->index);
		if (position <= size / 2)
		{
			while((*stack_b)->index != biggest->index)
				*stack_b = rotate(stack_b, 'b');
		}
		else
		{
			while((*stack_b)->index != biggest->index)
				*stack_b = rev_rotate(stack_b, 'b');
		}
		push(stack_b, stack_a, 'a');
	}
	return ;
}

void	k_sort(t_stack **stack_a, t_stack **stack_b)
{
	first_sort(stack_a, stack_b);
	second_sort(stack_a, stack_b);
	return ;
}
