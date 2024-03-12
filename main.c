// cc -Wall -Werror -Wextra -g3 -fsanitize=address -D BUFFER_SIZE=42 get_next_line_utils.c get_next_line.c main.c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int		fd;
	char	*line;

	fd = open("files/prueba.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
	}
	close(fd);
	return (0);
}
