CC = gcc

CCFLAGS = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
		ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_putnbr_fd.c \
		ft_memmove.c ft_memset.c ft_strcat.c ft_strchr.c ft_putendl_fd.c \
		ft_strcpy.c ft_strdup.c  ft_toupper.c ft_strlcpy.c ft_putstr_fd.c\
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_split.c ft_putchar_fd.c\
		ft_strncmp.c ft_strnstr.c ft_calloc.c ft_itoa.c ft_strmapi.c \
		ft_strrchr.c ft_split.c ft_substr.c ft_strtrim.c ft_tolower.c \
		ft_gnl.c ft_strchr_end.c

BONUS = ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c ft_lstclear_bonus.c ft_lstdelone_bonus.c  \
		ft_lstiter_bonus.c ft_lstlast_bonus.c ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c

OBJ = $(SRC:.c=.o)

OBJBONUS = $(BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) libft.h
	ar rc $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CCFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJBONUS)

re: fclean all

bonus: $(OBJBONUS)
	ar rc $(NAME) $(OBJBONUS)
	ranlib $(NAME)

so: $(OBJ) libft.h
	$(CC) -shared -fPIC -Wl,-soname,libft.so -o libft.so $(OBJ)