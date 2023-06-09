/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/09 16:49:14 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "design_patterns.h"
#include "utils.h"
#include "scene.h"

static inline	void test_init(t_meta *meta)
{
	const t_rgba amb_rgb = rgb_init(255, 255, 255, 255);
	const t_rgba pl_rgb = rgb_init(0, 0, 255, 255);
	const t_rgba sp_rgb = rgb_init(10, 0, 255, 255);
	const t_rgba cy_rgb = rgb_init(10, 0, 255, 255);
	const t_point3 cam_point = {-50.0, 0, 20};
	const t_point3 pl_point = {0.0, 0.0, -10.0};
	const t_point3 sp_center_point = {0.0, 0.0, 20.6};
	const t_point3 cy_center_point = {50.0, 0.0, 20.6};
	
	const t_point3 spot_light_point = {-40, 0, 30};
	const t_point3 cam_vec3 = {0.0, 0.0, 1.0};
	const t_vec3 pl_vec3 = {0.0, 1.0, 0.0};

	meta->ambient.type = AMB;
	meta->ambient.ratio = 0.2;
	meta->ambient.rgb = amb_rgb;
	meta->scene.camera.type = CAM;
	meta->scene.camera.view_point = cam_point;
	meta->scene.camera.normal_vec3 = cam_vec3;

	meta->spot_lights = ft_malloc(sizeof(t_light));
	meta->spot_lights->type = LIGHT;
	meta->spot_lights->ratio = 0.7;
	meta->spot_lights->rgb = amb_rgb;
	meta->spot_lights->light_point = spot_light_point;

	meta->objs = ft_malloc(sizeof(t_list));
	meta->objs = ft_lstnew(ft_malloc(sizeof(t_plane)));
	ft_lstadd_back(&meta->objs, ft_lstnew(ft_malloc(sizeof(t_sphere))));
	ft_lstadd_back(&meta->objs, ft_lstnew(ft_malloc(sizeof(t_cylinder))));

	((t_plane *)(meta->objs->content))->type = PL;
	((t_plane *)(meta->objs->content))->point = pl_point;
	((t_plane *)(meta->objs->content))->normal_vec3 = pl_vec3;
	((t_plane *)(meta->objs->content))->rgb = pl_rgb;

	((t_sphere *)(meta->objs->next->content))->type = SP;
	((t_sphere *)(meta->objs->next->content))->center_point = sp_center_point;
	((t_sphere *)(meta->objs->next->content))->diameter = 12.6;
	((t_sphere *)(meta->objs->next->content))->rgb = sp_rgb;

	((t_cylinder *)(meta->objs->next->next->content))->type = CY;
	((t_cylinder *)(meta->objs->next->next->content))->center_point = cy_center_point;
	((t_cylinder *)(meta->objs->next->next->content))->diameter = 14.2;
	((t_cylinder *)(meta->objs->next->next->content))->height = 21.42;
	((t_cylinder *)(meta->objs->next->next->content))->rgb = cy_rgb;

}

int	main(int ac, char **av)
{
	t_meta	*meta;

	(void)ac;
	(void)av;
	meta = singleton();
	test_init(meta);
	setup_scene(meta);
	mlx_image_to_window(meta->mlx_assets.mlx, meta->mlx_assets.img, 0, 0);
	mlx_loop_hook(meta->mlx_assets.mlx, hooks, meta);
	mlx_loop(meta->mlx_assets.mlx);
	return (EXIT_SUCCESS);
}
