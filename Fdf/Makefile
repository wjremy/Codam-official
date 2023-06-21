NAME := fdf
SOURCES := parse_map.c main.c initialize_program.c draw_map.c utils/rotation.c utils/transformations.c load_image.c utils/map_parameters.c utils/key_press.c
OBJECTS := ${SOURCES:.c=.o}

GETNEXTLINE_LIBFT := libraries/get_next_line/get_next_line.a libraries/Libft/libft.a
MINILIBX := -I libraries/minilibx_macos -L libraries/minilibx_macos -lmlx -framework OpenGL -framework AppKit

FLAGS := -Wall -Werror -Wextra
HEADER := fdf.h

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C libraries/get_next_line
	@make -C libraries/libft
	$ cc $(FLAGS) $(MINILIBX) $(OBJECTS) -I $(HEADER) $(GETNEXTLINE_LIBFT) -o $(NAME)

clean:
	@make clean -C libraries/get_next_line
	@make clean -C libraries/libft
	rm -rf $(OBJECTS)

fclean: clean
	@make fclean -C libraries/get_next_line
	@make fclean -C libraries/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re