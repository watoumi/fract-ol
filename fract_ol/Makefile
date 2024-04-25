NAME = Fractol

CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address
CC = cc
RM = rm -rf
SRCS = ./init.c ./main.c ./math_utils.c ./render.c ./string_utils.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC)  $(CFLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean :
		rm -rf $(OBJS)
fclean : clean
		rm -rf $(NAME)
re : fclean all
