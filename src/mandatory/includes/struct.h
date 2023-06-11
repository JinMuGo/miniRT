/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:08:43 by jgo               #+#    #+#             */
/*   Updated: 2023/06/11 12:16:02 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "enum.h"
# include "minirt.h"

struct				s_rgba
{
	double			r;
	double			g;
	double			b;
	double			a;
};

struct				s_mlx_assets
{
	mlx_t			*mlx;
	mlx_image_t		*img;
};

struct				s_ambient
{
	t_object_type	type;
	double			ratio;
	t_rgba			rgba;
};

struct				s_camera
{
	t_object_type	type;
	t_point3		view_point;
	double			fov;
	t_vec3			normal_vec3;
	double			viewport_h;
	double			viewport_w;
	t_vec3			horizontal;
	t_vec3			vertical;
	double			focal_len;
	t_point3		left_bottom;
	double			pitch;
	double			yaw;
	t_vec3			front;
	t_vec3			pos;
	t_vec3			up;
};

struct				s_spot_light
{
	t_object_type	type;
	t_point3		light_point;
	double			ratio;
	t_rgba			rgba;
};

struct				s_obj
{
	t_object_type	type;
	union u_obj		content;
	t_obj			*next;
};

struct				s_sphere
{
	t_object_type	type;
	t_point3		center_point;
	double			diameter;
	t_rgba			rgba;
};

struct				s_plane
{
	t_object_type	type;
	t_point3		point;
	t_vec3			normal_vec3;
	t_rgba			rgba;
};

struct				s_cylinder
{
	t_object_type	type;
	t_point3		center_point;
	t_vec3			normal_vec3;
	double			diameter;
	double			height;
	t_rgba			rgba;
};

struct				s_ray
{
	t_point3		origin;
	t_vec3			direction;
};

struct				s_record
{
	t_point3		point;
	t_vec3			normal_vec3;
	bool			front_face;
	t_rgba			rgba;
	double			t;
};

struct				s_canvas
{
	int				width;
	int				height;
	double			aspect_ratio;
};

struct				s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_ray			ray;
};

struct				s_meta
{
	t_mlx_assets	mlx_assets;
	t_ambient		ambient;
	t_scene			scene;
	t_camera		camera;
	t_list			*spot_lights;
	t_obj			*objs;
};

#endif
