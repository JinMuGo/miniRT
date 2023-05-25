/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:10:23 by jgo               #+#    #+#             */
/*   Updated: 2023/05/25 18:25:19 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include "const.h"
# include "enum.h"

typedef struct s_mlx	t_mlx;
typedef struct s_img	t_img;
typedef struct s_meta	t_meta;

struct s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line;
	int		endian;
};

struct s_mlx {
	void	*mlx;
	void	*win;
	t_img	img;
};

struct s_meta {
	t_mlx	mlx;
};

#endif
