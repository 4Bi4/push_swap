/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:15:58 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/04 18:56:30 by labia-fe         ###   ########.fr       */
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

int		dup_check(t_stack **stack);
int		str_check(t_stack **stack, char *str);

char	**ft_split(char const *s, char c);

void	free_matrix(char **mtrx);
void 	free_list(t_stack **stack);
void	link_node(t_stack **first, int value);

t_stack	*swap(t_stack **stack);

#endif