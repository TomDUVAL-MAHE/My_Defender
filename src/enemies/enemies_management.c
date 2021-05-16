/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** enemies_management.c
*/

#include "enemies.h"

void draw_enemies(sfRenderWindow *window, defender_t *defender, enemy_t *enemy)
{
    while (enemy) {
        if (enemy->anim_cooldown <= 0) {
            enemy->anim_rect.left += 200;
            enemy->anim_cooldown = enemy->anim_speed;
            (enemy->anim_rect.left >= 1350 ? enemy->anim_rect.left = 0 : 0);
            sfSprite_setTextureRect(enemy->sprite, enemy->anim_rect);
        }
        enemy->anim_cooldown -= defender->elapsed_microsecond;
        sfRenderWindow_drawSprite(window, enemy->sprite, NULL);
        enemy = enemy->next_enemy;
    }
}

void destroy_one_enemy_s_content(enemy_t *enemy)
{
    sfTexture_destroy(enemy->texture);
    sfSprite_destroy(enemy->sprite);
    sfClock_destroy(enemy->clock);
}

void destroy_all_enemies(enemy_t **enemy)
{
    enemy_t *enemy_to_destroy;
    enemy_t *actual = *enemy;

    while (actual) {
        enemy_to_destroy = actual;
        actual = actual->next_enemy;
        destroy_one_enemy_s_content(enemy_to_destroy);
        free(enemy_to_destroy);
    }
    *enemy = NULL;
}

void destroy_only_one_enemy(game_t *game, enemy_t *enemy)
{
    enemy_t *previous = game->enemies;

    if (game->enemies == enemy) {
        game->enemies = enemy->next_enemy;
        destroy_one_enemy_s_content(enemy);
        free(enemy);
        return;
    }
    while (previous->next_enemy != enemy)
        previous = previous->next_enemy;
    previous->next_enemy = enemy->next_enemy;
    destroy_one_enemy_s_content(enemy);
    free(enemy);
}
