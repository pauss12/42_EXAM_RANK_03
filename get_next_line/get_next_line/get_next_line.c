#include "get_next_line.h"

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>

char *strjoin_and_free(char *s1, char *s2)
{
	char *joined;
	size_t len1;
	size_t len2;
	size_t i;
	size_t j;

	if (!s1 && !s2)
		return (NULL);
	len1 = (s1) ? strlen(s1) : 0;
	len2 = strlen(s2);
	joined = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!joined)
		return (NULL);
	i = -1;
	while (++i < len1)
		joined[i] = s1[i];
	j = 0;
	while (j < len2)
		joined[i++] = s2[j++];
	joined[i] = '\0';
	free(s1); // Liberar la memoria de la cadena anterior
	return (joined);
}

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE];
	static int buffer_read = 0;
	static int buffer_pos = 0;
	char *line = NULL;
	char temp[2]; // Solo para el carácter actual
	int i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while (1)
	{
		if (buffer_pos >= buffer_read)
		{
			buffer_read = read(fd, buffer, BUFFER_SIZE);
			buffer_pos = 0;
			if (buffer_read <= 0)
				break;
		}
		temp[0] = buffer[buffer_pos++];
		temp[1] = '\0';
		line = strjoin_and_free(line, temp);
		if (temp[0] == '\n')
			break;
	}
	if (!line || line[0] == '\0')
	{
		free(line);
		return (NULL);
	}
	return (line);
}
