#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
    // Imprimir un entero sin signo
    //ft_printf("%u\n", -1); // Esto imprimirá 4294967295 en sistemas de 32 bits

    printf(" %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX); // Casting a void*
    ft_printf(" %p %p \n", (void *)ULONG_MAX, (void *)-ULONG_MAX);
    return 0;
}
