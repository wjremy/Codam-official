#include "minilibx_macos/mlx.h"
#include <math.h>
#include <stdio.h>
# include "get_next_line/get_next_line.h"
# include "Libft/libft.h"

int	get_height(char	*name_file)
{
	int	height;
	char *test;
	int	filed;

	filed = open(name_file, O_RDONLY);
	if(filed < 0)
		return(-1);
	test = "";
	height = 0;
    while ((test = get_next_line(filed)) != NULL)
    {
        free(test);
        height++;
    }
	close(filed);
	return(height);
}

char	**get_map(char	*name_file)
{
	int	height;
	char	**map;
	int	i;
	int	filed;

	i = 0;
	height = get_height(name_file);
	if (height == -1)
		return(NULL);
	map = malloc(height * sizeof(char*));
	if (map == NULL)
	{
		return(NULL);
	}
	map[height] = NULL;
	filed = open(name_file, O_RDONLY);
	if (filed == -1)
		return(NULL);
	while (i < height)
	{
		map[i] = get_next_line(filed);
		if (map[i] == NULL)
		{
			while(i>=0)
				free(map[i--]);
			free(map);
			close(filed);
			return(NULL);
		}
		//printf("%s", map[i]);
		i++;
	}
	close(filed);
	//free(map);
	return(map);
}
//connect malloc protection to other functions. also, it now doesnt output 0 if get_height gets it wrong
