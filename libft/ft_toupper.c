/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:57:24 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/03 18:10:02 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c = c - 32;
	return (c);
}

/*
#include <stdio.h>

int	main(void)
{
	int	a = 'd';

	printf("before: %c\n", a);
	printf("after: %c\n", ft_toupper(a));
	return (0);
}
*/
