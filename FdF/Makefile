NAME = FdF 

SRC = main.c \
	  get_fd_data.c \
	  key_events.c \
	  error_checker.c \
	  fdf_utils.c \
	  free_and_clear.c \
	  draw.c

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
	@echo "Archivage terminé [FdF]"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "Suppression des .o" 

fclean: clean
	@make fclean -C ${LIBPATH}
	@rm -f $(NAME)
	@echo "Suppression du .a effectuée"

re: fclean all

.PHONY : all clean fclean re 
