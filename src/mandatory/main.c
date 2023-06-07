/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:49:19 by jgo               #+#    #+#             */
/*   Updated: 2023/06/07 19:31:05 by sanghwal         ###   ########seoul.kr  */
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
	char	*str0 = "255,255,255";
	char	*str1 = ",255,255";
	char	*str2 = "255,,255";
	char	*str3 = "255,255,";
	char	*str4 = "255,,";
	char	*str5 = ",255,";
	char	*str6 = ",,25.5";

	t_rgb	rgb0 = parse_rgb(str0);
	t_rgb	rgb1 = parse_rgb(str1);
	t_rgb	rgb2 = parse_rgb(str2);
	t_rgb	rgb3 = parse_rgb(str3);
	t_rgb	rgb4 = parse_rgb(str4);
	t_rgb	rgb5 = parse_rgb(str5);
	t_rgb	rgb6 = parse_rgb(str6);
	
	(void)rgb0;
	(void)rgb1;
	(void)rgb2;
	(void)rgb3;
	(void)rgb4;
	(void)rgb5;
	(void)rgb6;
}