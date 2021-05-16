/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** This function swaps the content of two integers, whose addresses are given
** as a parameter.
*/
#include "my.h"

/*
** description f(*x, *y) -> 0
** call f(*x, *y)
*/
void my_swap(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
