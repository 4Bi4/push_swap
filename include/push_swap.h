/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:15:58 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/27 16:17:39 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "../src/libft/libft.h"

typedef struct s_stack
{
	int				index;
	int				value;

	struct s_stack	*next;
}					t_stack;

int		str_check(t_stack **stack, char *str);

char	**ft_split(char const *s, char c);

void	link_node(t_stack **first, int index, int value);

#endif