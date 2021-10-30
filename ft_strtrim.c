/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wnunes <wnunes@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 21:08:55 by wnunes            #+#    #+#             */
/*   Updated: 2021/10/28 23:08:53 by wnunes           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_start(char const *s1, char const *set)
{
	int	value_1;
	int	value_2;
	int	jump;

	value_1 = 0;
	while (s1[value_1])
	{
		value_2 = 0;
		jump = 0;
		while (set[value_2])
		{
			if (s1[value_1] == set[value_2])
			{
				jump++;
			}
			value_2++;
		}
		if (jump == 0)
		{
			break ;
		}
		value_1++;
	}
	return (value_1);
}

int	ft_end(char const *s1, char const *set)
{
	int	value_1;
	int	value_2;
	int	jump;

	value_1 = ft_strlen(s1) - 1;
	while (value_1 > 0)
	{
		value_2 = 0;
		jump = 0;
		while (set[value_2])
		{
			if (s1[value_1] == set[value_2])
			{
				jump++;
			}
			value_2++;
		}
		if (jump == 0)
		{
			break ;
		}
		value_1--;
	}
	return (value_1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		count_start;
	int		count_end;
	char	*s1_temp;

	count_start = ft_start(s1, set);
	count_end = ft_end(s1, set) + 1;
	if (count_end <= count_start)
	{
		return (ft_strdup(""));
	}
	s1_temp = (char *)malloc(sizeof(char) * (count_end - count_start + 1));
	ft_strlcpy(s1_temp, s1 + count_start, count_end - count_start + 1);
	return (s1_temp);
}
