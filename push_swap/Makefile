NAME = push_swap

SRC = main.c \
	  initialize.c \
	  parsing.c \
	  manage_errors.c \
	  manage_double.c \
	  swap_sorting.c \
	  swap_pushing.c \
	  swap_rotating.c \
	  swap_r_rotating.c \
	  sort_small_stack.c \
	  sort_big_stack.c \
	  simplify_stack.c \

LIBPATH = libft/
LIBNAME = libft.a
CC = gcc -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

.c.o = $(CC) -c -o $(OBJ)

$(NAME): $(OBJ)
	@make -C ${LIBPATH}
	@mv ${LIBPATH}${LIBNAME} ${LIBNAME}
	@${CC} ${LIBNAME} $(OBJ) -o $(NAME)
	@mv ${LIBNAME} ${LIBPATH}
	@echo "Archivage terminé [push_swap]"

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
