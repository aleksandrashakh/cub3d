/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:50:31 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/19 15:50:33 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	translate_forward(t_data *data, t_player *p)
{
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y)][(int)(p->x + p->dir_x * MOV_STEP)]))
		p->x += p->dir_x * MOV_STEP;
	else
		p->x = (int)(p->x + p->dir_x * MOV_STEP) + \
				(p->dir_x > 0) * (-0.01) + (p->dir_x < 0) * (1.01);
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y + p->dir_y * MOV_STEP)][(int)(p->x)]))
		p->y += p->dir_y * MOV_STEP;
	else
		p->y = (int)(p->y + p->dir_y * MOV_STEP) + \
				(p->dir_y > 0) * (-0.01) + (p->dir_y < 0) * (1.01);
}

void	translate_backward(t_data *data, t_player *p)
{
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y)][(int)(p->x - p->dir_x * MOV_STEP)]))
		p->x -= p->dir_x * MOV_STEP;
	else
		p->x = (int)(p->x - p->dir_x * MOV_STEP) + \
				(p->dir_x > 0) * (1.01) + (p->dir_x < 0) * (-0.01);
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y - p->dir_y * MOV_STEP)][(int)(p->x)]))
		p->y -= p->dir_y * MOV_STEP;
	else
		p->y = (int)(p->y - p->dir_y * MOV_STEP) + \
				(p->dir_y > 0) * (1.01) + (p->dir_y < 0) * (-0.01);
}

void	translate_right(t_data *data, t_player *p)
{
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y)][(int)(p->x + p->plane_x * MOV_STEP)]))
		p->x += p->plane_x * MOV_STEP;
	else
		p->x = (int)(p->x + p->plane_x * MOV_STEP) + \
				(p->plane_x > 0) * (-0.01) + (p->plane_x < 0) * (1.01);
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y + p->plane_y * MOV_STEP)][(int)(p->x)]))
		p->y += p->plane_y * MOV_STEP;
	else
		p->y = (int)(p->y + p->plane_y * MOV_STEP) + \
				(p->plane_y > 0) * (-0.01) + (p->plane_y < 0) * (1.01);
}

void	translate_left(t_data *data, t_player *p)
{
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y)][(int)(p->x - p->plane_x * MOV_STEP)]))
		p->x -= p->plane_x * MOV_STEP;
	else
		p->x = (int)(p->x - p->plane_x * MOV_STEP) + \
				(p->plane_x > 0) * (1.01) + (p->plane_x < 0) * (-0.01);
	if (!is_wall_door_closed(data->map->tiles \
		[(int)(p->y - p->plane_y * MOV_STEP)][(int)(p->x)]))
		p->y -= p->plane_y * MOV_STEP;
	else
		p->y = (int)(p->y - p->plane_y * MOV_STEP) + \
				(p->plane_y > 0) * (1.01) + (p->plane_y < 0) * (-0.01);
}
