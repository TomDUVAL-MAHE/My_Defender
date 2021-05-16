/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** This function displays, one-by-one, the characters of a string.
*/
#include "my.h"

int my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i+=1;
    }
    return (0);
}
