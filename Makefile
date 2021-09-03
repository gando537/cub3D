# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/28 15:26:11 by mdiallo           #+#    #+#              #
#    Updated: 2021/04/28 15:26:17 by mdiallo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MLX = -L /Users/Gando/Desktop/cub3D/minilibx_opengl_20191021 -lmlx -lm -framework OpenGL -framework AppKit

NAME = cub3D

SRCS = 	cub3d.c \
		utils/putstr_info.c \
		utils/get_next_line.c \
		utils/utils.c \
		utils/bitmap.c \
		sources/init_game.c \
		sources/treat_file/treat_size_window.c \
		sources/treat_file/treat_path.c \
		sources/treat_file/treat_color.c \
		sources/treat_file/other_funct.c \
		sources/treat_file/treat_file.c \
		sources/treat_file/treat_map.c \
		sources/control/key_control.c \
		sources/control/loop_control.c \
		sources/control/window_control.c \
		sources/draw/player.c \
		sources/draw/image.c \
		sources/draw/raycasting.c \
		sources/draw/raycasting_bis.c \
		sources/draw/textures.c \
		sources/draw/camera.c \
		sources/draw/draw_sprite.c \
		sources/draw/sprite.c

SRCS_BONUS = 	bonus/draw/bonus_camera.c \
				bonus/draw/bonus_health.c \
				bonus/control/bonus_key_control.c \
				bonus/draw/bonus_sound.c \
				bonus/init_bonus.c

OBJSRCS = $(SRCS:.c=.o) 
OBJSRCSBONUS = $(SRCS_BONUS:.c=.o)

$(NAME) : $(OBJSRCS) $(OBJSRCSBONUS)
	@rm -rf Cub3D
	@echo ""
	@echo "\033[32m[Compilation de libft...]"
	@echo ""
	@$(MAKE) bonus -C ./libft
	@echo ""
	@echo "\033[32m[Compilation du Jeu...]"
	@gcc $(OBJSRCSBONUS) $(OBJSRCS) -I./includes -I./usr/include -Wall -Wextra -Werror $(MLX) ./libft/libft.a -o $(NAME)
	@echo ""
	@echo "\033[32m[Fin de la Compilation... !]"

all : $(NAME)

clean :
	rm -rf $(OBJSRCS) $(OBJSRCSBONUS)
	$(MAKE) clean -C ./libft

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)
	rm -rf cub3d.bmp

re : fclean all

bonus : $(NAME)