/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deladia <deladia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 21:18:10 by deladia           #+#    #+#             */
/*   Updated: 2020/01/10 21:16:00 by deladia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_RTV1_H
# define RTV1_RTV1_H

# ifndef OPENCL___
#include "libft.h"
#include <SDL.h>
#include <math.h>
#include <OpenCL/opencl.h>
# endif
# define WIDTH 1250
# define HEIGHT 1000
# define VW 1.25
# define VH 1
# define D 1
# define WHITE 0xFFFFFF
# define BLACK 0x000000
# include "kernel.h"
// typedef struct			s_result
// {
// 	double 				t1;
// 	double 				t2;
// }						t_result;

// typedef struct 			s_light
// {
// 	char 				type;
// 	double 				intensity;
// 	t_pos				position;
// }						t_light;

// typedef struct 			s_cylinder
// {
// 	t_pos				center;
// 	t_pos				axis;
// 	double				radius;
// }						t_cylinder;

// typedef struct 			s_cone
// {
// 	t_pos				center;
// 	t_pos				axis;
// 	double				tan;
// }						t_cone;

// typedef struct 			s_plane
// {
// 	t_pos				center;
// 	t_pos				normal;
// }						t_plane;

// typedef struct 			s_sphere
// {
// 	t_pos				center;
// 	double				radius;
// }						t_sphere;

// union					u_objects
// {
// 	t_sphere			sphere;
// 	t_cylinder			cylinder;
// 	t_cone				cone;
// 	t_plane				plane;
// };

// enum					e_obj_type
// {
// 	o_sphere = 1,
// 	o_cylinder,
// 	o_cone,
// 	o_plane,
// };

// typedef struct			s_object
// {
// 	union u_objects		*objects;
// 	enum e_obj_type		type;
// 	int					color;
// 	int					specular;
// 	double				reflective;
// }						t_object;

// typedef struct			s_return
// {
// 	t_object			*closest_object;
// 	double				closest_t;
// }						t_return;

// typedef struct			s_cam
// {
// 	t_pos				position;
// 	double 				a;
// 	double 				b;
// }						t_cam;

typedef struct			s_cylinder_params
{
	// t_pos				pos;
	// t_pos				axis;
	cl_float3			pos;
	cl_float3			axis;
	float				radius;
	int					color;
	int					specular;
	float				reflective;
}						t_cylinder_params;

typedef struct			s_cone_params
{
	// t_pos				pos;
	// t_pos				axis;
	cl_float3			pos;
	cl_float3			axis;
	float				tan;
	int					color;
	int					specular;
	float				reflective;
}						t_cone_params;

typedef struct			s_plane_params
{
	// t_pos				pos;
	cl_float3			pos;
	int					color;
	int					specular;
	float				reflective;
	cl_float3			normal;
	// t_pos				normal;
}						t_plane_params;

typedef struct			s_sphere_params
{
	// t_pos				pos;
	cl_float3			pos;
	float				radius;
	int					color;
	int					specular;
	float				reflective;
}						t_sphere_params;

// typedef struct 			s_light_off
// {
// 	int					ambient;
// 	int					point;
// 	int					directional;
// 	int					reflect;
// }						t_light_off;

// typedef struct			s_scene
// {
// 	t_pos				*view;
// 	t_cam				*cam;
// 	t_light				**light;
// 	t_object			**object;
// 	t_light_off			*off;
// }						t_scene;
# ifndef OPENCL___
typedef struct			s_cl
{
	cl_platform_id		platform_id;
	cl_uint				ret_num_platforms;
	cl_context			context;
	cl_uint				ret_num_devices;
	cl_command_queue	cmd_queue;
	cl_program			program;
	cl_kernel			kernel;
	size_t				global_work_size[1];
	cl_device_id		device_id;
	cl_mem				memobjs[5];
	char 				*program_source;
	size_t 				program_size;
}						t_cl;

typedef struct 			s_sdl
{
	SDL_Window			*window;
	SDL_Renderer		*render;
	SDL_Texture			*texture;
	SDL_Event			event;
	int					*pixels;
	int					*background;
}						t_sdl;

typedef struct 			s_rtv1
{
	t_sdl				*sdl;
	t_cl				*opencl;
	t_scene				*scene;
}						t_rtv1;
# endif

# ifndef OPENCL___
int						sdl_init(t_sdl *sdl);
int						sdl_control(t_sdl *sdl, t_scene *scene, t_cl *cl);
void					init_light(t_light **light);
void					init_object(t_object **object);
void 					ft_error(char *str);
int						trace_start(t_sdl *sdl, t_scene *scene);
void                    func_error(int err);
int						read_kernel(t_cl *cl);
int						create_cl(t_cl *cl, t_sdl *sdl, t_scene *scene);
int						set_arg(t_cl *cl, t_sdl *sdl, t_scene *scene);
# endif

#endif
