/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:08:43 by jgo               #+#    #+#             */
/*   Updated: 2023/06/08 16:40:08 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "enum.h"
# include "minirt.h"

typedef struct s_mlx_assets	t_mlx_assets;
typedef struct s_rgb		t_rgb;
typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_vec3		t_point3;
typedef struct s_meta		t_meta;

struct						s_rgb
{
	int						r;
	int						g;
	int						b;
};

struct						s_mlx_assets
{
	mlx_t					*mlx;
	mlx_image_t				*img;
};

struct						s_ambient
{
	t_object_type			type;
	double					ratio;
	t_rgb					rgb;
};

struct						s_camera
{
	t_object_type			type;
	t_point3				view_point;
	t_vec3					normal_vec3;
	double					fov;
};

struct						s_spot_light
{
	t_object_type			type;
	t_point3				light_point;
	double					ratio;
	t_rgb					rgb;
};

struct						s_sphere
{
	t_object_type			type;
	t_point3				center_point;
	double					diameter;
	t_rgb					rgb;
};

struct						s_plane
{
	t_object_type			type;
	t_point3				point;
	t_vec3					normal_vec3;
	t_rgb					rgb;
};

struct						s_cylinder
{
	t_object_type			type;
	t_point3				center_point;
	t_vec3					normal_vec3;
	double					diameter;
	double					height;
	t_rgb					rgb;
};

struct						s_meta
{
	t_mlx_assets			mlx_assets;
	t_ambient				ambient;
	t_camera				camera;
	t_list					*spot_lights;
	t_list					*objs;
};

#endif
