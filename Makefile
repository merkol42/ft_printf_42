NAME		= libftprintf.a
LIBFT		= libft
CC			= gcc
CFLAGS		= -Wall -Werror -Wextra -I.


SRC	= $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rcs $(NAME) $(OBJ)

clean:
	@rm -f *.o

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

bonus: all

.PHONY:	all clean fclean re bonus
