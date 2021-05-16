/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** time_management.c
*/

#include "defender.h"

void get_time(defender_t *defender)
{
    defender->last_time = defender->actual_time;
    defender->actual_time = sfClock_getElapsedTime(defender->clock);
    defender->elapsed_microsecond = \
    sfTime_asMicroseconds(defender->actual_time)\
    - sfTime_asMicroseconds(defender->last_time);
}
