/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** tower_button_functions.c
*/

#include "defender.h"

void add_tower_one(defender_t *defender)
{
    defender->game.tower_menu.displayed = false;
    tower_create(defender, &(defender->game.temp), 1, (sfVector2f) {0, 0});
}

void add_tower_two(defender_t *defender)
{
    defender->game.tower_menu.displayed = false;
    tower_create(defender, &(defender->game.temp), 2, (sfVector2f) {0, 0});
}

void add_tower_three(defender_t *defender)
{
    defender->game.tower_menu.displayed = false;
    tower_create(defender, &(defender->game.temp), 3, (sfVector2f) {0, 0});
}

void add_tower_four(defender_t *defender)
{
    defender->game.tower_menu.displayed = false;
    tower_create(defender, &(defender->game.temp), 4, (sfVector2f) {0, 0});
}
