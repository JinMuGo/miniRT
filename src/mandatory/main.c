/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:07:29 by jgo               #+#    #+#             */
/*   Updated: 2023/05/28 16:53:50 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "print.h"
#include "scene.h"
#include "struct.h"
#include "trace.h"
#include "utils.h"

int	main(void)
{
	int i;
	int j;
	double u;
	double v;
	t_color3 pixel_color;
	t_canvas canv;
	t_camera cam;
	t_ray ray;
	t_object *world;

	canv = canvas(400, 300);
	cam = camera(&canv, point3(0, 0, 0));
	world = object(SP, sphere(point3(-2, 0, -5), 2));
	oadd(&world, object(SP, sphere(point3(2, 0, -5), 2)));      // world 에 구2 추가
	oadd(&world, object(SP, sphere(point3(0, -1000, 0), 990))); // world 에 구3 추가
	printf("P3\n%d %d\n255\n", canv.width, canv.height);
	j = canv.height - 1;
	while (j >= 0)
	{
		i = 0;
		/* * * * 수정 * * * */
		while (i < canv.width)
		{
			u = (double)i / (canv.width - 1);
			v = (double)j / (canv.height - 1);
			//ray from camera origin to pixel
			ray = ray_primary(&cam, u, v);
			pixel_color = ray_color(&ray, world);
			/* * * * 수정 끝 * * * */
			write_color(pixel_color);
			++i;
		}
		--j;
	}

	return (0);
}