NAME		= fractol

SRCS		=  	./srcs/validation.c \
				./srcs/mandelbrot.c \
				./srcs/julia.c \
				./srcs/martin.c \
				./srcs/constructor.c \
				./srcs/manipulations.c \
				./srcs/m_infrastructure.c \
				./srcs/j_infrastructure.c \
				./srcs/main.c
			
CFLAGS		= 	-Wall -Wextra -Werror -pthread
OBJECTS 	= 	$(SRCS:.c=.o)
LIB			= 	libft/libft.a

INC			= 	./includes/fractol.h

#colors
RESET		= \033[m
RED         = \033[1;31m
GREEN       = \033[01;38;05;46m
YELLOW      = \033[01;38;05;226m
BLUE        = \033[03;38;05;21m
VIOLET      = \033[01;38;05;201m
CYAN        = \033[1;36m
WHITE       = \033[01;38;05;15m

all: $(NAME)
	@echo  "$(YELLOW) : OK$(RESET)"

$(NAME): $(LIB) $(OBJECTS) $(INC)
	@ gcc $(CFLAGS) -I$(INC) $(SRCS) -L ./libft -lft -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(LIB):
	@echo  "$(GREEN)Compiling: $(WHITE)libft$(RESET)$(YELLOW) : $(RESET)\c)"
	@make -C libft
	@echo  "$(GREEN)Compiling: $(WHITE)fdf  $(RESET)$(YELLOW) : $(RESET)\c)"

$(OBJECTS): %.o: %.c
	@gcc -c $(CFLAGS) $< -o $@
	@echo  "$(YELLOW)█$(RESET)\c)"

clean:
	@ make -C libft clean
	@ rm -f $(OBJECTS)

fclean: clean
	@ rm -f $(NAME) $(LIB)
	@ make -C libft fclean

re: fclean all

.PHONY: all clean fclean re