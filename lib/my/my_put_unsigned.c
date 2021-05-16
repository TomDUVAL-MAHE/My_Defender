/*
** EPITECH PROJECT, 2020
** my_put_unsigned.c
** File description:
** Print an unsigned int from a int given as parameter
*/

#include "my.h"

int my_put_unsigned(int i)
{
    unsigned int nb = my_int_to_unsigned(i);
    int nb_of_dgit;

    nb_of_dgit = 0;
    while ((nb / my_compute_power_rec(10, nb_of_dgit)) >= 10) {
        nb_of_dgit += 1;
    }
    for (nb_of_dgit; nb_of_dgit >= 0; nb_of_dgit -= 1) {
        my_putchar('0' + ((nb / my_compute_power_rec(10, nb_of_dgit)) % 10));
    }
    return (0);
}
