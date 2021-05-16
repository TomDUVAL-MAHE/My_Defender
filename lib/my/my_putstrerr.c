/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** This function displays, one-by-one, the characters of a string.
*/
#include "my.h"
#include <unistd.h>
/*
** description: f("str") -> 0
** call f("str")
*/
int my_putstrerr(char const *str)
{
    write(2, str, my_strlen(str));
    return (0);
}
