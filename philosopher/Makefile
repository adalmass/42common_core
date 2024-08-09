NAME = philo

SRC = main.c \
	  init.c \
	  utils.c \
	  routine.c \
	  microlibft.c \
	  
OBJ = $(SRC:.c=.o)

CC = gcc  #-fsanitize=address

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
