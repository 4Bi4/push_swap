/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:15:58 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/13 17:01:26 by labia-fe         ###   ########.fr       */
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

//		[SORTING FUNCTIONS]
void	sort_three(t_stack **stack);
void	k_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_four(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack **stack_a, t_stack **stack_b);

//		[CHECKER FUNCTIONS]
int		list_size(t_stack *lst);
int		is_sorted(t_stack **stack);
int		dup_check(t_stack **stack);
t_stack	*biggest_node(t_stack **stack);
int		str_check(t_stack **stack, char *str);
int		check_position(t_stack **stack, int index);

//		[CREATING FUNCTIONS]
t_stack	*create_node(int value);
void	link_node(t_stack **first, int value);

//		[AUXILIARY FUNCTIONS]
void	indexer(t_stack *stack);
void	free_matrix(char **mtrx);
void	free_list(t_stack **stack);
char	**ft_split(char const *s, char c);

void	print_list(t_stack *first);

//		[MOVEMENT FUNCTIONS]
t_stack	*swap(t_stack **stack, char id);
t_stack	*rotate(t_stack **stack, char id);
t_stack	*rev_rotate(t_stack	**stack, char id);
void	push(t_stack **src, t_stack **dst, char id);

#endif