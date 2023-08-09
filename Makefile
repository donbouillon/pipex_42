NAME := pipex
CC := gcc
CFLAGS := -Wall -Werror -Wextra
SRC_FILES := pipex.c pipex_utils.c ft_printf/ft_printf.c ft_printf/ft_printf_utils.c \
libft/ft_substr.c libft/ft_strjoin.c libft/ft_strnstr.c libft/ft_split.c libft/ft_strlen.c \
libft/ft_strdup.c child_processes.c main.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	$(CC) ${OBJ_FILES} -o ${NAME}

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

clean:
	rm -rf $(OBJ_FILES) $(NAME)

fclean: clean
	rm -rf all
	make fclean -C ./libft

re: fclean all