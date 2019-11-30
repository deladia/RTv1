/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 22:54:41 by deladia           #+#    #+#             */
/*   Updated: 2019/12/01 02:23:07 by thorker          ###   ########.fr       */
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

int		main(void)
{
	t_key_value	*tmp;
	int 		ret;
	int 		number;

//	tmp = parse_json("../../../param.json");
	tmp = parse_json("test.json");
	ret = get_int(tmp, "angle_a", &number);
	printf("ret = %d value = %d\n", ret, number);
	ft_print(tmp);
	/*
	char *line = 0;
	size_t k = read(0, line, 3);
	(void)k;
	*/
	ft_return(&tmp);
	return (0);
}
