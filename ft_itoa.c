/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiastow <jpiastow@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 14:45:54 by jpiastow          #+#    #+#             */
/*   Updated: 2022/10/21 16:11:34 by jpiastow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		i++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	nbr;
	int		i;

	nbr = n;
	i = ft_intlen(nbr);
	result = (char *) malloc((i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	result[i--] = '\0';
	if (nbr == 0)
		result[0] = 48;
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= -1;
	}
	while (nbr > 0)
	{
		result[i] = 48 + (nbr % 10);
		nbr /= 10;
		i--;
	}
	return (result);
}
