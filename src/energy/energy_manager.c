/*
** EPITECH PROJECT, 2021
** energy manager
** File description:
** for my_defender
*/

#include "defender.h"

void set_new_text(game_t *game)
{
    sfText_setString(game->text_score, change_int_into_str(game->score));
    sfText_setString(game->text_coin, change_int_into_str(game->coin));
}

void other_choice(game_t *game, enemy_t *enemy)
{
    switch (enemy->type) {
    case 3:
        game->coin += 50;
        game->score += 50;
        set_new_text(game);
        break;
    case 4:
        game->coin += 500;
        game->score += 500;
        set_new_text(game);
        break;
    }
}

void get_energy_for_enemy_destroy(game_t *game, enemy_t *enemy)
{
    switch (enemy->type) {
    case 1:
        game->coin += 25;
        game->score += 25;
        set_new_text(game);
        break;
    case 2:
        game->coin += 30;
        game->score += 30;
        set_new_text(game);
        break;
    }
    other_choice(game, enemy);
}

void get_energy_for_tower(defender_t *defender, tower_t *tower)
{
    if (tower->attack_cooldown <= 0) {
        switch (tower->id_tower) {
        case 0:
            defender->game.coin += 20;
            sfText_setString(defender->game.text_score, \
            change_int_into_str(defender->game.score));
            sfText_setString(defender->game.text_coin, \
            change_int_into_str(defender->game.coin));
            break;
        case 4:
            defender->game.coin += 7;
            sfText_setString(defender->game.text_score, \
            change_int_into_str(defender->game.score));
            sfText_setString(defender->game.text_coin, \
            change_int_into_str(defender->game.coin));
            break;
        }
        tower->attack_cooldown = tower->attack_speed;
    }
    tower->attack_cooldown -= defender->elapsed_microsecond;
}
