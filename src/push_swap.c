/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:16:06 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/10 14:21:34 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_list(t_stack *first)
{
	t_stack	*temp;

	if (!first)
	{
		write(1, "(null)\n", 8);
		return ;
	}
		temp = first;
	while (temp)
	{
		printf("index: %d, value: %d\n", temp->index, temp->value);
		temp = temp->next;
	}
}

t_stack	*push_swap(t_stack *stack_a, t_stack *stack_b)
{
	int	len;

	(void)stack_b;
	len = list_size(stack_a);
	if (is_sorted(&stack_a) != 0)
	{
		if (len == 2)
			stack_a = swap(&stack_a, 'a');
		else if (len == 3)
			stack_a = sort_three(&stack_a);
		//else if (len == 4)
		//	sort_four(&stack_a, &stack_b);
		//else if (len == 5)
		//	sort_five_node(&stack_a, &stack_b);
		//else
		//	k_sort(&stack_a, &stack_b, len);
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
				return (1);
			i++;
		}
		if (dup_check(&stack_a) == 0)
		{
			indexer(stack_a);
			print_list(stack_a);
			stack_a = push_swap(stack_a, stack_b);
			print_list(stack_a);
		}
	}
	return (free_list(&stack_a), free_list(&stack_b), 0);
}
