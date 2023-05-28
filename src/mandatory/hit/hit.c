/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:44:15 by jgo               #+#    #+#             */
/*   Updated: 2023/05/28 16:44:42 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* * * * 추가 * * * */
#include "defs.h"
#include "trace.h"

bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec; // temp_rec의 tmin, tmax 값 초기화를 위해.
	hit_anything = false;
	while (world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = true;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

// hit_obj는 오브젝트 타입에 맞는 hit함수로 연결해주는 관문
bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	bool	hit_result;

	hit_result = false;
	if (world->type == SP)
		hit_result = hit_sphere(world, ray, rec);
			//hit_sphere의 첫번째 인자도 t_sphere *에서 t_object *로 수정해주자.
	return (hit_result);
}
/* * * * 추가 끝 * * * */