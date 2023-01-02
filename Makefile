SOURCES_CHECKER =  	srcs_checker/checker.c				\
					srcs_checker/error.c				\
					srcs_checker/ft_arg.c

SOURCES_PUSH_SWAP = srcs_push_swap/push_swap.c			\
					srcs_push_swap/error.c				\
					srcs_push_swap/sort_3_median.c		\
					srcs_push_swap/bloc_sort.c			\
					srcs_push_swap/sort_bloc_utils.c	\
					srcs_push_swap/ft_arg.c				\
					srcs_push_swap/retur_to_a.c			\
					srcs_push_swap/retur_to_a_100.c		\
					srcs_push_swap/retur_to_a_utils.c	

SOURCES_CHECKER_BNS =  	srcs_checker_bonus/checker.c	\
					srcs_checker_bonus/error.c			\
					srcs_checker_bonus/ft_arg.c			\
					srcs_checker_bonus/vizualizer.c

SOURCES_LST_UTILS = srcs_lst_utils/lst_utils.c			\
					srcs_lst_utils/lst_utils2.c

INCLUDE =	-Iinclude

NAME_1 = checker

NAME_2 = push_swap

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

DEBUG_FLAGS = -g3

${NAME_2}:
			@make -C libft
			${CC} ${SOURCES_CHECKER} ${SOURCES_LST_UTILS} ${CFLAGS} -Llibft -lft -o ${NAME_1}
			${CC} ${SOURCES_PUSH_SWAP} ${SOURCES_LST_UTILS} ${CFLAGS} -Llibft -lft -o ${NAME_2}

all: 		${NAME_2}

clean:		
			@make clean -C libft

fclean:		
			@make fclean -C libft
			rm -f ${NAME_1}
			rm -f ${NAME_2}

re:			fclean all

debug:		
			@make -C libft
			${CC} ${SOURCES_CHECKER} ${SOURCES_LST_UTILS} ${CFLAGS} ${DEBUG_FLAGS} -Llibft -lft -o ${NAME_1}
			${CC} ${SOURCES_PUSH_SWAP} ${SOURCES_LST_UTILS} ${CFLAGS}  ${DEBUG_FLAGS} -Llibft -lft -o ${NAME_2}

bonus:		
			fclean
			@make -C libft
			${CC} ${SOURCES_CHECKER_BNS} ${SOURCES_LST_UTILS} ${CFLAGS} -Llibft -lft -o ${NAME_1}
			${CC} ${SOURCES_PUSH_SWAP} ${SOURCES_LST_UTILS} ${CFLAGS} -Llibft -lft -o ${NAME_2}

.PHONY:		all fclean clean re bonus
