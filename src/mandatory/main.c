/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/11 16:11:37 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "design_patterns.h"
#include "utils.h"
#include "scene.h"
#include "parser.h"

// void	test_init(t_meta *meta)
// {
// 	const t_rgba amb_rgb = rgba_init(255, 255, 255, 255);
// 	const t_rgba pl_rgb = rgba_init(0, 0, 255, 255);
// 	const t_rgba sp_rgb = rgba_init(10, 0, 255, 255);
// 	const t_rgba cy_rgb = rgba_init(10, 0, 255, 255);
// 	const t_point3 cam_point = {-50.0, 0, 20};
// 	const t_point3 pl_point = {0.0, 0.0, -10.0};
// 	const t_point3 sp_center_point = {0.0, 0.0, 20.6};
// 	const t_point3 cy_center_point = {50.0, 0.0, 20.6};
	
// 	const t_point3 spot_light_point = {-40, 0, 30};
// 	const t_point3 cam_vec3 = {0.0, 0.0, 1.0};
// 	const t_vec3 pl_vec3 = {0.0, 1.0, 0.0};

// 	meta->ambient.type = AMB;
// 	meta->ambient.ratio = 0.2;
// 	meta->ambient.rgba = amb_rgb;
// 	meta->scene.camera.type = CAM;
// 	meta->scene.camera.view_point = cam_point;
// 	meta->scene.camera.normal_vec3 = cam_vec3;

// 	meta->spot_lights = ft_malloc(sizeof(t_spot_light));
// 	((t_spot_light *)(meta->spot_lights->content))->type = LIGHT;
// 	((t_spot_light *)(meta->spot_lights->content))->ratio = 0.7;
// 	((t_spot_light *)(meta->spot_lights->content))->rgba = amb_rgb;
// 	((t_spot_light *)(meta->spot_lights->content))->light_point = spot_light_point;

// 	meta->objs = ft_malloc(sizeof(t_list));
// 	meta->objs = ft_lstnew(ft_malloc(sizeof(t_plane)));
// 	ft_lstadd_back(&meta->objs, ft_lstnew(ft_malloc(sizeof(t_sphere))));
// 	ft_lstadd_back(&meta->objs, ft_lstnew(ft_malloc(sizeof(t_cylinder))));

// 	((t_plane *)(meta->objs->content))->type = PL;
// 	((t_plane *)(meta->objs->content))->point = pl_point;
// 	((t_plane *)(meta->objs->content))->normal_vec3 = pl_vec3;
// 	((t_plane *)(meta->objs->content))->rgba = pl_rgb;

// 	((t_sphere *)(meta->objs->next->content))->type = SP;
// 	((t_sphere *)(meta->objs->next->content))->center_point = sp_center_point;
// 	((t_sphere *)(meta->objs->next->content))->diameter = 12.6;
// 	((t_sphere *)(meta->objs->next->content))->rgba = sp_rgb;

// 	((t_cylinder *)(meta->objs->next->next->content))->type = CY;
// 	((t_cylinder *)(meta->objs->next->next->content))->center_point = cy_center_point;
// 	((t_cylinder *)(meta->objs->next->next->content))->diameter = 14.2;
// 	((t_cylinder *)(meta->objs->next->next->content))->height = 21.42;
// 	((t_cylinder *)(meta->objs->next->next->content))->rgba = cy_rgb;

// }

void check_leaks(void)
{
	system("leaks miniRT");
}

int	main(int ac, char **av)
{
	t_meta	*meta;

	atexit(check_leaks);
	if (ac != 2)
		return (error_handler(ARGS_ERR));
	parser(av[1]);
	meta = singleton();
	print_ambient(meta);
	print_camera(meta);
	print_light(meta);
	print_objs(meta);
	// test_init(meta);
	setup_scene(meta);

	mlx_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.img, 0, 0);
	mlx_loop_hook(meta->mlx_assets.mlx, hooks, meta);
	mlx_loop(meta->mlx_assets.mlx);
	ft_lstclear(&meta->spot_lights, free);
	objs_clear(&meta->objs, free);
	return (EXIT_SUCCESS);
}
