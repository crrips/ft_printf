NAME = libftprintf.a

SRC = 	ft_printf.c ft_check.c ft_putnbr_fd.c ft_putstr_fd.c\
		ft_putchar_fd.c ft_strlen.c ft_itoa.c ft_strdup.c

HEADER = ft_printf.h
OBJ = $(SRC:.c=.o) 

FLGS = -Wall -Werror -Wextra

all:$(NAME)

$(NAME):$(OBJ)
	ar rcs $(NAME) $(OBJ)
	
%.o:%.c
	cc $(FLGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re