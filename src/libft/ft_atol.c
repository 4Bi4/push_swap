/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: labia-fe <labia-fe@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 13:25:54 by labia-fe          #+#    #+#             */
/*   Updated: 2024/10/10 11:30:51 by labia-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	parse_digits(const char *c, int start, int sign)
{
	long int	a;
	long int	digit;
	int			i;

	a = 0;
	i = start;
	while (c[i] >= '0' && c[i] <= '9')
	{
		digit = c[i] - '0';
		if (a > LLONG_MAX / 10 || (a == LLONG_MAX / 10 && digit > 7))
		{
			if (sign == 1)
				return (LLONG_MAX);
			else
				return (LLONG_MIN);
		}
		a = a * 10 + digit;
		i++;
	}
	return (a * sign);
}

long int	ft_atol(const char *c)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	while ((c[i] >= 9 && c[i] <= 13) || c[i] == ' ')
		i++;
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i] == '-')
			sign = -1;
		i++;
	}
	return (parse_digits(c, i, sign));
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	r;

	if (argc < 2)
	{
		printf("Argument error, not enough arguments.\nInsert arguments");
		return (1);
	}
	r = ft_atoi(argv[1]);
	printf("Atoieame esta: %d", r);
	return (r);
}
*/
