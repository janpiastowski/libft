/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiastow <jpiastow@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 15:43:57 by jpiastow          #+#    #+#             */
/*   Updated: 2022/10/19 15:55:52 by jpiastow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1len;
	int		s2len;
	int		i;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	result = (char *) malloc((s1len + s2len + 2) * sizeof(char));
	if (!result)
		return (NULL);
	while (i < s1len + 1)
	{
		result[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2len + 1)
	{
		result[s1len + i] = s2[i];
		i++;
	}
	result[s1len + i] = '\0';
	return (result);
}
