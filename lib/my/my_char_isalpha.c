/*
** EPITECH PROJECT, 2020
** my_char_isalpha.c
** File description:
** A function that returns '1' if the character given as argument is a lettre.
** Returns '0' if not.
*/
#include "my.h"

int my_char_isalpha(char charc)
{
    if ((charc <= 'z' && charc >= 'a') || (charc <= 'Z' && charc >= 'A'))
        return (1);
    else
        return (0);
}
