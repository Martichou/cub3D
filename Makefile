# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marandre <marandre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/21 20:24:19 by marandre          #+#    #+#              #
#    Updated: 2019/11/25 22:29:32 by marandre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

MINILIBX_PATH = ./minilibx_opengl

SRC_PATH = srcs
SRC_NAME = main.c utils.c move.c key.c ray.c draw.c \
		parser/parser.c parser/parse_color.c parser/parse_map.c \
		parser/parse_resolution.c parser/parse_textures.c parser/parse_sprite.c

OBJ_PATH = objs
OBJ_NAME = $(SRC_NAME:.c=.o)

CC = clang
CFLAGS = -Wall -Werror -Wextra

CPPFLAGS = -I includes -I libft -I minilibx_opengl
LDFLAGS = -L libft -L minilibx_opengl
LDLIBS = -lft -lm -lmlx -framework OpenGL -framework AppKit

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: libft minilibx_all $(NAME)

$(NAME): $(OBJ) libft/libft.a
	@$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@
	@echo "Compilation of cub3D:	\033[1;32mOK\033[m"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -pv $(OBJ_PATH)/parser 2> /dev/null || true
	@$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

libft:
	@make -C libft

clean:
	@make -C libft clean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "cub3D:	Removing Objs"

fclean:
	@make -C libft fclean
	@rm -f $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true
	@echo "cub3D:	Removing Objs"
	@rm -f $(NAME)
	@echo "cub3D:	Removing cub3D"

re: fclean all

minilibx_all:
	make -C $(MINILIBX_PATH) all

.PHONY: all clean fclean re libft
