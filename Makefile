NAME = mybash
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iheader
SRC = ./src/main.c
OBJS = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -lreadline -o $(NAME)

%.o:%.c header/mybash.h
	@$(CC) $(CFLAGS) -c $< -o $@
	clear
	@echo "Tudo pronto...! --> ./mybash"
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all



