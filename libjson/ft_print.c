/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:27:09 by deladia           #+#    #+#             */
/*   Updated: 2019/11/06 23:27:11 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"

void		ft_print(t_key_value *tree)
{
	int 	i;

	i = 0;
	if (tree->key[i] == NULL)
		return ;
	while (tree->key[i] != NULL)
	{
		if (tree->type[i] == Array)
		{
			//Печатать массив
		}
		else if (tree->type[i] == String)
		{
			printf("value: %s\nkey: %s\n", tree->value[i], tree->key[i]);
		}
		else if (tree->type[i] == Dec)
		{
			printf("value: %d\nkey: %s\n", ((int*)tree->value[i])[0], tree->key[i]);
		}
		else if (tree->type[i] == Doub)
		{
			printf("value: %lf\nkey: %s\n", ((double*)tree->value[i])[0], tree->key[i]);
		}
		else if (tree->type[i] == None)
		{
			printf("value: NULL\nkey: %s\n", tree->key[i]);
		}
		else if (tree->type[i] == Object)
			ft_print(tree->value[i]);
		i++;
	}
}
