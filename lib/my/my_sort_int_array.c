/*
** EPITECH PROJECT, 2020
** my_sort_int_array
** File description:
** a function that sorts an integer array in ascending order, given a
** pointer to the first element of the array and its size
*/
#include "my.h"

int smallest_int(int *array, int size, int idx_int, int cycle)
{
    int intra_cycle = cycle;

    for (intra_cycle = cycle + 1; intra_cycle < size; intra_cycle +=1) {
        if (array[intra_cycle] < idx_int)
            idx_int = intra_cycle;
    }
    return (idx_int);
}

void my_sort_int_array(int *arr, int size)
{
    int idx;
    int cycle;

    for (cycle = 0; cycle < size-1; cycle += 1) {
        idx = cycle;
        my_int_swap(arr + cycle, arr + smallest_int(arr, size, idx, cycle));
    }
}
