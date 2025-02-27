/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:29:57 by labia-fe          #+#    #+#             */
/*   Updated: 2024/09/30 15:19:31 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dst;

	dst = s;
	while (n > 0)
	{
		*dst = 0;
		dst++;
		n--;
	}
	return ;
}

/*
#include <stdio.h>

int	main(void)
{
	char	a[] = "agachate y conoselo";

	printf("Before: %s\n", a);
	ft_bzero(a, 5);
	printf("After: %s\n", a);
	return (0);
}
*/
