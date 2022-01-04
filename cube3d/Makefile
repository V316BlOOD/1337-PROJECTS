SOURCES = sources/f_reading1.c sources/f_reading2.c sources/f_reading3.c sources/f_reading4.c sources/f_reading5.c sources/f_reading6.c sources/f_reading7.c sources/f_reading8.c sources/f_reading9.c \
		  sources/g_rendering1.c sources/g_rendering2.c sources/g_rendering3.c sources/g_rendering4.c sources/g_rendering5.c sources/g_rendering6.c sources/g_rendering7.c sources/g_rendering8.c sources/g_rendering9.c \
		  sources/main.c 
LIBFT = sources/libft/libft.a
CC = GCC 
FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit
NAME = cub3D
LIBFMAKE = ./sources/libft/


.PHONY: clean fclean re

all: $(NAME)
$(NAME):
	make -C $(LIBFMAKE)
	$(CC) $(FLAGS) $(SOURCES) $(LIBFT) -o $(NAME)
clean:
	rm $(NAME)
	make clean -C $(LIBFMAKE)
fclean: clean
	make fclean -C  $(LIBFMAKE)
re: fclean $(NAME)
