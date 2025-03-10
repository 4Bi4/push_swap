/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:51:14 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/10 19:33:32 by labia-fe         ###   ########.fr       */
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


void	free_list(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !*stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
	*stack = NULL;
}

int	list_size(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int		is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->index < temp->next->index)
			temp = temp->next;
		else
			return (1);
	}
	return (0);
}
