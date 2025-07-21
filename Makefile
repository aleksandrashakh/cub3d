NAME		= cube3d
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

SRC_DIR 	= src
OBJ_DIR 	= obj
LIBFT_DIR 	= libft
MINILIBX 	= minilibx-linux
LIBFT 		= $(LIBFT_DIR)/libft.a

SOURCE 		= src/main.c src/get_next_line.c src/get_next_line_utils.c \
			src/init/init.c src/init/parse_map_file.c src/init/parse_map_properties.c \
			src/init/parse_map_floor_ceiling.c src/init/parse_map_wall1.c src/init/parse_map_wall2.c \
			src/init/parse_map_tiles.c src/init/player_init.c src/init/check_map_init_player.c \
			src/hooks/keyhooks.c src/hooks/mousehooks.c src/hooks/open_door.c src/hooks/kill_the_sprite.c\
			src/move/move.c src/move/translate.c\
			src/render/draw.c src/render/raycast.c src/render/render_pov.c src/render/render_scene.c src/render/render_minimap.c \
			src/exit/exit.c src/exit/free.c src/exit/mlx_destroy.c \
			src/utils/hashtable1.c src/utils/hashtable2.c src/utils/math.c src/utils/utils_general1.c \
			src/utils/utils_general2.c src/utils/utils_parse.c src/utils/utils_rendering.c \

LIBRARY = -L$(MINILIBX) -lmlx -lX11 -lXext -lXrandr -lbsd -lm
INCLUDES = -I$(SRC_DIR) -I$(LIBFT_DIR)

all: $(NAME)

OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCE))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJECTS) $(LIBFT)
	make -C $(MINILIBX)
	$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME) $(LIBRARY)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	make clean -C $(MINILIBX)
	rm -f $(NAME)

re: fclean all