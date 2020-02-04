/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <deladia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 00:00:22 by thorker           #+#    #+#             */
/*   Updated: 2020/02/04 14:01:27 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		move_help(float *d, SDL_Event event, t_cam *cam)
{
	if (event.key.keysym.scancode == SDL_SCANCODE_D)
	{
		d[2] -= STEP * cos(cam->phi) * sin(cam->tetta);
		d[0] += STEP * sin(cam->phi) * sin(cam->tetta);
	}
	if (event.key.keysym.scancode == SDL_SCANCODE_V)
	{
		d[2] -= STEP * sin(cam->phi) * cos(cam->tetta);
		d[0] -= STEP * cos(cam->phi) * cos(cam->tetta);
		d[1] += STEP * sin(cam->tetta);
	}
	if (event.key.keysym.scancode == SDL_SCANCODE_C)
	{
		d[2] += STEP * sin(cam->phi) * cos(cam->tetta);
		d[0] += STEP * cos(cam->phi) * cos(cam->tetta);
		d[1] -= STEP * sin(cam->tetta);
	}
	cam->pos.s[2] += d[2];
	cam->pos.s[0] += d[0];
	cam->pos.s[1] += d[1];
}

void			move(SDL_Event event, t_sdl *sdl, t_cam *cam)
{
	float		d[3];

	d[2] = 0;
	d[0] = 0;
	d[1] = 0;
	if (event.key.keysym.scancode == SDL_SCANCODE_W)
	{
		d[2] += STEP * sin(cam->phi) * sin(cam->tetta);
		d[0] += STEP * cos(cam->phi) * sin(cam->tetta);
		d[1] += STEP * cos(cam->tetta);
	}
	if (event.key.keysym.scancode == SDL_SCANCODE_S)
	{
		d[2] -= STEP * sin(cam->phi) * sin(cam->tetta);
		d[0] -= STEP * cos(cam->phi) * sin(cam->tetta);
		d[1] -= STEP * cos(cam->tetta);
	}
	if (event.key.keysym.scancode == SDL_SCANCODE_A)
	{
		d[2] += STEP * cos(cam->phi) * sin(cam->tetta);
		d[0] -= STEP * sin(cam->phi) * sin(cam->tetta);
	}
	move_help(d, event, cam);
}
