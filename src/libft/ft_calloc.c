/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 11:26:55 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/02 12:36:25 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	max;

	max = nmemb * size;
	ptr = malloc(max);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, max);
	return (ptr);
}

/*
#include <stdio.h>

int main(void)
{
    int *arr;
    size_t n = 5;
    size_t i;

	i = 0;
    arr = (int *)ft_calloc(n, sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return (1);
    }

    while (i < n)
    {
        printf("arr[%zu] = %d\n", i, arr[i]);
        i++;
    }

    free(arr);
    return (0);
}
*/
