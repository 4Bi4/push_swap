/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 10:54:35 by labia-fe          #+#    #+#             */
/*   Updated: 2024/09/30 17:26:25 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	ptr = malloc(len + 1);
	if (ptr == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
/*
#include <stdio.h>

int main(void)
{
    char    *str = "Hello, World!";
    char    *str2 = "";

    printf("BEFORE:\nOriginal: %s\nCopy: %s\n", str, str2);
    str2 = ft_strdup(str);
    printf("AFTER:\nOriginal: %s\nCopy: %s\n", str, str2);
    free(str2);
    return (0);
}
*/
