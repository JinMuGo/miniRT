/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/09 17:17:14 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "defs.h"
#include "design_patterns.h"
#include "utils.h"
#include "parser.h"

void print_ambient(t_meta *meta) {
	printf("===ambient===\n");
	printf("Type: %d\n", meta->ambient.type);
	printf("Ratio: %f\n", meta->ambient.ratio);
	printf("RGB: %f, %f, %f\n", meta->ambient.rgb.r, meta->ambient.rgb.g, meta->ambient.rgb.b);
}

void print_camera(t_meta *meta) {
	printf("===camera===\n");
	printf("Type: %d\n", meta->camera.type);
	printf("Point: %f, %f, %f\n", meta->camera.view_point.x, meta->camera.view_point.y, meta->camera.view_point.z);
	printf("Vec: %f, %f, %f\n", meta->camera.normal_vec3.x, meta->camera.normal_vec3.y, meta->camera.normal_vec3.z);
	printf("FOV: %f\n", meta->camera.fov);
}

void print_light(t_meta *meta) {
	printf("===light===\n");
	t_list *current = meta->spot_lights;
	while (current != NULL) {
		t_spot_light *light = (t_spot_light *)current->content;
		printf("Light point: %f, %f, %f\n", light->light_point.x, light->light_point.y, light->light_point.z);
		printf("Ratio: %f\n", light->ratio);
		printf("RGB: %f, %f, %f\n", light->rgb.r, light->rgb.g, light->rgb.b);
		free(light);
		current = current->next;
	}
}

void print_objs(t_meta *meta)
{
	printf("===objs===\n");
	t_list	*current = meta->objs;
	while (current != NULL) {
		if (((t_sphere *)current->content)->type == SP)
		{
			printf(">>>sphere<<<\n");
			t_sphere *sphere = (t_sphere *)current->content;
			printf("Center point: %f, %f, %f\n", sphere->center_point.x, sphere->center_point.y, sphere->center_point.z);
			printf("Diameter: %f\n", sphere->diameter);
			printf("RGB: %f, %f, %f\n", sphere->rgb.r, sphere->rgb.g, sphere->rgb.b);
		}
		else if (((t_plane *)current->content)->type == PL)
		{
			printf(">>>plane<<<\n");
			t_plane	*plane = (t_plane *)current->content;
			printf("Point: %f, %f, %f\n", plane->point.x, plane->point.y, plane->point.z);
			printf("Vec3: %f, %f, %f\n", plane->normal_vec3.x, plane->normal_vec3.y, plane->normal_vec3.z);
			printf("RGB: %f, %f, %f\n", plane->rgb.r, plane->rgb.g, plane->rgb.b);
		}
		else if (((t_cylinder *)current->content)->type == CY)
		{
			printf(">>>cylinder<<<\n");
			t_cylinder	*cylinder = (t_cylinder *)current->content;
			printf("Point: %f, %f, %f\n", cylinder->center_point.x, cylinder->center_point.y, cylinder->center_point.z);
			printf("Vec3: %f, %f, %f\n", cylinder->normal_vec3.x, cylinder->normal_vec3.y, cylinder->normal_vec3.z);
			printf("diameter: %f\n", cylinder->diameter);
			printf("height: %f\n", cylinder->height);
			printf("RGB: %f, %f, %f\n", cylinder->rgb.r, cylinder->rgb.g, cylinder->rgb.b);
		}
		current = current->next;
	}
}

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