CC = gcc

CFLAGS += -Wall -Werror -Wextra -g3 -fsanitize=address

#CFLAGS += -g3 -fsanitize=address

RM = rm -rf

LIBFT = libft.a
LIBFTDIR = libft/
LIBFTLINK = -L $(LIBFTDIR) -lft


all: complib client server echoOK

complib: echoLibft
	$(MAKE) -C $(LIBFTDIR)

client: echoClient
	$(CC) $(CFLAGS) client.c $(LIBFTDIR)$(LIBFT) -o client

server: echoServer
	$(CC) $(CFLAGS) server.c $(LIBFTDIR)$(LIBFT) -o server

%.o:		%.c
	$(CC) -c $(CFLAGS) -o $@ $<
	printf "$(GREEN)██"

clean: echoCLEAN
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean echoFCLEAN
	$(MAKE) -C $(LIBFTDIR) fclean
	$(RM) server client

re:		fclean all

leaks:
	valgrind --leak-check=full --show-leak-kinds=all ./$(NAME)

git:
	make fclean
	git add .
	git commit -m "make done"
	git push

norme:
	norminette ./*.c ./minitalk.h ./libft/*.c ./libft/lift.h

.PHONY:		all clean fclean re leaks git norme
.SILENT:

##############______________Colors______________##############

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
END = \033[0m

##############______________MESSAGES______________##############

echoLibft:
	echo "$(YELLOW)===> Compiling $(RED)Libft$(END)\n"
echoServer:
	echo "$(YELLOW)===> Compiling $(RED)Server$(END)\n"
echoClient:
	echo "$(YELLOW)===> Compiling $(RED)Client$(END)\n"
echoOK:
	echo "$(GREEN) OK ===> Compilation Success$(END)\n"
echoCLEAN :
	echo "\n$(CYAN)===> Cleanning OBJS$(END)\n"
echoFCLEAN :
	echo "$(CYAN)===> Cleanning Client, Server & Libft$(END)\n"