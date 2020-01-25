/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_smth.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thorker <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 05:48:25 by thorker           #+#    #+#             */
/*   Updated: 2020/01/21 22:47:30 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

/*
** создает вещественное число и двигает токен
*/

void	*make_double(t_token **token)
{
	double *new_value;

	if ((new_value = (double*)malloc(sizeof(double))) == 0)
		return (*token);
	*new_value = ft_atof((*token)->value);
	*token = (*token)->next;
	return ((void*)new_value);
}

/*
** создает целое число и двигает токен
*/

void	*make_digit(t_token **token)
{
	int	*new_value;

	if ((new_value = (int*)malloc(sizeof(int))) == 0)
		return (*token);
	*new_value = ft_atoi((*token)->value);
	*token = (*token)->next;
	return ((void*)new_value);
}

/*
** создает строку и убирает знаки экранирования
*/

char	*make_string(char *str)
{
	char	*new_key;
	size_t	k;
	size_t	i;

	k = 0;
	i = 0;
	while (*(str + k) != 0)
	{
		if (*(str + k) == '\\' && *(str + ++k) == 0)
			return (0);
		k++;
		i++;
	}
	if ((new_key = ft_strnew(i)) == 0)
		return (0);
	i = 0;
	k = 0;
	while (*(str + k) != 0)
	{
		if (*(str + k) == '\\')
			k++;
		*(new_key + i++) = *(str + k++);
	}
	return (new_key);
}

/*
**	создает массив
*/

void	*make_array(t_token **token)
{
	t_array	*array;
	t_type	type;
	void	*value;

	if ((*token)->next == 0 || (array = (t_array*)malloc(sizeof(t_array))) == 0)
		return (*token);
	array->length = 0;
	while (*token != 0 && (*token)->next != 0)
	{
		*token = (*token)->next;
		type = 0;
		value = check_value(token, &type);
		if ((type == 0 | *token == 0) && realloc_array(array, value, type) == 0)
			break ;
		if (ft_strcmp((*token)->value, ",") == 0)
			continue;
		if (ft_strcmp((*token)->value, "]") == 0)
		{
			*token = (*token)->next;
			return (array);
		}
		break ;
	}
	ft_return_array(&array);
	return (*token);
}