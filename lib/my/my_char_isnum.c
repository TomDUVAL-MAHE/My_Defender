/*
** EPITECH PROJECT, 2020
** my_char_isnum.c
** File description:
** A function that returns '1' if the character given as argument is a digit.
** Returns '0' if not.
*/
#include "my.h"

int my_char_isnum(char charc)
{
    if (charc <= '9' && charc >= '0')
        return (1);
    else
        return (0);
}
