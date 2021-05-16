/*
** EPITECH PROJECT, 2020
** my_put_nbr
** File description:
** This function displays the number given as a parameter. It must be able
** to display all the possible value of int.
*/
#include "my.h"

/*
** description: f(x) -> 0
** call: f(x)
*/
int my_put_nbr(int nb)
{
    long int nbr;
    int nb_of_dgit;

    nbr = nb;
    if (nbr < 0) {
        my_putchar('-');
        nbr = nbr * -1;
    }
    nb_of_dgit = 0;
    while ((nbr / my_compute_power_rec(10, nb_of_dgit)) >= 10) {
        nb_of_dgit += 1;
    }
    for (nb_of_dgit; nb_of_dgit >= 0; nb_of_dgit -= 1) {
        my_putchar('0' + ((nbr / my_compute_power_rec(10, nb_of_dgit)) % 10));
    }
    return (0);
}
