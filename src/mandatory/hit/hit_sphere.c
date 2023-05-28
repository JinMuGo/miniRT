/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:40:14 by jgo               #+#    #+#             */
/*   Updated: 2023/05/28 16:43:41 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "struct.h"
#include "trace.h"
#include "utils.h"

bool	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vec3 oc; //방향벡터로 나타낸 구의 중심.
	//a, half_b, c는 각각 t에 관한 2차 방정식의 계수
	double a;
	double half_b;
	double c;
	double discriminant; //판별식
	double sqrtd;
	double root;
	t_sphere *sp = world->element;

	oc = vminus(ray->orig, sp->center);
	// a = vdot(ray->dir, ray->dir);
	// half_b = 2.0 * vdot(oc, ray->dir);
	// c = vdot(oc, oc) - sp->radius2;
	// // discriminant 는 판별식
	// discriminant = half_b * half_b - 4 * a * c;

	// // 판별식이 0보다 크다면 광선이 구를 hit한 것!
	// if (discriminant < 0)
	// 	return (-1.0);
	// return ((-half_b - sqrt(discriminant)) / (2.0 * a));
	a = vlength2(ray->dir);
	half_b = vdot(oc, ray->dir);
	c = vlength2(oc) - sp->radius2;
	discriminant = half_b * half_b - a * c;

	if (discriminant < 0)
		return (false);
	sqrtd = sqrt(discriminant);
	root = (-half_b - sqrtd) / a;
	if (root < rec->tmin || rec->tmax < root)
	{
		root = (-half_b + sqrtd) / a;
		if (root < rec->tmin || rec->tmax < root)
			return (false);
	}
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = vdivide(vminus(rec->p, sp->center), sp->radius);
	// 정규화된 법선 벡터.
	set_face_normal(ray, rec);
	// rec의 법선벡터와 광선의 방향벡터를 비교해서 앞면인지 뒷면인지 bool 값으로 저장.
	return (true);
}