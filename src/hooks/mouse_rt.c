/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_rt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 07:52:49 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/21 12:23:46 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

bool			mouse_rt(t_sdl *sdl,
						t_object **select_obj,
						t_scene *scene)
{
	int			x;
	int			y;

	SDL_GetMouseState(&x, &y);
	if (sdl->event.button.button == SDL_BUTTON_LEFT)
	{
		SDL_ShowCursor(0);
		SDL_WarpMouseInWindow(sdl->screen[0]->win, 640, 512);
		mouse_rotation(&(scene->cam), x, y);
		scene->move_on = 1;
		return (true);
	}
	if (sdl->event.type == SDL_MOUSEBUTTONDOWN
		&& sdl->event.button.button == SDL_BUTTON_RIGHT)
	{
		if ((*select_obj = get_object(scene, x, y)) != NULL)
			return (true);
	}
	return (false);
}
