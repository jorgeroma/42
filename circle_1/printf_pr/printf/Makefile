SRCS	=	ft_printf.c ft_putptr_utils.c

OBJS	=	${SRCS:.c=.o}

OBSBNS	=	${SRCSBNS:.c=.o}

NAME	=	libftprintf.a

CC		=	cc

AR		=	ar crs

RM		=	rm -f

CFLAGS	=	-Wall -Werror -Wextra

LIBFT	=	make -C ./libft

LIB_CL	=	make -C ./libft clean

LIB_FC	=	make -C ./libft fclean

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${LIBFT}
			cp ./libft/libft.a $(NAME)
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
