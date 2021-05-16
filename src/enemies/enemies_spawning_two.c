/*
** EPITECH PROJECT, 2021
** function for help enemy spawning
** File description:
** for my_defender
*/

#include "defender.h"

void init_round(round_t *round)
{
    round->cooldown = 15000000;
    round->nb_round = 1;
    round->spawn_time = 15000000;
}

void spawn_round_two(defender_t *defender, int random)
{
    switch (random % 8) {
    case 4:
        spawn_enemy(&(defender->game), (sfVector2f) {960, 1180}, \
        (sfVector2f) {1920, 1280});
        break;
    case 5:
        spawn_enemy(&(defender->game), (sfVector2f) {0, 1180}, \
        (sfVector2f) {960, 1280});
        break;
    case 6:
        spawn_enemy(&(defender->game), (sfVector2f) {-100, 560}, \
        (sfVector2f) {-200, 1080});
        break;
    case 7:
        spawn_enemy(&(defender->game), (sfVector2f) {-100, 0}, \
        (sfVector2f) {-200, 560});
        break;
    }
}
