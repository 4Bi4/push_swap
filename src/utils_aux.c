/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_aux.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 16:51:14 by labia-fe          #+#    #+#             */
/*   Updated: 2025/03/04 16:53:33 by labia-fe         ###   ########.fr       */
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
