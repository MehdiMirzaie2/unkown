# SRCS 		= main.c get_next_line.c get_next_line_utils.c push.c rotate.c result_checker.c swap.c

# OBJS 		= $(SRCS:.c=.o)

# CC 			= gcc
# RM 			= rm -f
# # CFLAGS 		= -Wall -Wextra -Werror
# CFLAGS 		= -Llibft -lft
# OFLAGS 		= -I../libft -Wall -Wextra -Werror
# libft 		= ../libft/libft.a

# NAME 		= checker

# all: 		$(NAME)

# $(libft):
# 			make -C libft

# $(NAME):	$(OBJS) | $(libft)
# 			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

# %.o : %.c
# 			$(CC) -c $< -o $@
# clean:
# 			$(RM) $(OBJS)
# 			make -C libft clean

# fclean:		clean
# 			$(RM) $(NAME)
# 			make -C libft fclean

# re:			fclean $(NAME)

# .PHONY:		all clean fclean re

SRCS 		= main.c get_next_line.c get_next_line_utils.c push.c rotate.c result_checker.c swap.c

OBJS 		= $(SRCS:.c=.o)

CC 			= gcc
RM 			= rm -f
CFLAGS 		= -Llibft -lft
OFLAGS 		= -I../libft -Wall -Wextra -Werror -v
# CFLAGS = -Wall -Wextra -Werror
# LDFLAGS = -Llibft -lft
# OFLAGS = -I ../libft


libft 		= ../libft/libft.a

NAME 		= checker

all: 		$(NAME)

$(libft):
			make -C libft

# $(NAME):	$(OBJS) | $(libft)
# 			$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

$(NAME):	$(OBJS) | $(libft)
			$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

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