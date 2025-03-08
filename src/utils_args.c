/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:59:36 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/05 15:17:59 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	indexer(t_stack *stack)
{
	int 	i;
	int		max;
	t_stack	*first;
	t_stack	*lower;

	i = 0;
	max = ft_lstsize(stack);
	first = stack;
	lower = stack;
	while (i < max)
	{
		stack = first;
		while (stack->index != -1)
			stack = stack->next;
		lower = stack;
		while (stack)
		{
			if (stack->value < lower->value && stack->index == -1)
				lower = stack;
			stack = stack->next;
		}
		lower->index = i;
		i++;
	}
	return ;
}

int	arg_loader(t_stack **stack, char *str, int split)
{
	char		**args;
	int			i;

	i = 0;
	if (split == 1)
	{
		args = ft_split(str, ' ');
		if (!args)
			return (1);
		while (args[i])
		{
			if (ft_atol(args[i]) < INT_MIN || ft_atol(args[i]) > INT_MAX)
				return (1);
			link_node(stack, ft_atoi(args[i]));+
			i++;
		}
		free_matrix(args);
	}
	if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
		return (1);
	link_node(stack, ft_atoi(str));
	return (0);
}

int	str_check(t_stack **stack, char *str)
{
	int	i;
	int	split;

	i = 0;
	split = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			split = 1;
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '+'
			&& str[i] != '-')
			return (write(2, "Error\n", 7), 1);
		if ((str[i] == '+' && !ft_isdigit(str[i + 1])) || (str[i] == '-'
				&& !ft_isdigit(str[i + 1])))
			return (write(2, "Error\n", 7), 1);
		i++;
	}
	if (arg_loader(stack, str, split) != 0)
		return (write(2, "Error\n", 7), 1);
	return (0);
}

int	dup_check(t_stack **stack)
{
	t_stack	*current;
	t_stack	*temp;

	current = *stack;
	while (current)
	{
		temp = current->next;
		while (temp)
		{
			if (current->value == temp->value)
				return (write(2, "Error\n", 7), 1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}
