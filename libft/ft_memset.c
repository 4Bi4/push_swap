/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 10:23:27 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/02 17:54:40 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*dst;

	dst = (unsigned char *)s;
	while (n > 0)
	{
		*dst = (unsigned char)c;
		dst++;
		n--;
	}
	return (s);
}

/*
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char a[] = "hola";

	printf("before: %s\n", a);
	printf("after: %s\n", (char *)ft_memset(a, NULL, 33));
	printf("expected: %s\n", (char *)memset(a, NULL, 33));
	return (0);
}
*/
