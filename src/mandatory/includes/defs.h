/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:10:23 by jgo               #+#    #+#             */
/*   Updated: 2023/06/11 12:15:58 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include "const.h"
# include "enum.h"
# include "struct.h"

typedef struct s_mlx_assets	t_mlx_assets;
typedef struct s_rgba		t_rgba;
typedef struct s_ambient	t_ambient;
typedef struct s_ray		t_ray;
typedef struct s_canvas		t_canvas;
typedef struct s_camera		t_camera;
typedef struct s_scene		t_scene;
typedef struct s_spot_light	t_spot_light;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_vec3		t_point3;
typedef struct s_meta		t_meta;
typedef struct s_record		t_record;
typedef struct s_obj		t_obj;

typedef double				(*t_get_obj_dist)(t_list *obj, *t_ray,
					*t_record);

union						u_obj
{
	t_sphere				sphere;
	t_plane					plane;
	t_cylinder				cylinder;
};

#endif
