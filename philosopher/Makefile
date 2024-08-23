NAME = philo

SRC = main.c \
	  init.c \
	  utils.c \
	  routine.c \
	  routine2.c \
	  death.c \
	  microlibft.c \

OBJ = $(SRC:.c=.o)

CC = gcc -Wall -Wextra -Werror #-fsanitize=thread -g

.c.o = $(CC) -c -o $(OBJ)

$(NAME): $(OBJ)
	@${CC} $(OBJ) -o $(NAME)
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