/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:57:32 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/04 13:09:35 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	srclen;

	srclen = ft_strlen(s);
	if (!s)
		return (NULL);
	if (srclen < start)
		return (ft_strdup(""));
	if (start + len > srclen)
		len = srclen - start;
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s + start, len + 1);
	return (ptr);
}

/*
#include <stdio.h>

int	main(void)
{
	const char	*a = "lorem ipsum dolor sit amet";
	int			start = 7;
	int			len = 3;

	printf("Before: %s\n", a);
	printf("After: %s\n", ft_substr(a, start, len));
	return (0);
}
*/