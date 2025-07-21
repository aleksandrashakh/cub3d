/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_sprites.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 12:17:59 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/21 12:18:00 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void sort_sprites_by_distance(t_data *data)
{
    int i;
    int j;
	t_sprite temp;

    i = 0;
    while (i < data->sprites->sprite_count - 1)
    {
        j = 0;
        while (j < data->sprites->sprite_count - i - 1)
        {
            if (data->sprites->sprite[j].distance < data->sprites->sprite[j + 1].distance)
            {
                temp = data->sprites->sprite[j];
				data->sprites->sprite[j] = data->sprites->sprite[j + 1];
				data->sprites->sprite[j + 1] = temp;
            }
            j++;
        }
        i++;
    }
}

void render_sprites(t_data *data, t_image *image)
{
    int i;

    i = 0;
    while (i < data->sprites->sprite_count)
    {
        t_sprite *sprite = &data->sprites->sprite[i];
		double dx = sprite->x - data->player->x;
		double dy = sprite->y - data->player->y;
		sprite->distance = dx * dx + dy * dy;
        i++;
    }
    sort_sprites_by_distance(data);
    i = 0;
    while (i < data->sprites->sprite_count)
        draw_sprite(data, image, &data->sprites->sprite[i]);

}
