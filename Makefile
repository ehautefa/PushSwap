SOURCES_CHECKER =  srcs/checker.c

SOURCES_PUSH_SWAP = srcs/push_swap.c

INCLUDE =	-Iinclude

NAME_1 = checker

NAME_2 = push_swap

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror -g 

${NAME_2}:
			# @make -C libft
			${CC} ${SOURCES_CHECKER} ${CFLAGS} -Llibft -lft -o ${NAME_1}
			${CC} ${SOURCES_PUSH_SWAP} ${CFLAGS} -Llibft -lft -o ${NAME_2}

all: 		${NAME_2}

clean:
			# ${MAKE} clean -C libft

fclean:		
			# clean
			# ${MAKE} fclean -C libft
			rm -f ${NAME_1}
			rm -f ${NAME_2}

re:			fclean all

.PHONY:		all fclean clean re bonus
