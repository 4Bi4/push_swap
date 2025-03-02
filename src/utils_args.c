/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:59:36 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/01 17:07:52 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void free_list(t_stack **stack)
{
    t_stack *tmp;

    if (!stack || !*stack)
        return;
    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
    *stack = NULL;
}

int	arg_loader(t_stack **stack, char *str)
{
	static int	index = 1;
	char		**args;
	int			i;

	i = 0;
	args = ft_split(str, ' ');
	if (!args)
		return (1);
	while (args[i])
	{
		link_node(stack, index, ft_atoi(args[i]));
		i++;
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
	if (split = 1)
	{
		if (arg_loader(stack, str) != 0)
			return (1);
	}
	return (0);
}
