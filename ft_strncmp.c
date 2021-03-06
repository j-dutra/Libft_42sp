/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:00:56 by joluiz-d          #+#    #+#             */
/*   Updated: 2021/11/25 14:04:41 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
*	DESCRIPTION
*	The strncmp() function lexicographically compare the null-terminated
*	strings s1 and s2.
*
*	The strncmp() function compares not more than n characters.  Because
*	strncmp() is designed for comparing strings rather than binary data,
*	characters that appear after a `\0' character are not compared.
*
*	RETURN VALUES
*	The strncmp() function return an integer greater than, equal to, or
*	less than 0, according as the string s1 is greater than, equal to, or
*	less than the string s2.  The comparison is done using unsigned
*	characters, so that `\200' is greater than `\0'.
*/

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 && *s2) != '\0' && n > 0)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
		n--;
	}
	if (n == 0)
		return (0);
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
