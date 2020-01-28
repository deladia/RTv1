/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cl_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sleonia <sleonia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/28 19:00:37 by deladia           #+#    #+#             */
/*   Updated: 2020/01/28 13:29:37 by sleonia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void		set_arg_2(t_cl *cl, t_sdl *sdl, t_scene *scene)
{
	int		ret;

	if ((ret = clEnqueueWriteBuffer(cl->cmd_queue, cl->memobjs[4], CL_TRUE, 0,
									sizeof(cl_int) * scene->texture_length,
									(cl_int *)scene->texture, 0, NULL,
									NULL)) != 0)
		// ft_error(clGetErrorString(ret));
		ft_error("KEK");
	if ((ret = clEnqueueWriteBuffer(cl->cmd_queue, cl->memobjs[5], CL_TRUE, 0,
									sizeof(cl_int) * scene->texture_cnt * 3,
									(cl_int *)scene->texture_param, 0, NULL,
									NULL)) != 0)
		// ft_error(clGetErrorString(ret));
		ft_error("KEK");
	if ((ret = clEnqueueNDRangeKernel(cl->cmd_queue, cl->kernel, 2, NULL,
							cl->global_work_size, NULL, 0, NULL, NULL)) != 0)
		// ft_error(clGetErrorString(ret));
		ft_error("KEK");
	if ((ret = clEnqueueReadBuffer(cl->cmd_queue, cl->memobjs[0], CL_TRUE, 0,
									HEIGHT * WIDTH * sizeof(cl_int),
									(cl_int *)sdl->pixels, 0, NULL,
									NULL)) != 0)
		// ft_error(clGetErrorString(ret));
		ft_error("KEK");
}

static void		set_arg_1(t_cl *cl, t_sdl *sdl, t_scene *scene)
{
	int		ret;

	if ((ret = clEnqueueWriteBuffer(cl->cmd_queue, cl->memobjs[0], CL_TRUE, 0,
									sizeof(cl_int) * HEIGHT * WIDTH,
									(cl_int *)sdl->pixels, 0, NULL,
								NULL)) != 0)
		// ft_error(clGetErrorString(ret));
		ft_error("KEK");
	if ((ret = clEnqueueWriteBuffer(cl->cmd_queue, cl->memobjs[1], CL_TRUE, 0,
								sizeof(t_cam), &scene->cam, 0, NULL,
								NULL)) != 0)
		// ft_error(clGetErrorString(ret));
		ft_error("KEK");
	if ((ret = clEnqueueWriteBuffer(cl->cmd_queue, cl->memobjs[2], CL_TRUE, 0,
								sizeof(t_object) * 6, scene->object, 0, NULL,
								NULL)) != 0)
		// ft_error(clGetErrorString(ret));
		ft_error("KEK");
	if ((ret = clEnqueueWriteBuffer(cl->cmd_queue, cl->memobjs[3], CL_TRUE, 0,
									sizeof(t_light) * 1, scene->light, 0, NULL,
								NULL)) != 0)
		// ft_error(clGetErrorString(ret));
		ft_error("KEK");
}

int				set_opencl_arg(t_cl *cl, t_sdl *sdl, t_scene *scene)
{
	cl_int		ret;
	int			side_x;
	int			side_y;

	side_x = WIDTH;
	side_y = HEIGHT;
	ret = clSetKernelArg(cl->kernel, 0, sizeof(cl_mem), &cl->memobjs[0]);
	ret |= clSetKernelArg(cl->kernel, 1, sizeof(cl_mem), &cl->memobjs[1]);
	ret |= clSetKernelArg(cl->kernel, 2, sizeof(cl_mem), &cl->memobjs[2]);
	ret |= clSetKernelArg(cl->kernel, 3, sizeof(cl_mem), &cl->memobjs[3]);
	ret |= clSetKernelArg(cl->kernel, 4, sizeof(cl_mem), &cl->memobjs[4]);
	ret |= clSetKernelArg(cl->kernel, 5, sizeof(cl_mem), &cl->memobjs[5]);
	ret |= clSetKernelArg(cl->kernel, 6, sizeof(cl_int), &scene->count_objects);
	ret |= clSetKernelArg(cl->kernel, 7, sizeof(cl_int), &scene->count_lights);
	ret |= clSetKernelArg(cl->kernel, 8, sizeof(cl_int), &scene->skybox_id);
	if (ret != 0)
		// ft_error(clGetErrorString(ret));
		ft_error("KEK");
	set_arg_1(cl, sdl, scene);
	set_arg_2(cl, sdl, scene);
	return (0);
}