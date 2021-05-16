/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** projectiles_destruction.c
*/

#include "defender.h"

void destroy_one_projectile_s_content(projectile_t *projectile)
{
    sfTexture_destroy(projectile->texture);
    sfSprite_destroy(projectile->sprite);
}

void destroy_all_projectiles(projectile_t **projectile)
{
    projectile_t *projectile_to_destroy;
    projectile_t *actual = *projectile;

    while (actual) {
        projectile_to_destroy = actual;
        actual = actual->next;
        destroy_one_projectile_s_content(projectile_to_destroy);
        free(projectile_to_destroy);
    }
    *projectile = NULL;
}

void destroy_only_one_projectile(game_t *game, projectile_t *projectile)
{
    projectile_t *previous = game->projectiles;

    if (game->projectiles == projectile) {
        game->projectiles = projectile->next;
        destroy_one_projectile_s_content(projectile);
        free(projectile);
        return;
    }
    while (previous->next != projectile)
        previous = previous->next;
    previous->next = projectile->next;
    destroy_one_projectile_s_content(projectile);
    free(projectile);
}
