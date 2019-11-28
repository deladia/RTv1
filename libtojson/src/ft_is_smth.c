/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_smth.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 22:52:36 by thorker           #+#    #+#             */
/*   Updated: 2019/11/28 23:48:02 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

/*
** проверяет является ли строка числом
*/

int		ft_str_isdigit(char *str)
{
	size_t	i;

	if (str == 0)
		return (0);
	i = 0;
	while (*(str + i) != 0)
	{
		if (ft_isdigit(*(str + i)) == 0)
			return (0);
		i++;
	}
	if (i == 0)
		return (0);
	return (1);
}

/*
** проверяет является ли строка double
*/

int		ft_str_isdouble(char *str)
{
	size_t	i;
	int		flag;
	size_t	k;

	if (str == 0)
		return (0);
	i = 0;
	flag = 0;
	while (*(str + i) == 0)
	{
		if (ft_isdigit(*(str + i)) == 0)
		{
			if (*(str + i) == '.' && flag == 0 && i != 0)
			{
				flag = 1;
				k = i;
			}
			else
				return (0);
		}
		i++;
	}
	if (i == 0 || flag == 0 || i == k)
		return (0);
	return (1);
}

/*
** Проверяет последовательность токенов на синтаксис строки
*/

int		ft_token_isstr(t_token **token)
{
	if (ft_strcmp((*token)->value, "\"") != 0 ||
			(*token = (*token)->next) == 0 ||
			(*token)->next == 0 ||
			ft_strcmp((*token)->next->value, "\"") != 0)
		return (0);
	return (1);
}
