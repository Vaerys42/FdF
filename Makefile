# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kboucaud <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/07 15:57:59 by kboucaud          #+#    #+#              #
#    Updated: 2017/03/07 15:58:03 by kboucaud         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = 	src/main.c \
		src/conv.c \
		src/ft_get_file.c \
		src/file_x.c \
		src/file_y.c \
		src/line.c \
		src/color.c \
		src/draw_seg.c \
		src/error.c \
		src/length.c \
		src/seg.c \
		src/mlx.c \
		src/alt.c \
		src/down.c \

LIBS = -framework OpenGL -framework Appkit minilibx_macos/libmlx.a libft/libft.a

OBJ = $(patsubst src/%.c,obj/%.o,$(SRC))

.SILENT :

all : $(NAME)

$(NAME) : $(OBJ)
		make -C libft/
		make -C minilibx_macos/
		gcc $(LIBS) $(OBJ) -o $(NAME)

obj/%.o: src/%.c
	mkdir -p obj
	gcc -Wall -Wextra -Werror -c $< -o $@

clean :
	$(MAKE) -C libft/ clean
	/bin/rm -rf obj

fclean : clean
	$(MAKE) -C libft/ fclean
	/bin/rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean