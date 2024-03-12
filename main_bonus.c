// cc -Wall -Werror -Wextra -g3 -fsanitize=address -D BUFFER_SIZE=42 get_next_line_utils_bonus.c get_next_line_bonus.c main_bonus.c
#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd01, fd02, fd03;

	fd01 = open("files/mix_demencia.txt", O_RDONLY);
	fd02 = open("files/xtayalive.txt", O_RDONLY);
	fd03 = open("files/star_shopping.txt", O_RDONLY);

    printf("MD_1 - %s\n", get_next_line(fd01));
    printf("XT_1 - %s\n", get_next_line(fd02));
    printf("SS_1 - %s\n", get_next_line(fd03));

    printf("MD_2 - %s\n", get_next_line(fd01));
    printf("XT_2 - %s\n", get_next_line(fd02));
    printf("SS_2 - %s\n", get_next_line(fd03));
    
    printf("MD_3 - %s\n", get_next_line(fd01));
    printf("XT_3 - %s\n", get_next_line(fd02));
    printf("SS_3 - %s\n", get_next_line(fd03));
    
    printf("MD_4 - %s\n", get_next_line(fd01));
    printf("XT_4 - %s\n", get_next_line(fd02));
    printf("SS_4 - %s\n", get_next_line(fd03));
}
