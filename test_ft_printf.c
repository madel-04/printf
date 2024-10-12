#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int num_tests = 0;
    int correct_tests = 0;

    printf("==== PRUEBAS DE ft_printf ====\n");

    // Test 1: Caracter
    printf("\nTest %d: %%c -> 'A'\n", ++num_tests);
    printf("printf:    ");
    int res1 = printf("%c\n", 'A');
    printf("ft_printf: ");
    int res2 = ft_printf("%c\n", 'A');
    if (res1 == res2) correct_tests++;

    // Test 2: Cadena de caracteres
    printf("\nTest %d: %%s -> \"Hola, Mundo\"\n", ++num_tests);
    printf("printf:    ");
    res1 = printf("%s\n", "Hola, Mundo");
    printf("ft_printf: ");
    res2 = ft_printf("%s\n", "Hola, Mundo");
    if (res1 == res2) correct_tests++;

    // Test 3: Puntero
    int a = 42;
    printf("\nTest %d: %%p -> &a\n", ++num_tests);
    printf("printf:    ");
    res1 = printf("%p\n", &a);
    printf("ft_printf: ");
    res2 = ft_printf("%p\n", &a);
    if (res1 == res2) correct_tests++;

    // Test 4: Entero con signo (%d)
    printf("\nTest %d: %%d -> 12345\n", ++num_tests);
    printf("printf:    ");
    res1 = printf("%d\n", 12345);
    printf("ft_printf: ");
    res2 = ft_printf("%d\n", 12345);
    if (res1 == res2) correct_tests++;

    // Test 5: Entero con signo negativo (%i)
    printf("\nTest %d: %%i -> -12345\n", ++num_tests);
    printf("printf:    ");
    res1 = printf("%i\n", -12345);
    printf("ft_printf: ");
    res2 = ft_printf("%i\n", -12345);
    if (res1 == res2) correct_tests++;

    // Test 6: Entero sin signo (%u)
    printf("\nTest %d: %%u -> 12345\n", ++num_tests);
    printf("printf:    ");
    res1 = printf("%u\n", 12345);
    printf("ft_printf: ");
    res2 = ft_printf("%u\n", 12345);
    if (res1 == res2) correct_tests++;

    // Test 7: Hexadecimal en minúsculas (%x)
    printf("\nTest %d: %%x -> 12345\n", ++num_tests);
    printf("printf:    ");
    res1 = printf("%x\n", 12345);
    printf("ft_printf: ");
    res2 = ft_printf("%x\n", 12345);
    if (res1 == res2) correct_tests++;

    // Test 8: Hexadecimal en mayúsculas (%X)
    printf("\nTest %d: %%X -> 12345\n", ++num_tests);
    printf("printf:    ");
    res1 = printf("%X\n", 12345);
    printf("ft_printf: ");
    res2 = ft_printf("%X\n", 12345);
    if (res1 == res2) correct_tests++;

    // Test 9: Porcentaje literal (%%)
    printf("\nTest %d: %% -> %%\n", ++num_tests);
    printf("printf:    ");
    res1 = printf("%%\n");
    printf("ft_printf: ");
    res2 = ft_printf("%%\n");
    if (res1 == res2) correct_tests++;

    printf("a%ib%ic%id", 1, -2, 3);
    ft_printf("a%ib%ic%id", 1, -2, 3);
    // Resultados finales
    printf("\nResultados: %d/%d pruebas correctas\n", correct_tests, num_tests);
    return 0;

   
}
