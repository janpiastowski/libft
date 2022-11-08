/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpiastow <jpiastow@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 11:52:06 by jpiastow          #+#    #+#             */
/*   Updated: 2022/10/21 14:07:34 by jpiastow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *string, char c)
{
	int	i;
	int	is_word;

	i = 0;
	is_word = 0;
	while (*string)
	{
		if (*string != c && is_word == 0)
		{
			is_word = 1;
			i++;
		}
		if (*string == c)
			is_word = 0;
		string++;
	}
	return (i);
}

static char	*word_duplicate(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**result;

	result = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			result[j++] = word_duplicate(s, index, i);
			index = -1;
		}
		i++;
	}
	result[j] = 0;
	return (result);
}
