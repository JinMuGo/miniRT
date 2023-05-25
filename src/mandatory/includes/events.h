/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 15:55:05 by jgo               #+#    #+#             */
/*   Updated: 2023/05/25 18:24:42 by jgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# define KEY_PRESS			2
# define KEY_RELEASE		3
# define MOUSE_PRESS		4
# define MOUSE_RELEASE		5
# define MOTION_NOTIFY		6
# define ENTER_NOTIFY		7
# define LEAVE_NOTIFY		8
# define FOCUS_IN			9
# define FOCUS_OUT			10
# define KEYMAP_NOTIFY		11
# define EXPOSE				12
# define GRAPHICS_EXPOSE	13
# define NO_EXPOSE			14
# define VISIBILITY_NOTIFY	15
# define CREATE_NOTIFY		16
# define DESTROY_NOTIFY		17
# define UNMAP_NOTIFY		18
# define MAP_NOTIFY			19
# define MAP_REQUEST		20
# define REPARENT_NOTIFY	21
# define CONFIGURE_NOTIFY	22
# define CONFIGURE_REQUEST	23
# define GRAVITY_NOTIFY		24

/*
#define ResizeRequest           25
#define CirculateNotify         26
#define CirculateRequest        27
#define PropertyNotify          28
#define SelectionClear          29
#define SelectionRequest        30
#define SelectionNotify         31
#define ColormapNotify          32
#define ClientMessage           33
#define MappingNotify           34
#define GenericEvent            35
#define LASTEvent               36
*/

#endif
