/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:50:12 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/07 13:05:39 by thorker          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void			mouse_rotation(t_cam *cam, int x, int y)
{
	float d_tetta;
	d_tetta = (y - HEIGHT / 2) * 0.001f;
	cam->phi -= (x - WIDTH / 2) * 0.001f;
	if (cam->phi > (float)M_PI - 0.00001f)
		cam->phi -= 1 * (float)M_PI;
	if (cam->phi < -(float)M_PI + 0.00001f)
		cam->phi += -1 * (float)M_PI;
	if (d_tetta < 0  && (cam->tetta) + d_tetta >= 0.00001f)
		cam->tetta += d_tetta;
	if (d_tetta > 0 && (cam->tetta) + d_tetta <= (float)M_PI + 0.00001f)
		cam->tetta += d_tetta;
}


int			mouse_events(char *flag, t_sdl *sdl, t_object **hi_lited_object, t_scene *scene)
{
	int			x;
	int			y;

	SDL_GetMouseState(&x, &y);
	if (sdl->event.button.button == SDL_BUTTON_LEFT)
	{
		SDL_WarpMouseInWindow(sdl->window, 640, 512);
			mouse_rotation(&(scene->cam), x, y);
		scene->move_on = 1;
		return (1);
	}
	if (sdl->event.button.button == SDL_BUTTON_RIGHT)
	{
		if ((*hi_lited_object = get_object(scene, x, y)) != NULL)
			return (1);
	}
    if(sdl->event.type == SDL_MOUSEWHEEL)
    {
		if(sdl->event.wheel.y > 0)
			sdl->event.key.keysym.scancode = SDL_SCANCODE_W;
		else if(sdl->event.wheel.y < 0)
			sdl->event.key.keysym.scancode = SDL_SCANCODE_S;
		move(sdl->event, &(scene->cam), &(scene->flag));
	}
	return (0);
}
