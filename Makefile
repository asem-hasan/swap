NAME = push_swap

SRCS = bench.c disorder.c ft_utils.c medium.c parse_flag.c push.c reverse_rotate.c simple.c split.c stack_utils.c complex.c \
       main_parsing.c parse_args.c parse_utils.c rotate.c sort_uttils.c stack.c swap.c utils.c ft_printf_char.c ft_printf_nbr.c ft_printf_str.c ft_printf.c


OBJS = ${SRCS:.c=.o}

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror

all: ${NAME}


$(NAME): ${OBJS}
	 $(CC) $(CFLAGS) ${OBJS} -o ${NAME}

%.o: %.c push_swap.h
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all
