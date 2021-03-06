/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 18:20:08 by joluiz-d          #+#    #+#             */
/*   Updated: 2021/11/25 14:18:27 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*	DESCRIPTION
*	Allocates (with malloc(3)) and returns a string representing the
*	integer received as an argument. Negative numbers must be handled.
*
*	RETURN VALUES
*	The string representing the integer. NULL if the allocation fails.
*/

static int	len_n(int n)
{
	int	len;

	len = 0;
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

static char	*converter(int n)
{
	int		len;
	char	*n_str;
	char	signal;

	len = 0;
	signal = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
		signal = 1;
	}
	len += len_n(n);
	n_str = (char *)malloc((len + 1) * sizeof(*n_str));
	if (n_str == NULL)
		return (NULL);
	n_str[len] = '\0';
	if (signal == 1)
		n_str[0] = '-';
	while (n != 0)
	{
		n_str[--len] = n % 10 + '0';
		n /= 10;
	}
	return (n_str);
}

char	*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	return (converter(n));
}
