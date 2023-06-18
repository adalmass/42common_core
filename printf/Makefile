NAME = libftprintf.a

SRC = ft_printf.c \
      ft_utils.c \
	  number_len.c \
	  search_format.c

CC = gcc -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

.c.o =  $(CC) -c -o $(OBJ)

$(NAME): $(OBJ)
	@ar -rc $(NAME) $(OBJ) 
	@echo "Archivage terminé"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "Suppression des .o" 

fclean: clean
	@rm -f $(NAME)
	@echo "Suppression du .a effectuée"

re: fclean all

.PHONY : all clean fclean re
