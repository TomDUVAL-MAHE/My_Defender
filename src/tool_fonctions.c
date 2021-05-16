/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** tool_fonctions.c
*/

#include "defender.h"

void draw_sprite_outline(sfRenderWindow *window, sfSprite *sprite)
{
    sfFloatRect global = sfSprite_getGlobalBounds(sprite);
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setPosition(rect, (sfVector2f) {global.left, global.top});
    sfRectangleShape_setSize(rect, (sfVector2f) {global.width, global.height});
    sfRectangleShape_setFillColor(rect, sfTransparent);
    sfRectangleShape_setOutlineColor(rect, sfYellow);
    sfRectangleShape_setOutlineThickness(rect, 2.0);
    sfRenderWindow_drawRectangleShape(window, rect, NULL);
    sfRectangleShape_destroy(rect);
}

bool is_in_area_range_two(tower_t *tower, enemy_t *enemy, float tower_x, \
float tower_y)
{
    float length = 0;

    length = sqrtf(pow((enemy->hitbox.left + enemy->hitbox.width) \
    - tower_x, 2) + pow(enemy->hitbox.top - tower_y, 2));
    if (length <= tower->range)
        return (true);
    length = sqrtf(pow(enemy->hitbox.left - tower_x, 2) + \
    pow((enemy->hitbox.top + enemy->hitbox.height) - tower_y, 2));
    if (length <= tower->range)
        return (true);
    length = sqrtf(pow((enemy->hitbox.left + enemy->hitbox.width) - tower_x, 2)\
    + pow((enemy->hitbox.top + enemy->hitbox.height) - tower_y, 2));
    if (length <= tower->range)
        return (true);
    return (false);
}

void show_enemy_hitbox(sfRenderWindow *window, enemy_t *enemy)
{
    while (enemy) {
        sfRectangleShape *rect = sfRectangleShape_create();
        sfRectangleShape_setOutlineColor(rect, sfRed);
        sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(255, 0, 0, 55));
        sfRectangleShape_setOutlineThickness(rect, 1);
        sfRectangleShape_setPosition(rect, (sfVector2f) {enemy->hitbox.left, \
            enemy->hitbox.top});
        sfRectangleShape_setSize(rect, (sfVector2f) {enemy->hitbox.width, \
            enemy->hitbox.height});
        sfRenderWindow_drawRectangleShape(window, rect, NULL);
        sfRectangleShape_destroy(rect);
        enemy = enemy->next_enemy;
    }
}

void show_tower_hitbox(sfRenderWindow *window, tower_t *tower)
{
    while (tower) {
        sfRectangleShape *rect = sfRectangleShape_create();
        sfRectangleShape_setOutlineColor(rect, sfRed);
        sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(255, 0, 0, 55));
        sfRectangleShape_setOutlineThickness(rect, 1);
        sfRectangleShape_setPosition(rect, (sfVector2f) {tower->hitbox.left, \
            tower->hitbox.top});
        sfRectangleShape_setSize(rect, (sfVector2f) {tower->hitbox.width, \
            tower->hitbox.height});
        sfRenderWindow_drawRectangleShape(window, rect, NULL);
        sfRectangleShape_destroy(rect);
        tower = tower->next;
    }
}

void show_projectile_hitbox(sfRenderWindow *window, projectile_t *projectile)
{
    while (projectile) {
        sfRectangleShape *rect = sfRectangleShape_create();
        sfRectangleShape_setOutlineColor(rect, sfRed);
        sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(255, 0, 0, 55));
        sfRectangleShape_setOutlineThickness(rect, 1);
        sfRectangleShape_setPosition(rect, (sfVector2f) \
        {projectile->hitbox.left, projectile->hitbox.top});
        sfRectangleShape_setSize(rect, (sfVector2f) {projectile->hitbox.width, \
            projectile->hitbox.height});
        sfRenderWindow_drawRectangleShape(window, rect, NULL);
        sfRectangleShape_destroy(rect);
        projectile = projectile->next;
    }
}
