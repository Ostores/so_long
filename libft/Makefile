NAME = libft.a

SRC_P = ft_strlen.c \
        ft_strnstr.c

SRC_GNL = get_next_line/get_next_line.c \
          get_next_line/get_next_line_utils.c

SRC_PRINTF = printf/ft_printf.c \
             printf/ft_utils.c \
             printf/ft_utils2.c

SRC = $(SRC_P) $(SRC_GNL) $(SRC_PRINTF)
OBJ = $(SRC:.c=.o)

HEAD = libft.h get_next_line/get_next_line.h printf/ft_printf.h

RM = rm -f
CC = gcc
FLAGS = -Wall -Werror -Wextra -Iprintf

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $(OBJ)

%.o: %.c $(HEAD)
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
