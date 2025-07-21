/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alshakhp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 11:31:47 by alshakhp          #+#    #+#             */
/*   Updated: 2025/07/21 11:31:49 by alshakhp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static t_sprite	*sprite_init(t_data *data, int i, int j)
{
    t_sprite *sprite;
    
    sprite = malloc(sizeof(t_sprite));
	if (!(sprite))
		error_msg_exit(data, "Error mallocing sprite");
    sprite->x = j + 0.5;
    sprite->y = i + 0.5;
    sprite->texture = 0; 
    return sprite;
}

static void add_sprite_to_list(t_data *data, t_sprite *sprite)
{
	if (data->sprites->sprite_count >= data->sprites->sprite_capacity)
	{
		data->sprites->sprite_capacity *= 2;
		t_sprite *new_array = realloc(data->sprites->sprite,
			sizeof(t_sprite ) * data->sprites->sprite_capacity);
		if (!new_array)
			error_msg_exit(data, "Failed to realloc sprite array");
		data->sprites = new_array;
	}
	data->sprites->sprite[data->sprites->sprite_count++] = *sprite;
    free(sprite);
}
static void init_sprites(t_data *data)
{
	data->sprites = malloc(sizeof(t_sprites));
	if (!data->sprites)
		error_msg_exit(data, "Failed to malloc sprite struct");

	data->sprites->sprite_capacity = 10;
	data->sprites->sprite_count = 0;
	data->sprites->sprite = malloc(sizeof(t_sprite) * data->sprites->sprite_capacity);
	if (!data->sprites->sprite)
		error_msg_exit(data, "Failed to malloc sprite array");
}
void	check_tile_sprite(t_data *data, int i, int j)
{
	if (i == 0 || j == 0 || \
			i == data->map->height - 1 || j == data->map->width - 1)
		error_msg_exit(data, "Sprite on the map edge not allowed");
	if (data->map->tiles[i - 1][j] == tile_empty ||
		data->map->tiles[i + 1][j] == tile_empty ||
		data->map->tiles[i][j - 1] == tile_empty ||
		data->map->tiles[i][j + 1] == tile_empty)
		error_msg_exit(data, "Sprite next to void. Don't do that.");
    if (data->sprites == NULL)
        init_sprites(data);
    t_sprite *sprite = sprite_init(data, i, j);
    add_sprite_to_list(data, sprite);

}