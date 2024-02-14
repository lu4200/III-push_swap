/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lumaret <lumaret@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 20:53:46 by lumaret           #+#    #+#             */
/*   Updated: 2024/02/14 05:36:36 by lumaret          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static	int	count_words(char *s, char sep)
{
	int	count;
	bool		in_word;

	count = 0;
	while (*s)
	{
		in_word = false;
		while (*s == sep)
			++s;
		while (*s != sep && *s)
		{
			if (!in_word)
			{
				count++;
				in_word = true;
			}
			++s;
		}
	}	
	return (count);
}

static char	*get_next_word(char *s, char sep)
{
	static int	cursor = 0;
	char		*next_word;
	int			len;
	int			i;

	len = 0;
	i = 0;
	while (s[cursor] == sep)
		++cursor;
	while ((s[cursor + len] != sep) && s[cursor + len])
		++len;
	next_word = malloc((size_t)len * sizeof(char) + 1);
	if (!next_word)
		return (NULL);
	while ((s[cursor] != sep) && s[cursor])
		next_word[i++] = s[cursor++];
	next_word[i] = '\0';
	return (next_word);
}

char	**ps_split(char *s, char c)
{
	int			nb_words;
	char		**result;
	int			i;

	i = 0;
	nb_words = count_words(s, c);
	if (!nb_words)
		exit(1);
	result = malloc(sizeof(char *) * (size_t)(nb_words + 1));
	if (!result)
		return (NULL);
	while (nb_words-- >= 0)
	{
		if (i == 0) 
		{
			result[i] = malloc(sizeof(char));
			if (!result[i])
				return (NULL);
			result[i++][0] = '\0';
			continue ;
		}
		result[i++] = get_next_word(s, c);
	}
	result[i] = NULL;
	return (result);
}
