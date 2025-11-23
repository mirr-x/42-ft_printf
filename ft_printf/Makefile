NAME =  libftprintf.a

CC = cc
CFLAGS = -Wextra -Wall -Werror -g

AR = ar crs $(NAME) $(OBJ)

SRC = ft_putchar_fd.c ft_putstr_fd.c ft_puthex_fd.c \
	ft_strlen.c ft_putnbr_fd.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR)

%.o: utilities/%.c ft_printf.h ft_printf.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean