CLAGS =  -Wall -Wextra -Werror
CC = gcc
P = .
LIBSRCELEMENTS = 	$P/ft_atoi.c	$P/ft_isalpha.c	$P/ft_itoa.c	$P/ft_memcpy.c	$P/ft_putendl_fd.c	$P/ft_strchr.c	$P/ft_strlcpy.c	$P/ft_strnstr.c	$P/ft_tolower.c \
					$P/ft_bzero.c	$P/ft_isascii.c	$P/ft_memccpy.c	$P/ft_memmove.c	$P/ft_putnbr_fd.c	$P/ft_strdup.c	$P/ft_strlen.c	$P/ft_strrchr.c	$P/ft_toupper.c \
					$P/ft_calloc.c	$P/ft_isdigit.c	$P/ft_memchr.c	$P/ft_memset.c	$P/ft_putstr_fd.c	$P/ft_strjoin.c	$P/ft_strmapi.c	$P/ft_strtrim.c \
					$P/ft_isalnum.c	$P/ft_isprint.c	$P/ft_memcmp.c	$P/ft_putchar_fd.c	$P/ft_split.c	$P/ft_strlcat.c	$P/ft_strncmp.c	$P/ft_substr.c

LIBOBJELEMENTS = 	$P/ft_atoi.o	$P/ft_isalpha.o	$P/ft_itoa.o	$P/ft_memcpy.o	$P/ft_putendl_fd.o	$P/ft_strchr.o	$P/ft_strlcpy.o	$P/ft_strnstr.o	$P/ft_tolower.o \
					$P/ft_bzero.o	$P/ft_isascii.o	$P/ft_memccpy.o	$P/ft_memmove.o	$P/ft_putnbr_fd.o	$P/ft_strdup.o	$P/ft_strlen.o	$P/ft_strrchr.o	$P/ft_toupper.o \
					$P/ft_calloc.o	$P/ft_isdigit.o	$P/ft_memchr.o	$P/ft_memset.o	$P/ft_putstr_fd.o	$P/ft_strjoin.o	$P/ft_strmapi.o	$P/ft_strtrim.o \
					$P/ft_isalnum.o	$P/ft_isprint.o	$P/ft_memcmp.o	$P/ft_putchar_fd.o	$P/ft_split.o	$P/ft_strlcat.o	$P/ft_strncmp.o	$P/ft_substr.o

NAME = libft.a

all: $(NAME)
$(NAME) :
	@$(CC) $(CFLAGS) $(LIBSRCELEMENTS) -c
	@ar rc $(NAME) $(LIBOBJELEMENTS)
	@ranlib $(NAME)
bonus: $(NAME)

clean: 
	@rm -rf $(LIBOBJELEMENTS) 
fclean: clean
	@rm -rf $(NAME)

re: fclean all 
