NAME := pipex
CC := gcc
CFLAGS := -Wall -Werror -Wextra
SRC_FILES := pipex.c pipex_utils.c ft_printf/ft_printf.c ft_printf/ft_printf_utils.c
OBJ_FILES = $(SRC_FILES:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILES)
	make re -C ./libft
	$(CC) ${OBJ_FILES} -Llibft -lft -o ${NAME}

.c.o:
	${CC} ${CFLAGS} -g -c $< -o ${<:.c=.o}

clean:
	rm -rf $(OBJ_FILES) $(NAME)

fclean: clean
	rm -rf all

re: fclean all