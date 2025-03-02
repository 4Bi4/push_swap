/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:16:06 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/02 20:03:27 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*create_node(int index, int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (write(2, "Error\n", 7), NULL);
	node->index = index;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	link_node(t_stack **first, int index, int value)
{
	t_stack	*new_node;
	t_stack	*temp;

	new_node = create_node(index, value);
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
	t_stack	*test;
	char	**a;
	int		i;

	test = NULL;
	if (argc < 2)
		return (write(2, "Error\n", 7), 1);
	if (argc >= 2)
	{
		i = 1;
		while (i < argc)
		{
			if (str_check(&test, argv[i]) != 0)
				return (1);
			i++;
		}
		if (dup_check(&test) == 0)
			print_list(test);
		free_list(&test);
	}
	return (0);
}
