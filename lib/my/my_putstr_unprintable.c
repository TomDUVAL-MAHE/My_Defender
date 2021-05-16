/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** This function displays, one-by-one, the characters of a string. If the
** charaters is unprintable, put his ascii value in octal base.
*/
#include "my.h"

int my_putstr_unprintable(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] >= 127)
            my_putchar_unprintable(str[i]);
        else
            my_putchar(str[i]);
        i+=1;
    }
    return (0);
}
