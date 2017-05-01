##
##
## Made by goedert nicolas
## Login   <nicolas94200@epitech.net>
##
## Started on  Tue Mar 21 12:19:45 2017 goedert nicolas
## Last update Tue Mar 21 12:19:45 2017 goedert nicolas
##

CFLAGS	+=	-Wextra -Wall -Werror -I./include

NAME	=	mysh

SRCS	=	./sources/basics.c		\
		./sources/basics2.c		\
		./sources/basics3.c		\
		./sources/my_str_to_word_tab.c	\
		./sources/get_next_line.c	\
		./sources/recup_path.c		\
		./sources/commands.c		\
		./sources/my_exit.c		\
		./sources/main.c

OBJS	=	$(SRCS:.c=.o)

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS) $(CFLAGS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	clean fclean all

.PHONY	:	all clean fclean re
