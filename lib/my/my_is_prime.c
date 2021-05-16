/*
** EPITECH PROJECT, 2020
** my_is_prime
** File description:
** This function returns 1 if the number is prime and 0 if not.
*/
#include "my.h"

int my_is_prime(int nb)
{
    int i = 2;

    if (nb < 2)
        return (0);
    for (; i < nb; i += 1) {
        if (nb % i == 0) {
            return (0);
        }
    }
    return (1);
}
