/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoaf.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoquel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:42:34 by achoquel          #+#    #+#             */
/*   Updated: 2019/01/23 16:42:37 by achoquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fdf.h"

static void	check_neg(int *n, int *neg)
{
	if (*n < 0)
	{
		*n *= -1;
		*neg = 1;
	}
	else
		*neg = 0;
}

char		*itoa_f(int n)
{
	char	*str;
	int		ncpy;
	int		size;
	int		neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	check_neg(&n, &neg);
	ncpy = n;
	size = 2;
	while (ncpy /= 10)
		++size;
	size += neg;
	if ((str = (char*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	str[--size] = 0;
	while (size-- > 0)
	{
		str[size] = n % 10 + '0';
		n /= 10;
	}
	if (neg)
		str[0] = '-';
	free(str);
	return (str);
}
