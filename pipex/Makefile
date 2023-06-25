NAME = pipex

SRC = main.c \
	  utils.c \
	  init.c \
	  manage_errors.c \
	  mini_libft/ft_strdup.c \
	  mini_libft/ft_strjoin.c \
	  mini_libft/ft_strncmp.c \
	  mini_libft/ft_strlen.c \
	  mini_libft/ft_memcpy.c \
	  mini_libft/ft_strnstr.c \
	  mini_libft/ft_split.c \
	  mini_libft/ft_putstr_fd.c \
	  mini_libft/ft_putchar.c \
	  mini_libft/ft_printf.c \
	  mini_libft/ft_utils_ptf.c \
	  mini_libft/number_len_ptf.c \
	  mini_libft/search_format_ptf.c \

CC = gcc -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

.c.o = $(CC) -c -o $(OBJ)

$(NAME): $(OBJ)
	@${CC} $(OBJ) -o $(NAME)
	@echo "Archivage terminé [pipex]"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "Suppression des .o" 

fclean: clean
	@rm -f $(OBJ) $(NAME)
	@echo "Suppression du .a effectuée"

re: fclean all

.PHONY : all clean fclean re 
