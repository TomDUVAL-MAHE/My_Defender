/*
** EPITECH PROJECT, 2020
** my_putchar
** File description:
** This is a function which print the given character.
*/
#include <unistd.h>
#include "my.h"

/*
**declaration: f(x)->void
**call f(x)
*/
void my_putchar(char c)
{
    write(1, &c, 1);
}
