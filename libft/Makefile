NAME=libft.a

SRCS=ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_strcpy.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c ft_memcmp.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_lstprint.c ft_lstadd_back_2p.c ft_lstdup_2p.c ft_lsthead_2p.c ft_lstnode_print_2p.c

OBJS= $(SRCS:.c=.o)

OBJSB= $(BONUS:.c=.o)

CC=gcc -Wall -Wextra -Werror

all:	$(NAME)

$(NAME):
	$(CC) -c -I libft.h $(SRCS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

bonus: $(NAME)
	$(CC) -c -I libft.h $(BONUS)
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
