/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:08:43 by jgo               #+#    #+#             */
/*   Updated: 2023/06/30 10:52:54 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_BONUS_H
# define STRUCT_BONUS_H

# include "enum_bonus.h"
# include "minirt_bonus.h"

typedef struct s_mlx_assets	t_mlx_assets;
typedef struct s_vec3		t_rgb;
typedef struct s_ambient	t_ambient;
typedef struct s_ray		t_ray;
typedef struct s_canvas		t_canvas;
typedef struct s_camera		t_camera;
typedef struct s_scene		t_scene;
typedef struct s_spot_light	t_spot_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_cone		t_cone;
typedef struct s_vec3		t_point3;
typedef struct s_meta		t_meta;
typedef struct s_record		t_record;
typedef struct s_obj		t_obj;
typedef struct s_quad_coeff	t_quad_coeff;
typedef struct s_hooks		t_hooks;
typedef struct s_renderer	t_renderer;
typedef struct s_thd_pool	t_thd_pool;
typedef struct s_mlx_image	t_mlx_image;
typedef struct s_cb			t_cb;
typedef struct s_bp			t_bp;
typedef struct s_tx			t_tx;
typedef struct s_obj_option	t_obj_option;

typedef double				(*t_get_obj_dist)(t_obj *, const t_ray *);
typedef t_object_type		(*t_get_obj_record)(t_obj *, const t_ray *,
			t_record *);

struct						s_quad_coeff
{
	double					a;
	double					b;
	double					c;
};

struct						s_cb
{
	t_rgb					rgb;
	float					degree;
	float					scale_s;
	float					scale_t;
};

struct						s_mlx_image
{
	t_mlx_image_type		type;
	mlx_image_t				*img;
};

struct						s_tx
{
	t_mlx_image				img;
	t_uv					uv;
	t_vec3					up;
	t_vec3					right;
	t_mlx_image				*bp;
};

union						u_obj_option
{
	t_cb					cb;
	t_tx					tx;
};

struct						s_obj_option
{
	t_obj_option_type		type;
	union u_obj_option		op;
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
	t_vec3					forward;
	t_vec3					up;
	t_vec3					right;
	double					fov;
	double					viewport_h;
	double					viewport_w;
	t_vec3					horizontal;
	t_vec3					vertical;
	double					focal_len;
	t_point3				left_bottom;
	double					pitch;
	double					yaw;
	t_vec3					pos;
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
	double					radius;
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
	t_cy_type				p_type;
	t_point3				center_point;
	t_vec3					normal_vec3;
	double					diameter;
	double					height;
	t_rgb					rgb;
};

struct						s_cone
{
	t_object_type			type;
	t_co_type				co_type;
	t_point3				base_point;
	t_vec3					normal_vec3;
	double					radius;
	double					height;
	t_rgb					rgb;
};

struct						s_ray
{
	t_point3				origin;
	t_vec3					direction;
};

struct						s_record
{
	t_point3				point;
	t_vec3					normal_vec3;
	double					t;
	t_rgb					rgb;
};

struct						s_canvas
{
	int						width;
	int						height;
	double					aspect_ratio;
};

struct						s_scene
{
	t_canvas				canvas;
	t_ray					ray;
};

union						u_obj
{
	t_sphere				sphere;
	t_plane					plane;
	t_cylinder				cylinder;
	t_cone					cone;
};

struct						s_obj
{
	t_object_type			type;
	t_get_obj_dist			get_t;
	t_get_obj_record		set_r;
	union u_obj				content;
	t_obj_option			*option;
	t_obj					*next;
};

struct						s_hooks
{
	bool					mouse_left;
	bool					mouse_right;
	double					prev_pos[2];
};

struct						s_renderer
{
	int						x;
	int						y;
	int						width;
	int						height;
	t_meta					*meta;
};

struct						s_thd_pool
{
	pthread_t				*tids;
	t_renderer				*rendrer;
};

struct						s_meta
{
	t_mlx_assets			mlx_assets;
	t_ambient				ambient;
	t_scene					scene;
	t_camera				camera;
	t_hooks					hooks;
	t_thd_pool				thd_pool;
	t_list					*spot_lights;
	t_obj					*objs;
};

#endif
