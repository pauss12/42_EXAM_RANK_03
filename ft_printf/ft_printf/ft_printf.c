
#include "ft_printf.h"

int print_str(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i] != '\0')
	{
		count += write(1, &str[i], 1);
		i++;
	}
	return (count);
}

int print_integer(int num)
{
	int count;
	char c;

	count = 0;
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		count += 11;
	}
	else if (num < 0)
	{
		num = -num;
		write(1, "-", 1);
		count += 1;
	}
	else if (num >= 0 && num <= 9)
	{
		c = num + '0';
		write(1, &c, 1);
		count++;
	}
	else
	{
		count += print_integer(num / 10);
		count += print_integer(num % 10);
	}
	return (count);
}

int print_hexa(unsigned int nb)
{
	int count;
	char c;

	count = 0;
	if (nb < 16)
	{
		if (nb <= 9)
		{
			c = nb + 48;
			count += write(1, &c, 1);
		}
		else
		{
			c = nb - 10 + 'a';
			count += write(1, &c, 1);
		}
	}
	else if (nb >= 16)
	{
		count += print_hexa(nb / 16);
		count += print_hexa(nb % 16);
	}
	return (count);
}

int ft_printf(const char *format, ...)
{
	int i;
	int count;
	va_list list;
	va_start(list, format);

	i = 0;
	count = 0;
	while (*format != '\0')
	{
		if (format[i] == '%')
		{
			format++;
			if (*format == 's')
				count += print_str(va_arg(list, char *));
			else if (*format == 'd')
				count += print_integer(va_arg(list, int));
			else if (*format == 'x')
				count += print_hexa(va_arg(list, unsigned int));
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(list);
	return (count);
}