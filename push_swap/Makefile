NAME = push_swap

SRC = main.c \
	  initialize.c \
	  parsing.c \
	  manage_errors.c \
	  manage_double.c \
	  DEBUG_print_tab.c \
	  sorting_swap.c \
	  pushing_swap.c \
	  rotating_swap.c \
	  r_rotating_swap.c \
	  sort_small_stack.c \
	  sort_big_stack.c \
	  

LIBPATH = libft/
LIBNAME = libft.a
CC = gcc -Wall -Wextra -Werror
CCsani = -g -fsanitize=address

OBJ = $(SRC:.c=.o)

.c.o = $(CC) -c -o $(OBJ)
#.c.o = $(CC) $(CCsani) -c -o $(OBJ)

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
