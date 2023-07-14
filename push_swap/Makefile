SRCS 		= main.c push.c make_linked_list.c rotate.c swap.c \
				small_logic.c three_sort.c five_sort.c big_sort.c set_cost.c smallest_large.c\
				utils.c utils2.c 

OBJS 		= $(SRCS:.c=.o)

CC 			= gcc
RM 			= rm -f
CFLAGS 		= -Llibft -lft
OFLAGS 		= -I libft -Wall -Wextra -Werror
libft 		= libft/libft.a

NAME 		= push_swap

all: 		$(NAME)

$(libft):
			make -C libft

$(NAME):	$(OBJS) | $(libft)
			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

%.o : %.c
			$(CC) $(OFLAGS) -c $< -o $@
clean:
			$(RM) $(OBJS)
			make -C libft clean

fclean:		clean
			$(RM) $(NAME)
			make -C libft fclean

re:			fclean $(NAME)

.PHONY:		all clean fclean re