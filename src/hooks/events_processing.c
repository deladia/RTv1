/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_processing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 11:38:10 by sleonia           #+#    #+#             */
/*   Updated: 2020/02/04 16:11:54 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

// void			events_processing(char *flag, t_rt *rt)
// {
// 	if (rt->sdl->event.type == SDL_QUIT)
// 			*flag = 1;
// 	if (key_events(flag, rt) || mouse_events(flag, rt->sdl, rt->scene))
// 	{
// 		calc_screen(&rt->scene->cam);
// 		set_opencl_arg(rt->opencl, rt->sdl, rt->scene);
// 		filter(rt->sdl->pixels, *flag);
// 		sdl_update(rt->sdl);
// 	}
// 	else
// 	{
// 		rt->scene->move_on = 0;
// 		calc_screen(&rt->scene->cam);
// 		set_opencl_arg(rt->opencl, rt->sdl, rt->scene);
// 		filter(rt->sdl->pixels, *flag);
// 		sdl_update(rt->sdl);
// 	}	
// }
void			events_processing(char *flag, t_rt *rt)
{
	if (rt->sdl->event.type == SDL_QUIT)
			*flag = 1;
	if (key_events(flag, rt) || mouse_events(flag, rt->sdl, rt->scene))
	{
		calc_screen(&rt->scene->cam);
		set_opencl_arg(rt->opencl, rt->sdl, rt->scene);
		filter(rt->sdl->sur->pixels, *flag);
		sdl_update(rt->sdl);
	}
	else
	{
		rt->scene->move_on = 0;
		calc_screen(&rt->scene->cam);
		set_opencl_arg(rt->opencl, rt->sdl, rt->scene);
		filter(rt->sdl->sur->pixels, *flag);
		sdl_update(rt->sdl);
	}	
}
