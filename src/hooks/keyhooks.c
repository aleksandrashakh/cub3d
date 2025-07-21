/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:07:38 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/19 15:07:39 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	handle_key(int keycode, t_data *data, bool pressed)
{
	if (keycode == KEY_W)
		data->player->mov_forward = pressed;
	if (keycode == KEY_S)
		data->player->mov_backward = pressed;
	if (keycode == KEY_A)
		data->player->strafe_left = pressed;
	if (keycode == KEY_D)
		data->player->strafe_right = pressed;
	if (keycode == KEY_ARROW_LEFT)
		data->player->rot_left = pressed;
	if (keycode == KEY_ARROW_RIGHT)
		data->player->rot_right = pressed;
}

int	hook_key_press(int keycode, t_data *data)
{
	handle_key(keycode, data, true);
	return (0);
}

int	hook_key_release(int keycode, t_data *data)
{
	if (keycode == KEY_ESCAPE)
		cub_exit(data, 0);
	if (keycode == KEY_E)
		open_door(data);
	if (keycode == KEY_F)
		kill_the_sprite(data);
	handle_key(keycode, data, false);
	return (0);
}
int	hook_exit(t_data *data)
{
	cub_exit(data, 0);
	return (0);
}