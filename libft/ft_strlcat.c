/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:26:03 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/26 19:13:04 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;
	size_t	max;

	i = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	max = size - dstlen - 1;
	if (size <= dstlen)
		return (size + srclen);
	while (i < max && src[i])
	{
		dst[dstlen + i] = src[i];
		i++;
	}
	dst[dstlen + i] = '\0';
	return (dstlen + srclen);
}

// #include <stdio.h>

// int	main(void)
// {
// 	char	a[] = "Hola ";
// 	char	b[] = "Mundo";

// 	printf("before a: %s\n", a);
// 	printf("before b: %s\n", b);
// 	printf("creating a string of size %ld.\n", ft_strlcat(a, b, 40));
// 	printf("after: %s\n", a);
// 	return (0);
// }
