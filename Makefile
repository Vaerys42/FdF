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

SRC = 	main.c \
		mlx_window.c \
		ft_get_file.c \
		draw_seg.c \
		file_x.c \
		file_y.c \
		line_y.c \
		line_x.c \

LIBS = -framework OpenGL -framework Appkit minilibx_macos/libmlx.a libft/libft.a

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : 
		make -C libft/
		make -C minilibx_macos/
		gcc -c $(SRC)
		gcc $(LIBS) $(OBJ) -o $(NAME)

clean :
	$(MAKE) -C libft/ clean
	/bin/rm -f $(OBJ)

fclean : clean
	$(MAKE) -C libft/ fclean
	/bin/rm -rf $(NAME)

re : fclean all

.PHONY: clean fclean