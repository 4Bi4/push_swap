/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:51:14 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/13 17:02:28 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

//	Creates a new node with the given value
//	\returns
//	a pointer to the new node, NULL if error
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

//	Links a new node with the given value to the end of the list
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

//	Frees the entire list (stack) and sets the pointer to NULL
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

//	Calculates the size of the list (stack)
//	\returns
//	the size of the list, 0 if the list is empty
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

//	Checks if the stack is sorted in ascending order based on index
//	\returns
//	1 if sorted, 0 if not
int	is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (temp && temp->next)
	{
		if (temp->index < temp->next->index)
			temp = temp->next;
		else
			return (0);
	}
	return (1);
}
