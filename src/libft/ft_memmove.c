/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:23:56 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/04 17:08:01 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dst;
	unsigned char	*sc;

	dst = (unsigned char *)dest;
	sc = (unsigned char *)src;
	if (!dst && !src)
		return (NULL);
	if (dest > src)
	{
		while (n--)
			dst[n] = sc[n];
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*
#include <stdio.h>

int	main(void)
{
	char	a[] = "jjjjjjjj";
	char	b[] = "00000000";

	printf("before: %s\n", b);
	printf("after: %s\n", (char *)ft_memmove(b, a, 0));
	return (0);
}
*/
