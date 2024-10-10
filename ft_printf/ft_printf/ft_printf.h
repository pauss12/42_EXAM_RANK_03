#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

	int
	ft_printf(const char *format, ...);
int print_str(char *str);
int print_integer(int num);
int print_hexa(unsigned int nb);

#endif