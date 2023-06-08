/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/08 16:45:50 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "design_patterns.h"
#include "utils.h"
#include "parser.h"

// int	main(int ac, char **av)
// {
// 	t_meta	*meta;

// 	(void)ac;
// 	(void)av;
// 	meta = singleton();
// 	mlx_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.img, 0, 0);
// 	mlx_loop_hook(meta->mlx_assets.mlx, hooks, meta);
// 	mlx_loop(meta->mlx_assets.mlx);
// 	return (EXIT_SUCCESS);
// }

int	main(void)
{
	char *str1 = "A 0.2 255,255,255";
	char *str2 = "C -50.0,0,20 0,0,1 70";

	char **temp1 = ft_split_whitespace(str1);
	char **temp2 = ft_split_whitespace(str2);

	parse_ambient(temp1);
	parse_camera(temp2);

	t_meta *meta = singleton();
	printf("===ambient===\n");
	printf("type: %d, ratio: %f, rgb: %d, %d, %d\n", meta->ambient.type, meta->ambient.ratio, meta->ambient.rgb.r, meta->ambient.rgb.g, meta->ambient.rgb.b);

	printf("===camera===\n");
	printf("type: %d, point: %f, %f, %f, vec: %f, %f, %f, fov: %f\n", meta->camera.type, meta->camera.view_point.x, meta->camera.view_point.y, meta->camera.view_point.z, meta->camera.normal_vec3.x, meta->camera.normal_vec3.y, meta->camera.normal_vec3.z, meta->camera.fov);
	return (0);
}
