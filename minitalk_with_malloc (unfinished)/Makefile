NAME_SERVER := server
SOURCE_SERVER := server.c
OBJECT_SERVER := ${SOURCE_SERVER:.c=.o}
BONUS_SERVER := server_bonus.c
OBJECT_BONUS_SERVER := ${BONUS_SERVER:.c=.o}

NAME_CLIENT := client
SOURCE_CLIENT := client.c
OBJECT_CLIENT := ${SOURCE_CLIENT:.c=.o}
BONUS_CLIENT := client_bonus.c
OBJECT_BONUS_CLIENT := ${BONUS_CLIENT:.c=.o}

PRINTF := ft_printf/libftprintf.a

FLAGS := -Wall -Werror -Wextra
HEADER := minitalk.h
BONUS_HEADER := minitalk_bonus.h

all: $(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJECT_SERVER)
	@make -C ft_printf
	$ cc $(FLAGS) $(OBJECT_SERVER) -I $(HEADER) $(PRINTF) -o $(NAME_SERVER)

$(NAME_CLIENT): $(OBJECT_CLIENT)
	@make -C ft_printf
	$ cc $(FLAGS) $(OBJECT_CLIENT) -I $(HEADER) $(PRINTF) -o $(NAME_CLIENT)

bonus: $(NAME_SERVER)_bonus $(NAME_CLIENT)_bonus

$(NAME_SERVER)_bonus: $(OBJECT_BONUS_SERVER)
	@make -C ft_printf
	$ cc $(FLAGS) $(OBJECT_BONUS_SERVER) -I $(HEADER) $(PRINTF) -o $(NAME_SERVER)_bonus

$(NAME_CLIENT)_bonus: $(OBJECT_BONUS_CLIENT)
	@make -C ft_printf
	$ cc $(FLAGS) $(OBJECT_BONUS_CLIENT) -I $(HEADER) $(PRINTF) -o $(NAME_CLIENT)_bonus

clean:
	@make clean -C ft_printf
	rm -rf $(OBJECT_SERVER) $(OBJECT_CLIENT) $(OBJECT_BONUS_SERVER) $(OBJECT_BONUS_CLIENT)

fclean: clean
	@make fclean -C ft_printf
	rm -f $(NAME_SERVER) $(NAME_CLIENT) $(NAME_SERVER)_bonus $(NAME_CLIENT)_bonus

re: fclean all

.PHONY: all clean fclean re