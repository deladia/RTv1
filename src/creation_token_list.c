/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creation_token_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 16:16:00 by deladia           #+#    #+#             */
/*   Updated: 2019/11/04 01:54:15 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

//t_type			is_text(char *word, t_dictionary *dict)
//{
//	int 		i;
//
//	i = 0;
//	while(i < 3)
//		if (!ft_strcmp(word, dict->object[i++]))
//			return (Object);
//	i = 0;
//	while(i < 3)
//		if (!ft_strcmp(word, dict->camera_properties[i++]))
//			return (Camera_properties);
//	i = 0;
//	while(i < 3)
//		if (!ft_strcmp(word, dict->light_properties[i++]))
//			return (Light_properties);
//	i = 0;
//	while(i < 6)
//		if (!ft_strcmp(word, dict->figure_properties[i++]))
//			return (Figure_properties);
//	i = 0;
//	while(i < 3)
//		if (!ft_strcmp(word, dict->light_type[i++]))
//			return (Light_type);
//	i = 0;
//	while(i < 4)
//		if (!ft_strcmp(word, dict->figure_type[i++]))
//			return (Subobject);
//	return (None);
//}
//
//t_type			is_separator(char *word, t_dictionary *dict)
//{
//	int 		i;
//
//	i = 0;
//	while(i < 5)
//	{
//		if (ft_strchr(word, dict->separator[i++]))
//			return (Separator);
//	}
//	return (None);
//}
//
//t_type			is_number(char *word, t_dictionary *dict)
//{
//	int 		i;
//	size_t 		len;
//
//	(void)dict;
//	i = 0;
//	len = 0;
//	if (word[0] == '-')
//		len++;
//	while(word[i] != '\0')
//	{
//		if (word[i] >= '0' && word[i] <= '9')
//			len++;
//		i++;
//	}
//	if (ft_strlen(word) == len)
//		return (Dec);
//	else if (ft_strlen(word) - len == 1 && word[1] == '.')
//		return (Double_presition);
//	else if (word[0] == '0' && word[1] == 'x')
//		return (Hex);
//	return (None);
//}

/*
** 		Создает токен и присваевает value
*/

t_token			*create_token(char *word, t_token *token)
{
	if (token->value == NULL)
		token->value = ft_strdup(word);
	else
	{
		if ((token->next = (t_token *)ft_memalloc(sizeof(t_token))) == NULL)
			ft_error("Memory not allocated (for token)");
		token = token->next;
		token->value = ft_strdup(word);
	}
	return (token);
}