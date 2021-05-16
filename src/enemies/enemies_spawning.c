/*
** EPITECH PROJECT, 2021
** manager for spawning enemy
** File description:
** for my_defender
*/

#include "defender.h"

sfVector2f create_pos_for_spawn(sfVector2f limite_one, sfVector2f limite_two)
{
    int modulo_x = limite_two.x - limite_one.x;
    int modulo_y = limite_two.y - limite_one.y;
    int rand_x = rand();
    int rand_y = rand();
    sfVector2f pos;

    modulo_x = (modulo_x == 0 ? 1 : modulo_x);
    modulo_y = (modulo_y == 0 ? 1 : modulo_y);
    if (limite_one.x < 0)
        pos.x = limite_one.x - (rand_x % modulo_x);
    else
        pos.x = limite_one.x + (rand_x % modulo_x);
    if (limite_one.y < 0)
        pos.y = limite_one.y - (rand_y % modulo_y);
    else
        pos.y = limite_one.y + (rand_y % modulo_y);
    return (pos);
}

void spawn_enemy(game_t *game, sfVector2f limite_one, sfVector2f limite_two)
{
    int rand_type;
    if ((game->round.nb_round % 10) == 0) {
        for (int type_boss = 0; type_boss != game->round.nb_round / 10; \
        type_boss++) {
            add_enemy(&(game->enemies), 4, create_pos_for_spawn(limite_one, \
            limite_two));
        }
    }
    for (int i = 0; i < game->round.nb_round * 3; i++) {
        rand_type = rand() % 3 + 1;
        add_enemy(&(game->enemies), rand_type, \
        create_pos_for_spawn(limite_one, limite_two));
    }
}

void set_up_next_round(defender_t *defender)
{
    int random = rand();

    switch (random % 8) {
    case 0:
        spawn_enemy(&(defender->game), (sfVector2f) {0, -100}, \
        (sfVector2f) {960, -200});
        break;
    case 1:
        spawn_enemy(&(defender->game), (sfVector2f) {960, -100}, \
        (sfVector2f) {1920, -100});
        break;
    case 2:
        spawn_enemy(&(defender->game), (sfVector2f) {2020, 0}, \
        (sfVector2f) {2120, 560});
        break;
    case 3:
        spawn_enemy(&(defender->game), (sfVector2f) {2020, 560}, \
        (sfVector2f) {2120, 1080});
        break;
    }
    spawn_round_two(defender, random);
}

void spawn_a_round(defender_t *defender, round_t *round)
{
    if (round->cooldown <= 0) {
        set_up_next_round(defender);
        round->nb_round = round->nb_round + 1;
        round->cooldown = round->spawn_time;
    }
    round->cooldown -= defender->elapsed_microsecond;
}

void enemy_spawn_manager(defender_t *defender)
{
    spawn_a_round(defender, &(defender->game.round));
}
