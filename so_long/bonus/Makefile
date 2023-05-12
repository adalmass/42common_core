NAME = so_long

SRC = main.c \
	  startup_checks.c \
	  initialize_structs.c \
	  manage_maps.c \
	  parsing.c \
	  check_errors.c \
	  pathfinding.c \
	  pathfinding2.c \
	  run.c \
	  key_events.c \
	  player_moves.c \
	  img_load_and_print.c \
	  exit_animation.c \
	  enemy_moves.c \
	  enemy_moves2.c

LIBPATH = ./libft/
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
	@mv ${LIBNAME} ${LIBPATH}
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
