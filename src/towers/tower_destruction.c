/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** tower_destruction.c
*/

#include "defender.h"

void destroy_one_tower_s_content(tower_t *tower)
{
    sfTexture_destroy(tower->texture);
    sfSprite_destroy(tower->sprite);
    sfClock_destroy(tower->clock);
    sfCircleShape_destroy(tower->area_range);
}

void destroy_only_one_tower(game_t *game, tower_t *tower)
{
    tower_t *previous = game->towers;
    if (game->towers == tower) {
        game->towers = tower->next;
        destroy_one_tower_s_content(tower);
        free(tower);
        return;
    }
    while (previous->next != tower)
        previous = previous->next;
    previous->next = tower->next;
    destroy_one_tower_s_content(tower);
    free(tower);
}

void destroy_all_towers(tower_t **tower)
{
    tower_t *tower_to_destroy;
    tower_t *actual = *tower;

    while (actual) {
        tower_to_destroy = actual;
        actual = actual->next;
        sfTexture_destroy(tower_to_destroy->texture);
        sfSprite_destroy(tower_to_destroy->sprite);
        sfClock_destroy(tower_to_destroy->clock);
        sfCircleShape_destroy(tower_to_destroy->area_range);
        free(tower_to_destroy);
    }
    *tower = NULL;
}
