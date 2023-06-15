/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 20:08:34 by sanghwal          #+#    #+#             */
/*   Updated: 2023/06/15 20:48:22 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "render.h"

static bool	is_valid_height(double t, t_cylinder *cy, t_ray *ray)
{
	t_vec3	intersect_point;
	double	res;

	res = 0;
	if (t < 0)
		return (false);
	// 교점의 좌표를 계산합니다.
	intersect_point = ray_at(ray, t);

	// 교점에서 원기둥의 중심까지의 벡터를 계산합니다.
	t_vec3 vec_to_center = vec3_minus(intersect_point, cy->center_point);

	// 그 벡터를 원기둥의 방향 벡터로 투영합니다.
	double projected_length = vec3_inner_product(vec_to_center, cy->normal_vec3);

	// 투영된 길이의 절대값이 원기둥의 높이 범위 내에 있는지 확인합니다.
	// 원기둥의 끝면에서 교점이 발생하는 경우를 포함하기 위해 등호를 추가합니다.
	res = fabs(projected_length);
	if (res == 0)
		return (false);
	else
		return (fabs(projected_length) <= cy->height / 2.0);
}

t_vec3 vec3_project(const t_vec3 a, const t_vec3 b)
{
    double magnitude_b = vec3_length(b);
    return vec3_scalar_multi(b, vec3_inner_product(a, b) / (magnitude_b * magnitude_b));
}

bool is_point_inside_cap(const t_vec3* p, const t_cylinder* cy)
{
    // 교점에서 원기둥 중심까지의 벡터를 계산합니다.
    t_vec3 p_to_c = vec3_minus(*p, cy->center_point);

    // 이 벡터를 원기둥의 방향 벡터로 투영합니다.
    t_vec3 projection = vec3_project(p_to_c, cy->normal_vec3);

    // 투영 벡터의 길이를 계산합니다.
    double distance = vec3_length(projection);

    // 이 길이가 원기둥의 반지름보다 작거나 같으면, 교점은 원기둥의 cap 내에 있습니다.
    return distance <= (cy->diameter / 2) && p->z >= cy->center_point.z && p->z <= cy->center_point.z + cy->height;
}

// bool is_valid_height2(double t, const t_cylinder* cy, const t_ray* ray)
// {
//     t_vec3 p = ray_at((t_ray *)ray, t);

//     // 교점이 원기둥의 높이 범위 내에 있는지 확인합니다.
//     double height = vec3_inner_product(vec3_minus(p, cy->center_point), cy->normal_vec3);
//     bool height_valid = 0 <= height && height <= cy->height;

//     // 교점이 원기둥의 cap 내에 있는지 확인합니다.
//     bool inside_cap = is_point_inside_cap(&p, cy);

//     // 두 조건을 모두 만족하면, 이 교점은 유효합니다.
//     return height_valid && inside_cap;
// }

double distance(t_vec3 a, t_vec3 b)
{
    double dx = b.x - a.x;
    double dy = b.y - a.y;
    double dz = b.z - a.z;

    return sqrt(dx*dx + dy*dy + dz*dz);
}

bool	is_valid_height2(double t, const t_cylinder* cy, const t_ray* ray)
{
	t_vec3	top_circle = vec3_plus(cy->center_point, vec3_scalar_multi(cy->normal_vec3, cy->height / 2));
	// t_vec3	bot_circle = vec3_minus(cy->center_point, vec3_scalar_multi(cy->normal_vec3, cy->height / 2));

	t_vec3	t_to_q = vec3_minus(ray_at((t_ray *)ray, t), top_circle);
	double	dot = vec3_inner_product(t_to_q, cy->normal_vec3);
	
	if (dot != 0)
		return (false);
	double	len = distance(ray_at((t_ray *)ray, t), top_circle);
	if (dot == 0 && len >= 0 && len <= cy->diameter / 2)
		return (true);
	return (false);
}

bool	is_valid_height3(double t, const t_cylinder* cy, const t_ray* ray)
{
	// t_vec3	top_circle = vec3_plus(cy->center_point, vec3_scalar_multi(cy->normal_vec3, cy->height / 2));
	t_vec3	bot_circle = vec3_minus(cy->center_point, vec3_scalar_multi(cy->normal_vec3, cy->height / 2));

	t_vec3	t_to_q = vec3_minus(ray_at((t_ray *)ray, t), bot_circle);
	double	dot = vec3_inner_product(t_to_q, cy->normal_vec3);
	
	if (dot != 0)
		return (false);
	double	len = distance(ray_at((t_ray *)ray, t), bot_circle);
	if (dot == 0 && len >= 0 && len <= cy->diameter / 2)
		return (true);
	return (false);
}

static double	calculate_infinite_cylinder_t(t_cylinder *cy, t_ray *ray)
{
	const t_vec3	c_to_o = vec3_minus(ray->origin, cy->center_point);
	const double	a = vec3_inner_product(vec3_minus(ray->direction,
				vec3_scalar_multi(cy->normal_vec3,
					vec3_inner_product(ray->direction, cy->normal_vec3))),
			vec3_minus(ray->direction,
				vec3_scalar_multi(cy->normal_vec3,
					vec3_inner_product(ray->direction, cy->normal_vec3))));
	const double	b = 2.0 * vec3_inner_product(vec3_minus(ray->direction,
				vec3_scalar_multi(cy->normal_vec3,
					vec3_inner_product(ray->direction, cy->normal_vec3))),
			vec3_minus(c_to_o, vec3_scalar_multi(cy->normal_vec3,
					vec3_inner_product(c_to_o, cy->normal_vec3))));
	const double	c = vec3_inner_product(vec3_minus(c_to_o, vec3_scalar_multi(cy->normal_vec3, vec3_inner_product(c_to_o, cy->normal_vec3))), vec3_minus(c_to_o, vec3_scalar_multi(cy->normal_vec3, vec3_inner_product(c_to_o, cy->normal_vec3)))) - ((cy->diameter / 2.0) * (cy->diameter / 2.0));
	double			root[2];

	if (root_formula(a, b, c, root) == false)
		return (0);
	if (!is_valid_height(root[0], cy, ray) && !is_valid_height(root[1], cy, ray))
		return (0);
	if (root[0] > 0 && is_valid_height(root[0], cy, ray))
		return (root[0]);
	if (root[1] > 0)
		return (root[1] && is_valid_height(root[1], cy, ray));
	return (0);
}

static double	calculate_cap_cylinder_t(t_cylinder *cy, t_ray *ray)
{
	const double	top_t = vec3_inner_product(vec3_minus(vec3_plus(cy->center_point, vec3_scalar_multi(cy->normal_vec3, cy->height / 2)), ray->origin), cy->normal_vec3) / vec3_inner_product(ray->direction, cy->normal_vec3);
	const double	bottom_t = vec3_inner_product(vec3_minus(vec3_minus(cy->center_point, vec3_scalar_multi(cy->normal_vec3, cy->height / 2)), ray->origin), vec3_scalar_multi(cy->normal_vec3, -1)) / vec3_inner_product(ray->direction, vec3_scalar_multi(cy->normal_vec3, -1));
	const bool		top_valid = is_valid_height2(top_t, cy, ray);
	const bool		bottom_valid = is_valid_height3(bottom_t, cy, ray);

	// printf("t: %f, b: %f", top_t, bottom_t);
	if (top_valid && bottom_valid)
	{
		if (top_t < bottom_t)
		{
			cy->p_type = TOP;
			return (top_t);
		}
		else
		{
			cy->p_type = BOT;	
			return (bottom_t);
		}
	}
	else if (top_valid)
	{
		cy->p_type = TOP;
		return (top_t);
	}
	else if (bottom_valid)
	{
		cy->p_type = BOT;
		return (bottom_t);
	}
	else
	{
		// printf("return 0\n");
		return 0;
	}
}

double	get_cylinder_dist(t_obj *obj, const t_ray *ray)
{
	t_cylinder	*cylinder;
	double		infinite_t;
	double		cap_t;
	double		t;

	t = 0;
	cylinder = &(obj->content.cylinder);
	cylinder->normal_vec3 = vec3_unit(cylinder->normal_vec3);
	infinite_t = calculate_infinite_cylinder_t(cylinder, (t_ray *)ray);
	cylinder->p_type = INF;
	cap_t = calculate_cap_cylinder_t(cylinder, (t_ray *)ray);
	// printf(" cap_t: %f infi_t: %f\n", cap_t, infinite_t);
	if (infinite_t <= 0 && cap_t <= 0)
		return (0);
	if (infinite_t > 0 && cap_t > 0)
	{
		if (infinite_t < cap_t)
		{
			// printf(" result_t: %f\n", infinite_t);
			return (infinite_t);
		}
		else
		{
			// printf(" result_t: %f\n", cap_t);
			return (cap_t);
		}
	}
	else if (cap_t > 0)
	{
		// printf(" result_t: %f\n", cap_t);
		return (cap_t);
	}
	else if (infinite_t > 0)
	{
		cylinder->p_type = INF;
		// printf(" result_t: %f\n", infinite_t);
		return (infinite_t);
	}
	// printf(" result_t: %f\n", t);
	return (infinite_t);
}

t_object_type	get_cylinder_record(t_obj *obj, t_ray *ray, t_record *record)
{
	const t_cylinder	cylinder = obj->content.cylinder;
	t_vec3				projected_point;

	record->obj = &obj->content;
	record->point = ray_at(ray, record->t);
	if (cylinder.p_type == INF)
		projected_point = vec3_plus(cylinder.center_point, vec3_scalar_multi(cylinder.normal_vec3, vec3_inner_product(vec3_minus(record->point, cylinder.normal_vec3), cylinder.normal_vec3)));
	if (cylinder.p_type == TOP)
		projected_point = vec3_plus(cylinder.center_point, vec3_scalar_multi(cylinder.normal_vec3, cylinder.height / 2));
	if (cylinder.p_type == BOT)
		projected_point = vec3_minus(cylinder.center_point, vec3_scalar_multi(cylinder.normal_vec3, cylinder.height / 2));
	record->normal_vec3 = vec3_unit(vec3_minus(record->point, projected_point));
	set_face_normal(ray, record);
	return (obj->type);
}

t_rgba	get_cylinder_color(union u_obj *obj)
{
	const t_cylinder	cylinder = obj->cylinder;

	return (cylinder.rgba);
}
