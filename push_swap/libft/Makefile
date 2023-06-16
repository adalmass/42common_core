NAME = libft.a

SRC_LIBFT = ft_putchar.c \
			ft_putstr.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_strlen.c \
			ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_strlcpy.c \
			ft_strlcat.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strchr.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strncmp.c \
			ft_atoi.c \
			ft_calloc.c \
			ft_strdup.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_split.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_striteri.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstadd_front.c \
			ft_lstsize.c \
			ft_lstlast.c \
			ft_lstadd_back.c \
			ft_lstdelone.c \
			ft_lstclear.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_strcpy.c \

SRC_PTF = ft_printf.c \
		  number_len_ptf.c \
		  search_format_ptf.c \
		  ft_utils_ptf.c

SRC_GNL = get_next_line.c \
		  get_next_line_utils.c \
		  get_next_line_bonus.c \
		  get_next_line_utils_bonus.c 

CC = gcc -Wall -Wextra -Werror

OBJ_LIBFT = $(SRC_LIBFT:.c=.o)
OBJ_PTF = $(SRC_PTF:.c=.o) 
OBJ_GNL = $(SRC_GNL:.c=.o) 

.c.o =  $(CC) -c -o $(OBJ_LIBFT) $(OBJ_PTF) $(OBJ_GNL)

$(NAME): $(OBJ_LIBFT) $(OBJ_PTF) $(OBJ_GNL)
	@ar -rc $(NAME) $(OBJ_LIBFT) $(OBJ_PTF) $(OBJ_GNL) 
	@echo "Archivage termine [libft]"

all: $(NAME)

clean:
	@rm -f $(OBJ_LIBFT) $(OBJ_PTF) $(OBJ_GNL)
	@echo "Suppression des fichiers .o terminee [Libft, Printf, GNL]"

fclean: clean
	@rm -f $(NAME)
	@echo "Suppression des fichiers .a terminee"

re: fclean all

.PHONY : all clean fclean re
