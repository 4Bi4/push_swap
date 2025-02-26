/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:30:14 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/04 15:02:49 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = ft_strlen(s1);
	if (!s1 || !set)
		return (NULL);
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	while (j > i && is_in_set(s1[j - 1], set))
		j--;
	len = j - i;
	ptr = (char *)malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, &s1[i], len + 1);
	ptr[len] = '\0';
	return (ptr);
}

/*
#include <stdio.h>

int main()
{
    char    s1[] = "hello world";
    char    set[] = "held";

    printf("Source:%s\nTarget:%s\n", s1, set);
    printf("Result:%s\n", ft_strtrim(s1, set));
    return (0);
}
*/
