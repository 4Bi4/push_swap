/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:16:06 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/20 17:29:06 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ft_atoi(const char *c)
{
	int	a;
	int	i;
	int	sign;

	i = 0;
	a = 0;
	sign = 1;
	while ((c[i] >= 9 && c[i] <= 13) || c[i] == ' ')
	{
		i++;
	}
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		a = a * 10 + (c[i] - '0');
		i++;
	}
	return (a * sign);
}

t_stack	*create_node(int index, int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return(write(2, "¡[ERROR]! malloc somehow failed 💀\n", 94), -1);
	node->index = index;
	node->value = value;
	node->next = NULL;
	return (node);
}

void	link_node(t_stack **first, int index, int value)
{
	t_stack *new_node;

	new_node = create_node(index, value);
	if (!new_node)
		return ;
	if (!*first)
	
}

void	print_list(t_stack *first)
{
	t_stack *temp;
	
	temp = first;
	while (temp)
	{
		printf("index: %d, value: %d\n", temp->index, temp->value);
		temp = temp->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	test;
	int i = 1;

	(void)argv;
	while (i <= argc)
		link_node(&test, i, ft_atoi(argv[i]));

	return (0);
}