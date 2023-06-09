/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/09 17:18:56 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "design_patterns.h"
#include "utils.h"
#include "parser.h"

int main(void) {
	char *s_amb = "A 0.2 255,255,255";
	char *s_cam = "C -50.0,0,20 0,0,1 70";
	char *s_light = "L ,,50.0 0.0 10,0,255";
	char *s_sphere = "sp 0.0,0.0,20.6 12.6 10,0,255";
	char *s_plane = "pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225";
	char *s_cylinder = "cy 50.0,0.0,20.6 0.0,0.0,1.0 14.2 21.42 10,0,255";

	char **amb_temp = ft_split_whitespace(s_amb);
	char **cam_temp = ft_split_whitespace(s_cam);
	char **l_temp = ft_split_whitespace(s_light);
	char **sp_temp = ft_split_whitespace(s_sphere);
	char **pl_temp = ft_split_whitespace(s_plane);
	char **cy_temp = ft_split_whitespace(s_cylinder);

	printf("%s\n", s_amb);
	parser_ambient(amb_temp);

	printf("%s\n", s_cam);
	parser_camera(cam_temp);

	printf("%s\n", s_light);
	parser_light(l_temp);

	printf("%s\n", s_sphere);
	parser_sphere(sp_temp);

	printf("%s\n", s_plane);
	parser_plane(pl_temp);

	printf("%s\n", s_cylinder);
	parser_cylinder(cy_temp);

	t_meta *meta = singleton();

	print_ambient(meta);
	print_camera(meta);
	print_light(meta);
	print_objs(meta);

	free(meta);

	return (0);
}

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