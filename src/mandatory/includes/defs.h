/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghwal <sanghwal@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:10:23 by jgo               #+#    #+#             */
/*   Updated: 2023/06/13 18:47:02 by sanghwal         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include "const.h"
# include "enum.h"
# include "struct.h"

typedef double			(*t_get_obj_dist)(t_obj *, const t_ray *);
typedef t_rgba			(*t_get_obj_color)(union u_obj *);
typedef t_object_type	(*t_get_obj_record)(t_obj *, t_ray *, t_record *);

#endif
