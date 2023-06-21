NAME := push_swap
SOURCES := main.c input_validation.c linked_list_creation.c output.c command_execution.c set_indexes.c big_sort.c small_sort.c buckets.c
OBJECTS := ${SOURCES:.c=.o}

PRINTFLIBFT := ft_printf/libftprintf.a

FLAGS := -Wall -Werror -Wextra
HEADER := push_swap.h

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C ft_printf
	$ cc $(FLAGS) $(OBJECTS) -I $(HEADER) $(PRINTFLIBFT) -o $(NAME)

clean:
	@make clean -C ft_printf
	rm -rf $(OBJECTS)

fclean: clean
	@make fclean -C ft_printf
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re