/*
** EPITECH PROJECT, 2020
** my_compute_squre_root
** File description:
** function that returns the square root (if it is a whole number) of the
** number given as argument.
*/
#include "my.h"

int my_compute_square_root(int nb)
{
    int i;

    if (nb <= 0)
        return (0);
    for (i = 1; my_compute_power_rec(i, 2) <= nb; i += 1) {
        if (my_compute_power_rec(i, 2) == nb)
            return (i);
    }
    return (0);
}
