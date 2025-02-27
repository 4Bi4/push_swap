/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:29:42 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/03 19:31:30 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*subj;
	unsigned char		target;

	subj = (unsigned char *)s;
	target = (unsigned char)c;
	while (n > 0)
	{
		if (*subj == target)
			return ((void *)subj);
		n--;
		subj++;
	}
	return (NULL);
}

/*
#include <stdio.h>

int	main(void)
{
	char	a[] = "when i was, a young boy";

	printf("before: %s\n", a);
	printf("after: %s\n", (char *)ft_memchr(a, 's', 3));
	return (0);
}
*/
