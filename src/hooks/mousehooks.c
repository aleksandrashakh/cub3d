/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousehooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:31:02 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/19 15:31:04 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	hook_mouse(int x, int y, t_data *data)
{
	int	octant;

	(void) y;
	octant = SCREEN_WIDTH / 8;
	data->player->rot_left = (x < octant);
	data->player->rot_right = (x > SCREEN_WIDTH - octant);
	return (0);
}
