/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 11:07:29 by jgo               #+#    #+#             */
/*   Updated: 2023/05/28 09:17:46 by jgo              ###   ########.fr       */
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
	t_sphere *sp;

	canv = canvas(400, 300);
	cam = camera(&canv, point3(0, 0, 0));
	sp = sphere(point3(0, 0, -5), 2);
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
			pixel_color = ray_color(&ray, sp);
			/* * * * 수정 끝 * * * */
			write_color(pixel_color);
			++i;
		}
		--j;
	}

	free(sp);
	return (0);
}