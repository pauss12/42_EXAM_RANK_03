#include "ft_printf.h"

int main()
{
	int aux;
	int temp;

	aux = 0;
	temp = 0;

	printf("------------------------------------\n");
	aux = ft_printf("$\n");
	temp = printf("$\n");

	printf("Mi funcion ha leido: %d caracteres\n", aux);
	printf("La original ha leido: %d caracteres\n", temp);
	printf("------------------------------------\n\n");

	aux = 0;
	temp = 0;

	// Cadena normal ------------------------
	printf("------------------------------------\n");
	aux = printf("La cadena es [buenas]\n");
	temp = ft_printf("La cadena es [buenas]\n");

	printf("Mi funcion ha leido: %d caracteres\n", aux);
	printf("La original ha leido: %d caracteres\n", temp);
	printf("------------------------------------\n\n");

	//Cadena con %s
	aux = 0;
	temp = 0;
	printf("------------------------------------\n");
	aux = printf("%s\n", "toto");
	temp = ft_printf("%s\n", "toto");

	printf("Mi funcion ha leido: %d caracteres\n", aux);
	printf("La original ha leido: %d caracteres\n", temp);
	printf("------------------------------------\n\n");

	//Cadena con decimal -----------------------
	aux = 0;
	temp = 0;
	printf("------------------------------------\n");
	aux = ft_printf("Magic %s is %d\n", "number", 42);
	temp = printf("Magic %s is %d\n", "number", 42);

	printf("Mi funcion ha leido: %d caracteres\n", aux);
	printf("La original ha leido: %d caracteres\n", temp);
	printf("------------------------------------\n\n");

	//NUMERO MINIMO NEGATIVO -------------------------------------------------------------

	printf("------------------------------------\n");
	aux = 0;
	temp = 0;

	aux = ft_printf("%d\n", -2147483648);
	temp = printf("%ld\n", -2147483648);

	printf("Mi funcion ha leido: %d caracteres\n", aux);
	printf("La original ha leido: %d caracteres\n", temp);
	printf("------------------------------------\n\n");

	//NUMEROS NEGATIVOS ----------------------------------------------------------------
	printf("------------------------------------\n");
	aux = 0;
	temp = 0;

	aux = ft_printf("-214\n");
	temp = printf("-214\n");

	printf("Mi funcion ha leido: %d caracteres\n", aux);
	printf("La original ha leido: %d caracteres\n", temp);

	aux = 0;
	temp = 0;
	aux = ft_printf("%dSDFGFD\n", -214);
	temp = printf("%dSDFGFD\n", -214);

	printf("Mi funcion ha leido: %d caracteres\n", aux);
	printf("La original ha leido: %d caracteres\n", temp);

	printf("------------------------------------\n\n");

	//Cadena con hexadecimal ------------------- ----------------------------------------
	aux = 0;
	temp = 0;
	printf("------------------------------------\n");
	aux = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	temp = printf("Hexadecimal for %d is %x\n", 42, 42);

	printf("Mi funcion ha leido: %d caracteres\n", aux);
	printf("La original ha leido: %d caracteres\n", temp);
	printf("------------------------------------\n\n");

	printf("------------------------------------\n");
	aux = 0;
	temp = 0;
	aux = ft_printf("Hexadecimal for %d is %x\n", 10, 10);
	temp = printf("Hexadecimal for %d is %x\n", 10, 10);
	
	printf("Mi funcion ha leido: %d caracteres\n", aux);
	printf("La original ha leido: %d caracteres\n", temp);
	printf("------------------------------------\n\n");

	//---------------------------------------------------------------------------------

	printf("------------------------------------\n");
	aux = 0;
	temp = 0;

	aux = ft_printf("00422a21474836477fffffff-214748364880000000\n");
	temp = printf("00422a21474836477fffffff-214748364880000000\n");

	printf("Mi funcion ha leido: %d caracteres\n", aux);
	printf("La original ha leido: %d caracteres\n", temp);
	printf("------------------------------------\n\n");

	printf("------------------------------------\n");
	aux = 0;
	temp = 0;

	aux = ft_printf("totowiurwuyrhwrywuier(null)aaaaaa\n");
	temp = printf("totowiurwuyrhwrywuier(null)aaaaaa\n");

	printf("Mi funcion ha leido: %d caracteres\n", aux);
	printf("La original ha leido: %d caracteres\n", temp);
	printf("------------------------------------\n\n");

	//otras pruebas ---------------------------------------------------------------------

	printf("------------------------------------\n");
	aux = 0;
	temp = 0;

	aux = ft_printf(" \
	0 $ \
	42 $ \
	1 $ \
	5454 $ \
	2147483647 $\
	 - 2147483648 $ \
	 - 2147483648 $ \
	 2147483647 $ $\
	\n");

	temp = printf(" \
	0 $ \
	42 $ \
	1 $ \
	5454 $ \
	2147483647 $\
	 - 2147483648 $ \
	 - 2147483648 $ \
	 2147483647 $ $\
	\n");

	printf("Mi funcion ha leido: %d caracteres\n", aux);
	printf("La original ha leido: %d caracteres\n", temp);
	printf("------------------------------------\n\n");

	return (0);
}