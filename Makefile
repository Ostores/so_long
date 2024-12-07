NAME = so_long

CC = gcc
FLAGS = -Wall -Werror -Wextra -I/usr/local/include ${SEG}
LIBS = -L/usr/local/lib -lmlx -framework OpenGL -framework AppKit
SEG = -fsanitize=address -g

SRC_PATH = ./srcs/
LIBFT_PATH = ./libft/
OBJ_DIR = ./obj/

SRC =	so_long \
		parsing \
		find_collectible \
		find_player \
		find_wall \
		key_move \
		load_map \
		load_map_size \
		load_asset \
		draws \
		error
		
		

C_FILES = $(addprefix $(SRC_PATH), $(SRC:=.c))

OBJ = $(addprefix $(OBJ_DIR), $(SRC:=.o))

LIBFT_LIB = $(LIBFT_PATH)libft.a

all: $(OBJ_DIR) $(LIBFT_LIB) $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(LIBFT_LIB) $(LIBS)
	@echo "So_Long compilation finished successfully!"st

$(OBJ_DIR)%.o: $(SRC_PATH)%.c | $(OBJ_DIR)
	@$(CC) $(FLAGS) -c $< -o $@


$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LIBFT_LIB):
	@echo "Compiling So_Long... Please wait..."
	@$(MAKE) -C $(LIBFT_PATH) --silent

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all

.PHONY: all clean fclean re
