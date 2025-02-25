/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 14:59:36 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/25 20:06:31 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	arg_loader(t_stack **stack, char *str)
{
	char	**args;
	int		i;

	i = 0;
	args = ft_split(str, ' ');
	if (!args)
		return (1);
	while (args[i])
	{
		link_node(stack, i + 1, ft_atoi(args[i]));
		i++;
	}
	return (0);
}

int	str_check(t_stack **stack, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && str[i] != ' ' && str[i] != '+' && str[i] != '-')
			return (write(2, "Error\n", 7), 1);
		i++;
	}
	if (arg_loader(stack, str) != 0)
		return (1);
	return (0);
}
