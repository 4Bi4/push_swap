/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:16:06 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/05 16:13:03 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (write(2, "Error\n", 7), NULL);
	node->index = -1;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	link_node(t_stack **first, int value)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = create_node(value);
	if (!new_node)
		return ;
	if (!*first)
		*first = new_node;
	else
	{
		temp = *first;
		while (temp->next)
			temp = temp->next;
		temp->next = new_node;
	}
}

void	print_list(t_stack *first)
{
	t_stack	*temp;

	temp = first;
	while (temp)
	{
		printf("index: %d, value: %d\n", temp->index, temp->value);
		temp = temp->next;
	}
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
			write(1, "\n", 1);
			indexer(stack_a);
			print_list(stack_a);
			write(1, "\n ---------------- \n     SWAPPING\n ---------------- \n\n", 54);
			stack_a = swap(&stack_a);
			print_list(stack_a);
			write(1, "\n ----------------- \n    GET ROTATED\n ----------------- \n\n", 58);
			stack_a = rotate(&stack_a);
			print_list(stack_a);
			write(1, "\n ----------------- \n  GET REV_ROTATED\n ----------------- \n\n", 60);
			stack_a = rev_rotate(&stack_a);
			print_list(stack_a);
			write(1, "\n ----------------- \n     PUSH TO B\n ----------------- \n\n", 57);
			push(&stack_a, &stack_b);
			write(1, "\n     [STACK A]\n\n", 17);
			print_list(stack_a);
			write(1, "\n     [STACK B]\n\n", 17);
			print_list(stack_b);
		}
		free_list(&stack_a);
		free_list(&stack_b);
	}
	return (write(1, "\n", 1), 0);
}
