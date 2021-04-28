SOURCES_CHECKER =  	srcs_checker/checker.c				\
					srcs_checker/error.c				\
					srcs_checker/lst_utils.c			\
					srcs_checker/lst_utils2.c			\
					srcs_checker/ft_arg.c				\
					srcs_checker/debug.c

SOURCES_PUSH_SWAP = srcs_push_swap/push_swap.c			\
					srcs_push_swap/error.c				\
					srcs_push_swap/lst_utils.c			\
					srcs_push_swap/lst_utils2.c			\
					srcs_push_swap/sort.c				\
					srcs_push_swap/bloc_sort.c			\
					srcs_push_swap/sort_bloc_utils.c	\
					srcs_push_swap/ft_arg.c				\
					srcs_push_swap/retur_to_a.c			\
					srcs_push_swap/retur_to_a_utils.c	\
					srcs_push_swap/sort_3.c				\
					srcs_push_swap/debug.c

SOURCES_CHECKER_BNS =  	srcs_checker_bonus/checker.c	\
					srcs_checker_bonus/error.c			\
					srcs_checker_bonus/lst_utils.c		\
					srcs_checker_bonus/lst_utils2.c		\
					srcs_checker_bonus/ft_arg.c			\
					srcs_checker_bonus/vizualizer.c		\
					srcs_checker_bonus/debug.c

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
			rm -rf push_swap.dSYM
			rm -rf checker.dSYM

re:			fclean all

bonus:		# @make -C libft
			${CC} ${SOURCES_CHECKER_BNS} ${CFLAGS} -Llibft -lft -o ${NAME_1}
			${CC} ${SOURCES_PUSH_SWAP} ${CFLAGS} -Llibft -lft -o ${NAME_2}

.PHONY:		all fclean clean re bonus
