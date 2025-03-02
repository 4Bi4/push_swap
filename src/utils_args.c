/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:59:36 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/02 20:02:21 by labia-fe         ###   ########.fr       */
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

int	arg_loader(t_stack **stack, char *str, int split)
{
	static int	index = 1;
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
			link_node(stack, index, ft_atoi(args[i]));
			i++;
			index++;
		}
	}
	else
	{
		link_node(stack, index, ft_atoi(str));
		index++;
	}
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
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ' && str[i] != '+'
			&& str[i] != '-')
			return (write(2, "Error\n", 7), 1);
		i++;
	}
	if (arg_loader(stack, str, split) != 0)
		return (1);
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
				return(write(2, "Error\n", 7), 1);
			temp = temp->next;
		}
		current = current->next;
	}
	return (0);
}
