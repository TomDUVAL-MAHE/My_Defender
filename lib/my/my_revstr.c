/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** a function that reverses a string.
*/
#include "my.h"

char *my_revstr(char *str)
{
    int temp = 0;
    int size = my_strlen(str) - 1;

    for (int i = 0; size > i; i += 1) {
        temp = str[i];
        str[i] = str[size];
        str[size] = temp;
        size --;
    }
    return (str);
}
