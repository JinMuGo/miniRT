/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 19:26:51 by jgo               #+#    #+#             */
/*   Updated: 2023/05/28 09:17:39 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"
/* * * * 수정 * * * */
#include "scene.h"

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	if (!(sp = (t_sphere *)malloc(sizeof(t_sphere))))
		return (NULL);
	sp->center = center;
	sp->radius = radius;
	sp->radius2 = radius * radius;
	return (sp);
}
/* * * * 수정 끝 * * * */
