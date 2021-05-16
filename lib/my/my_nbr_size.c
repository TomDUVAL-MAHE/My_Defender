/*
** EPITECH PROJECT, 2020
** My_Radar
** File description:
** my_nbr_size.c
*/

#include "my.h"

int my_nbr_size(int nb)
{
    int res = 0;

    if (nb == 0)
        return (1);
    while (nb != 0) {
        nb /= 10;
        res++;
    }
    return (res);
}