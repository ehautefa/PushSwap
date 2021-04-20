SOURCES_CHECKER =  	srcs_checker/checker.c		\
					srcs_checker/error.c		\
					srcs_checker/lst_utils.c	\
					srcs_checker/lst_utils2.c	\
					srcs_checker/ft_arg.c		\
					srcs_checker/debug.c

SOURCES_PUSH_SWAP = srcs_push_swap/push_swap.c

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
