NAME =  libftprintf.a

CC = cc
CFLAGS = -Wextra -Wall -Werror -c

SRC = ft_printf.c utilities/ft_putchar_fd.c utilities/ft_putstr_fd.c utilities/ft_puthex_fd.c \
	utilities/ft_strlen.c utilities/ft_putnbr_fd.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean