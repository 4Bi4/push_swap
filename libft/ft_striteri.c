/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 12:26:43 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/02 17:00:17 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
static void	f(int i, char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = *c - 32;
}
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
#include <stdio.h>

int main(void)
{
    char c[] = "ABC";
    char c0[] = "margarita";
    char c1[] = "1  3 ,4l Casa 33";

    ft_striteri(c, f);
    ft_striteri(c0, f);
    ft_striteri(c1, f);

    printf("Test 1: %s\n", c);
    printf("Test 2: %s\n", c0);
    printf("Test 3: %s\n", c1);
    return (0);
}
*/
