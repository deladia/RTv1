/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:54:41 by deladia           #+#    #+#             */
/*   Updated: 2019/11/26 16:03:24 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "to_json.h"
void	free_token(t_token **token)
{
	t_token		*tmp;

	tmp = *token;
	while(tmp)
	{
		*token = tmp;
		if (tmp->next)
			tmp = tmp->next;
		free((*token)->value);
		free(token);
	}
}

int		ftf_parse(void)
{
	t_key_value		*tmp;
	t_token			*token;
	t_token			*head_token;

	tmp = NULL;
	token = ft_open("test.json");
	head_token = token;
	if (token == 0)
		return (0);
	if (ft_strcmp(token->value, "{") == 0)
		tmp = check_object(&token);
	else
	{
		ft_putendl(token->value);
		return (0);
	}
	if ((t_token*)tmp == token)
	{
		ft_error("токен равен тмп");
	}
	ft_print(tmp);
	while (head_token != 0)
	{
		token = head_token->next;
		free(head_token->value);
		free(head_token);
		head_token = token;		
	}
	ft_return(&tmp);
	return (0);
}
int		main(void)
{
	ftf_parse();
	char *line = 0;
	size_t k = read(0, line, 3);
	(void)k;
	return (0);
}
