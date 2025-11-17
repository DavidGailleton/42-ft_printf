#include <stdio.h>
#include <limits.h>
#include "include/ft_printf.h"

void test(const char *name, int (*test_func)(void))
{
    printf("\n===== %s =====\n", name);
    test_func();
}

int test_char(void)
{
    int r1, r2;

    r1 = printf("printf:    [%c]\n", 'A');
    r2 = ft_printf("ft_printf: [%c]\n", 'A');
    printf("Return printf: %d | Return ft_printf: %d\n", r1, r2);

    return (0);
}

int test_string(void)
{
    int r1, r2;

    r1 = printf("printf:    [%s]\n", "Hello");
    r2 = ft_printf("ft_printf: [%s]\n", "Hello");
    printf("Return printf: %d | Return ft_printf: %d\n", r1, r2);

    r1 = printf("printf:    [%s]\n", NULL);
    r2 = ft_printf("ft_printf: [%s]\n", NULL);
    printf("Return printf: %d | Return ft_printf: %d\n", r1, r2);

    return (0);
}

int test_pointer(void)
{
    int x = 42;
    int r1, r2;

    r1 = printf("printf:    [%p]\n", &x);
    r2 = ft_printf("ft_printf: [%p]\n", &x);
    printf("Return printf: %d | Return ft_printf: %d\n", r1, r2);

    r1 = printf("printf:    [%p]\n", NULL);
    r2 = ft_printf("ft_printf: [%p]\n", NULL);
    printf("Return printf: %d | Return ft_printf: %d\n", r1, r2);

    return (0);
}

int test_decimal(void)
{
    int r1, r2;

    r1 = printf("printf:    [%d] [%i]\n", 42, -42);
    r2 = ft_printf("ft_printf: [%d] [%i]\n", 42, -42);
    printf("Return printf: %d | Return ft_printf: %d\n", r1, r2);

    r1 = printf("printf:    [%d]\n", INT_MIN);
    r2 = ft_printf("ft_printf: [%d]\n", INT_MIN);
    printf("Return printf: %d | Return ft_printf: %d\n", r1, r2);

    return (0);
}

int test_unsigned(void)
{
    int r1, r2;

    r1 = printf("printf:    [%u]\n", 4294967295u);
    r2 = ft_printf("ft_printf: [%u]\n", 4294967295u);
    printf("Return printf: %d | Return ft_printf: %d\n", r1, r2);

    return (0);
}

int test_hex(void)
{
    int r1, r2;

    r1 = printf("printf:    [%x] [%X]\n", 3735928559u, 3735928559u);
    r2 = ft_printf("ft_printf: [%x] [%X]\n", 3735928559u, 3735928559u);
    printf("Return printf: %d | Return ft_printf: %d\n", r1, r2);

    return (0);
}

int test_percent(void)
{
    int r1, r2;

    r1 = printf("printf:    [%%]\n");
    r2 = ft_printf("ft_printf: [%%]\n");
    printf("Return printf: %d | Return ft_printf: %d\n", r1, r2);

    return (0);
}

int main(void)
{
    test("CHAR", test_char);
    test("STRING", test_string);
    test("POINTER", test_pointer);
    test("DECIMAL", test_decimal);
    test("UNSIGNED", test_unsigned);
    test("HEX", test_hex);
    test("PERCENT", test_percent);

    printf("\n===== ALL TESTS DONE =====\n");
    return (0);
}

