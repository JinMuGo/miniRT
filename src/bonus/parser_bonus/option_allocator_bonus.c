/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_allocator_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:30:54 by jgo               #+#    #+#             */
/*   Updated: 2023/06/30 19:36:25 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"
#include "defs_bonus.h"
#include "parser_bonus.h"
#include "utils_bonus.h"

static inline int	check_bump_file_name(const char *origin, const char *path)
{
	const char	*tmp = ft_remove_suffix(origin);
	const char	*s1 = ft_strjoin(tmp, "_bump");
	const char	*s2 = ft_remove_suffix(path);
	const int	rv = ft_strcmp(s1, s2);

	ft_free_n(3, tmp, s1, s2);
	return (rv);
}

static inline void	_bp_allocator(
		t_tx *tx, t_error_type err, const char *origin, const char *path)
{
	const char	*origin_file_name = ft_strrchr(origin, '/');
	const char	*path_file_name = ft_strrchr(path, '/');

	if (origin_file_name == NULL || path_file_name == NULL
		|| check_bump_file_name(origin_file_name, path_file_name))
		error_handler(err);
	tx->bp = ft_malloc(sizeof(t_mlx_image));
	open_mlx_image(tx->bp, err, path);
	if (tx->img.img->width != tx->bp->img->width
		&& tx->img.img->height != tx->bp->img->height)
		error_handler(err);
}

static inline t_obj_option	*_cb_allocator(char **line, int idx)
{
	t_obj_option	*option;

	option = ft_malloc(sizeof(t_obj_option));
	option->type = CB;
	option->op.cb.rgb = parser_vec3(line[idx++], RGB_ERR);
	option->op.cb.scale_s = check_to_double(line[idx++]);
	option->op.cb.scale_t = check_to_double(line[idx++]);
	option->op.cb.degree = check_to_double(line[idx++]);
	return (option);
}

static inline t_obj_option	*_tx_allocator(
		char **line, int idx, t_error_type err)
{
	const char		*tx_path = line[++idx];
	t_obj_option	*option;

	option = ft_malloc(sizeof(t_obj_option));
	option->type = TX;
	open_mlx_image(&option->op.tx.img, err, tx_path);
	if (line[++idx] && !ft_strcmp(line[idx], "bp"))
		_bp_allocator(&option->op.tx, SP_ERR, tx_path, line[++idx]);
	else
		option->op.tx.bp = NULL;
	return (option);
}

t_obj_option	*option_allocator(char **line, int idx, t_error_type err)
{
	if (line[idx] == NULL)
		return (NULL);
	else if (!ft_strcmp(line[idx], "cb"))
		return (_cb_allocator(line, ++idx));
	else if (!ft_strcmp(line[idx], "tx"))
		return (_tx_allocator(line, idx, err));
	else
		error_handler(OPT_ERR);
	return (NULL);
}
