#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

char *get_next_line();

int main(int argc, char *argv[])
{
	int fd = open("text.txt", O_RDONLY);
	char *line;
	int i;

	i = 0;
	line = NULL;
	while (i < 3)
	{
		line = get_next_line(fd);
		printf("---%s\n", line);
		// if (line == NULL)
		// 	break ;
		free(line);
		i++;
	}
	return (0);
}