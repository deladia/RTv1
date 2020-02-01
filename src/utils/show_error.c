/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <deladia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 02:35:38 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/01 10:01:33 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void				show_error(char *error, char *sounds[])
{
	int				id;
	char			*sh_command;

	sh_command = ft_strjoin(DISPLAY_NOT, E_CAM);
	system(sh_command);
	srand(time(NULL));
	id = rand() % ft_len_arr((void **)sounds);
	if (id == 0)
		return ;
	playSound(sounds[id], 100);
	SDL_Delay(1500);
	ft_strdel(&sh_command);
}