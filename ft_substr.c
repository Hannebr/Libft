/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hbrouwer <hbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/11 15:23:35 by hbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/14 20:29:17 by hbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	i;

	if (len > ft_strlen(s))
		len = ft_strlen(s);
	result = (char *) malloc((len + 1) * sizeof(char));
	if (result == 0)
		return (0);
	i = 0;
	while (i < len && (start + i) < ft_strlen(s))
	{
		result[i] = *((char *)s + (start + i));
		i++;
	}
	result[i] = '\0';
	return (result);
}
