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

int	ft_atoi(const char *c)
{
	int	a;
	int	i;
	int	sign;

	i = 0;
	a = 0;
	sign = 1;
	while ((c[i] >= 9 && c[i] <= 13) || c[i] == ' ')
	{
		i++;
	}
	if (c[i] == '-' || c[i] == '+')
	{
		if (c[i] == '-')
		{
			sign = -sign;
		}
		i++;
	}
	while (c[i] >= '0' && c[i] <= '9')
	{
		a = a * 10 + (c[i] - '0');
		i++;
	}
	return (a * sign);
}

/*
#include <stdio.h>

int main(int argc, char **argv)
{
    int r;

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
