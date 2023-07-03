/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespace.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:05:06 by sanghwal          #+#    #+#             */
/*   Updated: 2023/07/03 17:45:32 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "defs.h"

static size_t	_total_word_count(char const *s)
{
	size_t	cnt;
	size_t	i;

	cnt = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (s[i])
			cnt++;
		while (s[i] && !ft_isspace(s[i]))
			i++;
	}
	return (cnt);
}

static size_t	_cal_word_len(char const *s, size_t start)
{
	size_t	end;

	end = start;
	while (s[end] && !ft_isspace(s[end]))
		end++;
	return (end - start + 1);
}

static bool	_shift_i_judge_end(char const *s, size_t *i)
{
	while (s[*i] && ft_isspace(s[*i]))
		(*i)++;
	if (!s[*i])
		return (true);
	return (false);
}

char	**ft_split_whitespace(char const *s)
{
	char	**arr;
	size_t	i;
	size_t	idx;
	size_t	word_size;

	if (!s)
		return (NULL);
	arr = malloc(sizeof(char *) * (_total_word_count(s) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	idx = 0;
	while (s[i])
	{
		if (_shift_i_judge_end(s, &i))
			break ;
		word_size = _cal_word_len(s, i);
		arr[idx] = malloc(sizeof(char) * word_size);
		if (!arr[idx])
			return (ft_free_all_arr(arr));
		ft_strlcpy(arr[idx++], &s[i], word_size);
		i += word_size - 1;
	}
	arr[idx] = 0;
	return (arr);
}
