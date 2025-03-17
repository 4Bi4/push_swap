/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:16:06 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/13 18:11:27 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	len;

	len = list_size(stack_a);
	if (is_sorted(&stack_a) != 0)
	{
		if (len == 2)
			stack_a = swap(&stack_a, 'a');
		else if (len == 3)
			sort_three(&stack_a);
		else if (len == 4)
			sort_four(&stack_a, &stack_b);
		else if (len == 5)
			sort_five(&stack_a, &stack_b);
		else
			k_sort(&stack_a, &stack_b);
	}
	return (stack_a);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (write(2, "Error\n", 7), 1);
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			if (str_check(&stack_a, argv[i]) != 0)
				return (free_list(&stack_a), free_list(&stack_b), 1);
			i++;
		}
		if (dup_check(&stack_a) == 0)
		{
			indexer(stack_a);
			stack_a = push_swap(stack_a, stack_b);
		}
	}
	return (free_list(&stack_a), free_list(&stack_b), 0);
}
