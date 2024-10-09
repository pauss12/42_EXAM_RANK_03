#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
	#define BUFFER_SIZE 6
#endif

char *read_line();
char *ft_strjoin(char *s1, char *s2);
char *get_next_line();
int ft_strlen(char *str);

static char *ft_free_join(char *estatica, char *buffer)
{
	char *str;

	// if (estatica == NULL)
	// 	return (NULL);
	str = ft_strjoin(estatica, buffer);
	free(estatica);
	return (str);
}

char *read_line(int fd, char *estatica)
{
	char *buffer;
	int read_bytes;

	read_bytes = 1;
	buffer = NULL;
	if (estatica == NULL)
		estatica = calloc(1, sizeof(char));
	buffer = calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			return (NULL);
		}
		buffer[read_bytes ] = 0;
		estatica = ft_free_join(estatica, buffer);
	}
	//printf("Estatica dentro de read_line es: %s\n", estatica);
	free(buffer);
	return (estatica);
}

char *get_first_line(char *estatica)
{
	char *line;
	int j;
	int i;

	line = NULL;
	i = 0;
	j = 0;
	printf("entra en get_first_line\n");
	if (!estatica[0] || !estatica)
		return (NULL);
	while (estatica[i] != '\n' && estatica[i] != '\0')
		i++;
	line = calloc((i + 2), sizeof(char));
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = estatica[j];
		j++;
	}
	if (estatica[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	printf("Sale de get first line - Line: (%s)\n", line);
	//printf("Line dentro de get_first_line es: %s\n", line);
	return (line);
}

char *pass_line(char *estatica)
{
	//Quiero restarle la linea leida a la estatica
	char *new_estatica;
	int i;
	int j;

	printf("Entra en pass line - Estatica: (%s)\n", estatica);



	new_estatica = calloc((cont + ), sizeof(char));
	if (new_estatica)
		return (NULL);

	printf("------------------------------------\n");
	while (estatica[i] != '\0')
	{
		printf("Caracter estatica[%d] es: %c\n", i, estatica[i]);
		new_estatica[j] = estatica[i];
		j++;
		i++;
	}
	printf("------------------------------------\n");
	new_estatica[j] = '\0';
	printf("pass line es %s\n", new_estatica);

	return (new_estatica);
}

char *get_next_line(int fd)
{
	static char *estatica;
	char *line;

	line = NULL;
	estatica = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	estatica = read_line(fd, estatica);
	if (estatica == NULL)
		return (NULL);
	// printf("Estatica dentro de get_next_line es :%s\n", estatica);
	line = get_first_line(estatica);
	estatica = pass_line(estatica);
	return (line);
}