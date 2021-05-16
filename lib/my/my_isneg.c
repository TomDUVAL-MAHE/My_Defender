/*
** EPITECH PROJECT, 2020
** my_isneg
** File description:
** This function dysplays either 'N' if the integer passed as parameter is
** negative or 'P', if positive or null.
*/
#include "my.h"

/*
**description: f(x)-> 'N' | 'P'
**call: f(x)
*/
int my_isneg(int n)
{
    if (n < 0) {
        my_putchar('N');
    } else {
        my_putchar('P');
    }
    my_putchar('\n');
    return (0);
}
