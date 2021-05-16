/*
** EPITECH PROJECT, 2020
** my_find_prime_sup
** File description:
** a function that returns the smallest prime number that is greater than,
** or equal to, the number given as a parameter.
*/
#include "my.h"

int my_find_prime_sup(int nb)
{
    int i = 2;

    if (nb < 2)
        return (0);
    for (; i < nb; i +=1) {
        if (nb % i == 0) {
            return (i);
        }
    }
    return (nb);
}
