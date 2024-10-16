#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
    // Imprimir un entero sin signo
    ft_printf("%u\n", -1); // Esto imprimirá 4294967295 en sistemas de 32 bits

    // Usar punteros para imprimir ULONG_MAX
    unsigned long max_value = ULONG_MAX;
    unsigned long negative_max_value = (unsigned long)(-ULONG_MAX); // Esto sigue siendo problemático, ya que es un número negativo

    // Usando %p para imprimir punteros
    unsigned long *ptr_max = &max_value; // puntero a ULONG_MAX
    unsigned long *ptr_neg_max = (unsigned long *)negative_max_value; // Convertir -ULONG_MAX a puntero (no recomendable)

    printf(" %p %p \n", (void *)ptr_max, (void *)ptr_neg_max); // Casting a void*

    return 0;
}
