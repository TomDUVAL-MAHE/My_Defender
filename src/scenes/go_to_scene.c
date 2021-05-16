/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** go_to_scene.c
*/

#include "defender.h"

void make_changment_for_game(game_t *game)
{
    game->coin = 50;
    game->score = 0;
    game->sell_mode = false;
    game->enemies = NULL;
    game->towers = NULL;
    game->temp = NULL;
    game->projectiles = NULL;
}

void make_game_start(defender_t *defender)
{
    defender->scene_id = GAME_ID;
}

void return_to_main_menu(defender_t *defender)
{
    defender->scene_id = MAIN_MENU_ID;
}
