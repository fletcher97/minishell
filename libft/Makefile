NAME		=	libft.a

SRCS		= 	$(shell find . -type f -name "*.c")
OBJS		= 	$(SRCS:.c=.o)
OBJSB		=	$(BONUS:.c=.o)
LIB_DIRS	=
INCL_DIRS	=
INCLUDE		=	$(addprefix -I, $(INCL_DIRS))

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror

RED			= \033[0;31m
GREEN		= \033[0;32m
ORANGE		= \033[0;33m
BLUE		= \033[1;34m
YELLOW		= \033[1;33m
NC			= \033[0m

all:	$(NAME)

$(NAME): $(OBJS)
	@echo "\n$(GREEN)Creating libft:$(NC)"
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

.c.o:
			@echo "Creating object: $@"
			@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

bonus: $(NAME)
	$(CC) $(FLAGS) -c -I libft.h $(BONUS)
	ar rc $(NAME) $(OBJSB)
	ranlib $(NAME)

clean:
	/bin/rm -f $(OBJS)

fclean:
	/bin/rm -f $(NAME)

bclean:
	/bin/rm -f $(OBJSB)

re: fclean all

rf: clean fclean all
	gcc -Wall -Wextra -Werror main.c libft.a
	./a.out

rb: bclean fclean bonus
	gcc -Wall -Wextra -Werror main.c libft.a
	./a.out
