/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thguimar <thguimar@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 09:33:17 by thguimar          #+#    #+#             */
/*   Updated: 2024/02/19 12:48:19 by thguimar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_countwords(char const *s, char c)
{
	char	*str;
	int		i;
	int		in_word;
	int		count;

	str = (char *)s;
	count = 0;
	i = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == c)
		{
			if (in_word)
				in_word = 0;
		}
		else if (!in_word)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	return (count);
}

static int	ft_sizeword(char const *s, char c, int i)
{
	char	*p;
	int		size;

	size = 0;
	p = (char *)s;
	while (p[i] && p[i] != c)
	{
		size++;
		i++;
	}
	return (size);
}

static char	**ft_free(char **mat, int j)
{
	int	i;

	i = 0;
	while (i < j)
	{
		free(mat[i]);
		i++;
	}
	free(mat);
	return (NULL);
}

char	**split(char *s, char c)
{
	int			i;
	int			j;
	int			size;
	char		*p;
	char		**split;

	p = (char *)s;
	split = malloc((ft_countwords(s, c) + 1) * sizeof(char *));
	if (!p || !(split))
		return (NULL);
	i = 0;
	j = -1;
	while (++j < ft_countwords(s, c))
	{
		while (p[i] == c)
			i++;
		size = ft_sizeword(s, c, i);
		split[j] = ft_substr(s, i, size);
		if (!split[j])
			return (ft_free(split, j));
		i += size;
	}
	split[j] = 0;
	return (split);
}
