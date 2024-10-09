#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	char *ptr1;
	char *ptr2;
	size_t i;
	size_t j;

	ptr1 = (char *)s1;
	ptr2 = (char *)s2;
	i = 0;
	j = 0;
	str = calloc(((ft_strlen(ptr1) + ft_strlen(ptr2)) + 1),  sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}