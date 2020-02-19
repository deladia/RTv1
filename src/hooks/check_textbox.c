/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textbox.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 21:07:57 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/19 21:38:33 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static bool	check_sphere_textbox(int x, int y,
							t_object **hi_lited_object, t_rt *rt)
{
	if ((x >= 35 && x <= 120) && (y >= 160 && y <= 185))
	{
		rt->sdl->gui->textbox[Sphere_rad]->on_focus = true;
		return (reset_value(Sphere_rad, rt));
	}
	if ((x >= 305 && x <= 480) && (y >= 160 && y <= 185))
	{
		rt->sdl->gui->textbox[Sphere_center]->on_focus = true;
		return (reset_value(Sphere_center, rt));
	}
	return (true);
}

bool		check_textbox(int x, int y,
							t_object **hi_lited_object, t_rt *rt)
{
	if (!*hi_lited_object)
	{
		if ((x >= 185 && x <= 275) && (y >= 60 && y <= 80))
		{
			rt->sdl->gui->textbox[Phi]->on_focus = true;
			return (reset_value(Phi, rt));
		}
		if ((x >= 390 && x <= 480) && (y >= 60 && y <= 80))
		{
			rt->sdl->gui->textbox[Tetta]->on_focus = true;
			return (reset_value(Tetta, rt));
		}
		if ((x >= 180 && x <= 230) && (y >= 195 && y <= 225))
		{
			rt->sdl->gui->textbox[Id]->on_focus = true;
			return (reset_value(Id, rt));
		}
		if ((x >= 265 && x <= 360) && (y >= 195 && y <= 225))
		{
			rt->sdl->gui->textbox[Skybox_ambient]->on_focus = true;
			return (reset_value(Skybox_ambient, rt));
		}
		if ((x >= 400 && x <= 460) && (y >= 195 && y <= 225))
		{
			rt->sdl->gui->textbox[Fsaa]->on_focus = true;
			return (reset_value(Fsaa, rt));
		}	
		return (true);
	}
	else if ((*hi_lited_object)->type == o_sphere)
		check_sphere_textbox(x, y, hi_lited_object, rt);
	if ((x >= 410 && x <= 430) && (y >= 710 && y <= 750))
	{
		rt->sdl->gui->textbox[New_obj]->on_focus = true;
		return (reset_value(New_obj, rt));
	}
	return (true);
}
