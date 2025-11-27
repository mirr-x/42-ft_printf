NAME =  libftprintf.a

CC = cc
CFLAGS = -Wextra -Wall -Werror

SRC = ft_printf.c utilities/ft_putstr_fd.c utilities/ft_puthex_ptr_fd.c \
	utilities/ft_putnbr_fd.c utilities/ft_puthex_dec_fd.c

SRC_BONUS = ft_printf_bonus.c utilities_bonus/ft_putstr_fd_bonus.c utilities_bonus/ft_puthex_ptr_fd_bonus.c \
	utilities_bonus/ft_putnbr_fd_bonus.c utilities_bonus/ft_puthex_dec_fd_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

BONUS = .bonus

all: $(NAME)

$(NAME): $(OBJ)
	ar crs $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(BONUS)

$(BONUS): $(OBJ_BONUS)
	ar crs $(NAME) $(OBJ_BONUS)
	@touch .bonus

utilities_bonus/%.o: utilities_bonus/%.c ft_printf_bonus.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean:
	rm -f $(OBJ) $(NAME) $(BONUS) $(OBJ_BONUS)

re: fclean all

.PHONY: clean fclean bonus re all