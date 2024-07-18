NAME = philo

SRC = main.c \
	  microlibft.c \
	  utils.c \
	  
OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror #-fsanitize=address

.c.o = $(CC) -c -o $(OBJ)

$(NAME): $(OBJ)
	@${CC} $(OBJ) -o $(NAME) -lreadline -D_REENTRANT
	@echo "Archivage terminé [philosopher]"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "Suppression des .o" 

fclean: clean
	@rm -f $(OBJ) $(NAME)
	@echo "Suppression du .a effectuée"

re: fclean all

.PHONY : all clean fclean re
