/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:08:43 by jgo               #+#    #+#             */
/*   Updated: 2023/06/07 15:07:09 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "enum.h"
# include "minirt.h"

typedef struct s_vec3		t_vec3;
typedef struct s_vec4		t_vec4;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;
typedef struct s_ray		t_ray;
// typedef struct s_camera		t_camera;
typedef struct s_canvas		t_canvas;
// typedef struct s_sphere		t_sphere;
typedef struct s_hit_record	t_hit_record;
typedef struct s_object		t_object;
typedef struct s_light		t_light;
typedef struct s_scene		t_scene;

typedef struct s_mlx_assets	t_mlx_assets;
typedef struct s_rgb		t_rgb;
typedef struct s_ambient	t_ambient;
typedef struct s_camera		t_camera;
typedef struct s_spot_light	t_spot_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;

typedef struct s_mlx		t_mlx;
typedef struct s_img		t_img;
typedef struct s_meta		t_meta;

struct						s_vec3
{
	double					x;
	double					y;
	double					z;
};

struct						s_vec4
{
	double					x;
	double					y;
	double					z;
	double					w;
};

struct						s_rgb
{
	int						r;
	int						g;
	int						b;
};


struct						s_ray
{
	t_point3				orig;
	t_vec3					dir;
};

// struct						s_camera
// {
// 	t_point3 orig;        // 카메라 원점(위치)
// 	double viewport_h;    // 뷰포트 세로길이
// 	double viewport_w;    // 뷰포트 가로길이
// 	t_vec3 horizontal;    // 수평길이 벡터
// 	t_vec3 vertical;      // 수직길이 벡터
// 	double focal_len;     // focal length
// 	t_point3 left_bottom; // 왼쪽 아래 코너점
// };

// struct						s_canvas
// {
// 	int width;           //canvas width
// 	int height;          //canvas height;
// 	double aspect_ratio; //종횡비
// };

// struct						s_sphere
// {
// 	t_point3				center;
// 	double					radius;
// 	double					radius2;
// };

// struct						s_hit_record
// {
// 	t_point3 p;    // 교점의 좌표
// 	t_vec3 normal; // 교점에서의 법선
// 	double					tmin;
// 	double					tmax;
// 	double t; // 광선의 원점과 교점 사이의 거리.
// 	bool					front_face;
// 	t_color3				albedo;
// };

// struct						s_object
// {
// 	t_object_type			type;
// 	void					*element;
// 	void					*next;
// 	t_color3				albedo;
// };

struct						s_light
{
	t_point3				origin;
	t_color3				light_color;
	double					bright_ratio;
};

// struct						s_scene
// {
// 	t_canvas				canvas;
// 	t_camera				camera;
// 	t_object				*world;
// 	t_object				*light;
// 	t_color3				ambient; // 8.4에서 설명할 요소
// 	t_ray					ray;
// 	t_hit_record			rec;
// };

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
	int						fov;
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
