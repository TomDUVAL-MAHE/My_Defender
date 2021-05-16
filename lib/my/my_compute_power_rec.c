/*
** EPITECH PROJECT, 2020
** my_compute_power_rec
** File description:
** A recursive function that returns the first argument raised to the power px
*/
#include "my.h"

/*
** description : f(int nb, int p) -> nb^p
** call : f(int nb, int p)
*/

int my_compute_power_rec(int nb, int p)
{
    if (p < 0)
        return (0);
    if (p == 0)
        return (1);
    if (p > 0)
        return (nb * my_compute_power_rec(nb, p-1));
    return (1);
}
