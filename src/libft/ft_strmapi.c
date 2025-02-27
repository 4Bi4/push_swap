/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 16:43:04 by labia-fe          #+#    #+#             */
/*   Updated: 2025/02/19 13:59:37 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static char	f(int i, char c)
{
	if ( c >= 'a' && c <= 'z')
		return (c - 32);
	i++;
	return (c);
}
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*result;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	result = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i])
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>

int main(void)
{
    char c[] = "ABC";
    char c0[] = "margarita";
    char c1[] = "1  3 ,4l Casa 33";

	char *a = ft_strmapi(c, f);
	char *a0 = ft_strmapi(c0, f);
	char *a1 = ft_strmapi(c1, f);

    printf("Test 1: %s\n", a);
    printf("Test 2: %s\n", a0);
    printf("Test 3: %s\n", a1);
    return (0);
}
*/
