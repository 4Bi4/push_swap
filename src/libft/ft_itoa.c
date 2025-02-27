/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 15:20:35 by labia-fe          #+#    #+#             */
/*   Updated: 2024/09/30 16:43:56 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nlen(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		num;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	num = n;
	len = ft_nlen(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		num = -num;
	while (len > 0)
	{
		len--;
		str[len] = (num % 10) + '0';
		num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*
#include <stdio.h>

int main(void)
{
    int n = -2147483648;
    int n2 = 2147483647;
    int n3 = -42;
    int n4 = 360;

    printf("%s\n", ft_itoa(n));
    printf("%s\n", ft_itoa(n2));
    printf("%s\n", ft_itoa(n3));
    printf("%s\n", ft_itoa(n4));
    return (0);
}
*/
