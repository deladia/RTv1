/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_plane_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 08:58:20 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/21 11:37:27 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		print_screen_title(t_ttf *ttf[], SDL_Surface *sur)
{
	SDL_Color	default_color;
	SDL_Color	highlighted_color;

	highlighted_color = (SDL_Color){118, 165, 163, 0};
	default_color = ttf[BIG_FONT_ID]->font_color;
	ttf[BIG_FONT_ID]->font_color = highlighted_color;
	sdl_putstr((SDL_Rect){200, 35, 0, 0}, "plane",
				ttf[BIG_FONT_ID], sur);
	ttf[BIG_FONT_ID]->font_color = default_color;
}

static void		print_screen_item(t_ttf *ttf[], SDL_Surface *sur)
{
	SDL_Color	default_color;
	SDL_Color	highlighted_color;

	highlighted_color = (SDL_Color){189, 171, 135, 0};
	default_color = ttf[NORMAL_FONT_ID]->font_color;
	ttf[NORMAL_FONT_ID]->font_color = highlighted_color;
	sdl_putstr((SDL_Rect){50, 100, 0, 0}, "distance",
		ttf[NORMAL_FONT_ID], sur);
	sdl_putstr((SDL_Rect){360, 100, 0, 0}, "axis",
		ttf[NORMAL_FONT_ID], sur);
	ttf[NORMAL_FONT_ID]->font_color = default_color;
}

void			gui_plane_screen(t_sdl *sdl)
{
	print_screen_title(sdl->gui->ttf, sdl->screen[1]->sur);
	print_screen_item(sdl->gui->ttf, sdl->screen[1]->sur);
	gui_material(sdl);
	gui_buttons(sdl);
	load_textboxes(Plane_axis, Plane_tan, sdl->gui, sdl->screen[1]->render);
}
