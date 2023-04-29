NAME = so_long

SRC = main.c \
	  startup_checks.c \
	  initialize.c \
	  manage_maps.c \
	  parsing.c \
	  errors.c \
	  check_path.c \
	  pathfinding.c \
	  pathfinding2.c \
	  mlx_init.c \
	  mlx_key_events.c \
	  mlx_movements.c

LIBPATH = libft/
LIBNAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
FLAGSMLX = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

OBJ = $(SRC:.c=.o)

.c.o = $(CC) ${FLAGS} -c -o $(OBJ)

$(NAME): $(OBJ)
	@make -C ${LIBPATH}
	@mv ${LIBPATH}${LIBNAME} ${LIBNAME}
	@${CC} ${FLAGSMLX} ${LIBNAME} $(OBJ) -o $(NAME)
	@echo "Archivage terminé [so_long]"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "Suppression des .o" 

fclean: clean
	make fclean -C ${LIBPATH}
	@rm -f $(NAME)
	@echo "Suppression du .a effectuée"

re: fclean all

.PHONY : all clean fclean re 
