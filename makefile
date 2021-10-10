NAME = pipex
LIBFT = libft.a

LIBFT_PATH = ./libs/libft/

SRC = ./src/mandatory/

FILES = $(SRC)pipex.c
OBJECTS = pipex.o

CC = clang
CFLAGS = -Wall -Wextra -Werror
RE = rm -f

all: $(NAME)

$(NAME): $(OBJECTS)
	make --no-print-directory -C $(LIBFT_PATH) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) -L $(LIBFT_PATH)

$(OBJECTS): $(FILES)
	$(CC) $(CFLAGS) -g -c $(FILES)

clean:
	make --no-print-directory -C $(LIBFT_PATH) fclean
	$(RM) $(OBJECTS)

fclean: clean
	echo cleaning!
	make --no-print-directory -C $(LIBFT_PATH) fclean
	$(RM) $(NAME)
	echo done!
	
re: fclean all 

.PHONY: all clean fclean re 