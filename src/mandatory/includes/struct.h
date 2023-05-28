/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:08:43 by jgo               #+#    #+#             */
/*   Updated: 2023/05/27 23:37:29 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "minirt.h"
# include "enum.h"

typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;
typedef struct s_ray		t_ray;
typedef struct s_camera		t_camera;
typedef struct s_canvas		t_canvas;
typedef struct s_sphere		t_sphere;
typedef struct s_hit_record	t_hit_record;
typedef struct s_object		t_object;

typedef struct s_mlx		t_mlx;
typedef struct s_img		t_img;
typedef struct s_meta		t_meta;

struct						s_vec3
{
	double					x;
	double					y;
	double					z;
};

struct						s_ray
{
	t_point3				orig;
	t_vec3					dir;
};

struct						s_camera
{
	t_point3 orig;        // 카메라 원점(위치)
	double viewport_h;    // 뷰포트 세로길이
	double viewport_w;    // 뷰포트 가로길이
	t_vec3 horizontal;    // 수평길이 벡터
	t_vec3 vertical;      // 수직길이 벡터
	double focal_len;     // focal length
	t_point3 left_bottom; // 왼쪽 아래 코너점
};

struct						s_canvas
{
	int width;           //canvas width
	int height;          //canvas height;
	double aspect_ratio; //종횡비
};

struct						s_sphere
{
	t_point3				center;
	double					radius;
	double					radius2;
};

struct						s_hit_record
{
	t_point3 p;    // 교점의 좌표
	t_vec3 normal; // 교점에서의 법선
	double					tmin;
	double					tmax;
	double t; // 광선의 원점과 교점 사이의 거리.
	bool					front_face;
};

struct						s_object
{
	t_object_type			type;
	void					*element;
	void					*next;
};

struct						s_img
{
	void					*img;
	char					*addr;
	int						bpp;
	int						line;
	int						endian;
};

struct						s_mlx
{
	void					*mlx;
	void					*win;
	t_img					img;
};

struct						s_meta
{
	t_mlx					mlx;
};

#endif