/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:51:14 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/04 20:42:41 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	free_matrix(char **mtrx)
{
	int i;

	i = 0;
	while (mtrx[i])
	{
		free(mtrx[i]);
		mtrx[i] = NULL;
		i++;
	}
	if (mtrx)
		free(mtrx);
	mtrx = NULL;
	return ;
}

int	ft_lstsize(t_stack *lst)
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
