#include "get_next_line.h"

int main()
{
	char *line;
	int i;
	int fd;

	i = 0;
	line = NULL;
	fd = open("text.txt", O_RDONLY);
	while (i <= 3)
	{
		line = get_next_line(fd);
		printf("line: %s\n", line);
		free(line);
		i++;
	}
	return (0);
}