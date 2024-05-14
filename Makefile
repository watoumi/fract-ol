NAME = fractol
NAME_B = fractol_bonus

CFLAGS = -Wall -Wextra -Werror -O3
CC = cc
RM = rm -rf
SRCS = mandatory/./draw_julia.c mandatory/./init.c mandatory/./main.c mandatory/./math_utils.c mandatory/./draw_mandelbrot.c mandatory/./string_utils.c mandatory/./input.c
B_SRCS = bonus/./init.c bonus/./main.c bonus/./math_utils.c bonus/./render.c bonus/./string_utils.c bonus/./input.c

OBJS = $(SRCS:.c=.o)
B_OBJS = $(B_SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC)  $(CFLAGS) $(OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME)
bonus : $(B_OBJS)
	$(CC)  $(CFLAGS) $(B_OBJS)  -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)
clean :
		rm -rf $(OBJS) $(B_OBJS)
fclean : clean
		rm -rf $(NAME) $(NAME_B)
re : fclean all
