NAME = minishell

SRC = main.c \
	  check_cmd_line.c \
	  tools.c \
	  redir_n_pipe.c \
	  handle_spaces.c \
	  mini_libft/ft_strdup.c \
	  mini_libft/ft_isalpha.c \
	  mini_libft/ft_isalnum.c \
	  mini_libft/ft_isdigit.c \
	  mini_libft/ft_strjoin_free.c \
	  mini_libft/ft_strncmp.c \
	  mini_libft/ft_strlen.c \
	  mini_libft/ft_memcpy.c \
	  mini_libft/ft_strnstr.c \
	  mini_libft/ft_split.c \
	  mini_libft/ft_putstr_fd.c \
	  mini_libft/ft_putchar.c \
	  mini_libft/ft_strtrim.c \
	  mini_libft/ft_strchr.c \
	  mini_libft/ft_substr.c \
	  mini_libft/ft_printf.c \
	  mini_libft/ft_utils_ptf.c \
	  mini_libft/number_len_ptf.c \
	  mini_libft/search_format_ptf.c \

OBJ = $(SRC:.c=.o)

CC = gcc #-Wall -Wextra -Werror -fsanitize=address

.c.o = $(CC) -c -o $(OBJ)

$(NAME): $(OBJ)
	@${CC} $(OBJ) -o $(NAME) -lreadline
	@echo "Archivage terminé [minishell]"

all: $(NAME)

clean:
	@rm -f $(OBJ)
	@echo "Suppression des .o" 

fclean: clean
	@rm -f $(OBJ) $(NAME)
	@echo "Suppression du .a effectuée"

re: fclean all

.PHONY : all clean fclean re
