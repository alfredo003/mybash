NAME = mybash
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iheader
SRC = ./src/main.c \
	./src/verify_command.c 
LIBFT_DIR = ./libs/libft
LIBFT = $(LIBFT_DIR)/libft.a
OBJS = $(SRC:.c=.o)

all:	$(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS)  $(LIBFT)  -lreadline -o $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR)
%.o:%.c header/mybash.h
	@$(CC) $(CFLAGS) -c $< -o $@
	clear
	@echo "Tudo pronto...! --> ./mybash"
clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	clear

fclean: clean
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	clear

re: fclean all



