NAME		=	a.out
SRC			=	main.c\
				double_linked_list.c
OBJ			=	$(SRC:.c=.o)
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
CPPFLAGS	=	-I./

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:
	make fclean
	make all

.PHONY: all clean fclean re
