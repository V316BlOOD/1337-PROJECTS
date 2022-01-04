CFLAGS =  -Wall -Wextra -Werror -c	
CC = gcc
NAME = libftprintf.a


all : $(NAME)

$(NAME) :
	@make -C libft
	@$(CC) $(CFLAGS) ft_printf.c ft_printf_utils_5.c ft_printf_utils_2.c ft_printf_utils.c ft_printf_utils_3.c ft_printf_utils_4.c
	@ar rc $(NAME) ft_printf.o  ft_printf_utils_5.o  ft_printf_utils_2.o ft_printf_utils.o ft_printf_utils_3.o ft_printf_utils_4.o ./libft/*.o
	@ranlib $(NAME)

bonus: $(NAME)
clean :
	@rm -rf ft_printf.o ft_printf_utils_5.o ft_printf_utils_2.o ft_printf_utils_3.o ft_printf_utils.o ft_printf_utils_4.o ./libft/*.o
	@make -C libft clean
fclean : clean
	@rm $(NAME)
	@make -C libft fclean
re : fclean all
