/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:15:58 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/05 16:12:42 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "../src/libft/libft.h"

typedef struct s_stack
{
	int				index;
	int				value;

	struct s_stack	*next;
}					t_stack;

int		ft_lstsize(t_stack *lst);
int		dup_check(t_stack **stack);
int		str_check(t_stack **stack, char *str);

char	**ft_split(char const *s, char c);

void	indexer(t_stack *stack);
void	free_matrix(char **mtrx);
void 	free_list(t_stack **stack);
void	push(t_stack **src, t_stack **dst);
void	link_node(t_stack **first, int value);

t_stack	*swap(t_stack **stack);
t_stack	*rotate(t_stack **stack);
t_stack	*rev_rotate(t_stack	**stack);

#endif