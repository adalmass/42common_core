NAME = so_long_bonus

SRC = main_bonus.c \
	  startup_checks_bonus.c \
	  initialize_bonus.c \
	  manage_maps_bonus.c \
	  parsing_bonus.c \
	  errors_bonus.c \
	  pathfinding_bonus.c \
	  pathfinding2_bonus.c \
	  run_bonus.c \
	  mlx_key_events_bonus.c \
	  mlx_movements_bonus.c \
	  mlx_imgs_bonus.c \
	  mlx_animations_bonus.c

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
	@echo "Archivage terminé [so_long_bonus]"

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
