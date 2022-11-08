/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiastow <jpiastow@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:01:08 by jpiastow          #+#    #+#             */
/*   Updated: 2022/10/19 13:22:07 by jpiastow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;

	i = 0;
	string = (unsigned char *) s;
	while (i < n)
	{
		if ((unsigned char)c == string[i])
			return (&string[i]);
		i++;
	}
	return (NULL);
}
