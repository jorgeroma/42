SRCS	=	ft_printf.c

OBJS	=	${SRCS:.c=.o}

OBSBNS	=	${SRCSBNS:.c=.o}

NAME	=	libftprintf.a

CC		=	cc

AR		=	ar cr

RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

LIBFT	=	make -C libft

LIB_CL	=	make -C libft clean

LIB_FC	=	make -C libft fclean

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${LIBFT}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${LIB_CL}
			${RM} ${OBJS} ${OBSBNS}

fclean:		clean
			${LIB_FC}
			${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
