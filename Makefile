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

SRC = main.c mlx_window.c ft_get_file.c draw_seg.c

OBJ = $(SRC:.c=.o)

MAKE = libft/Makefile

all : $(NAME)

$(NAME) : 
		$(MAKE) -C libft/make re
		gcc -c -lmlx -framework OpenGL -framework Appkit $(SRC)
		gcc -o $(NAME) $(OBJ)

clean :
	$(MAKE) -C libft/make clean
	/bin/rm -f $(OBJ)

fclean : clean
	$(MAKE) -C libft/make fclean
	/bin/rm -rf $(NAME)

re : fclean all

.PHONY: clean