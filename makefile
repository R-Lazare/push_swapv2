CC = cc
CFLAGS = -Wall -Wextra -Werror -g

# Source files for push_swap
SRC = arena_alloc.c arena.c ft_atoi.c ft_split.c ft_substr.c pushswap.c \
      basefunc.c basefunc2.c basefunc3.c basefunc4.c ft_printf.c \
      init.c sort.c sort_helper.c main.c

# Source files for checker
SRC2 = arena_alloc.c arena.c ft_atoi.c ft_split.c ft_substr.c checker.c \
       basefunc.c basefunc2.c basefunc3.c basefunc4.c ft_printf.c \
       init.c sort.c sort_helper.c get_next_line.c pushswap.c

OBJ = $(SRC:.c=.o)
OBJ2 = $(SRC2:.c=.o)

NAME = push_swap
NAME2 = checker

HEADER = pushswap.h

# General rule for object files
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule for making push_swap
all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

# Rule for making checker
bonus: $(NAME2)

$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2)

# Rule for cleaning object files
clean:
	rm -f $(OBJ) $(OBJ2)

# Rule for cleaning everything
fclean: clean
	rm -f $(NAME) $(NAME2)

# Rule for re-compiling everything
re: fclean all

.PHONY: all clean fclean re bonus
