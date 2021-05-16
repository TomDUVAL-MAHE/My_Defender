/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** end_of_a_game
*/

#include "defender.h"

bool does_continue(defender_t *defender)
{
    tower_t *first_tower = defender->game.towers;

    if (!first_tower || first_tower->id_tower != 0) {
        defender->last_score = defender->game.score;
        defender->scene_id = MAIN_MENU_ID;
        defender->loose = true;
        return (false);
    }
    return (true);
}