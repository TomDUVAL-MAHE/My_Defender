/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** projectiles_moves.c
*/

#include "defender.h"

void calcul_move(projectile_t *projectile)
{
    float x = projectile->hitbox.left + projectile->hitbox.width / 2;
    float y = projectile->hitbox.top + projectile->hitbox.height / 2;

    projectile->move.x = (projectile->destination.x - x) * \
    projectile->speed_multiplier;
    projectile->move.y = (projectile->destination.y - y) * \
    projectile->speed_multiplier;
}

void rotate_projectile(projectile_t *projectile)
{
    double projectile_x = (double) {projectile->hitbox.left} \
    + (double) {projectile->hitbox.width} / 2.0;
    double projectile_y = (double) {projectile->hitbox.top} \
    + (double) {projectile->hitbox.height} / 2.0;
    double final_x = projectile->destination.x;
    double final_y = projectile->destination.y;
    double adjacent = sqrt(pow(projectile_x - projectile_x, 2.0) \
    + pow(final_y - projectile_y, 2.0));
    double hypo = sqrt(pow(final_x - projectile_x, 2.0) \
    + pow(final_y - projectile_y, 2.0));
    double res = acos(adjacent / hypo) * 180 / M_PI;

    if (final_x - projectile_x < 0 && final_y - projectile_y < 0)
        res = 270 - res;
    if (final_x - projectile_x < 0 && final_y - projectile_y >= 0)
        res = 90 + res;
    if (final_x - projectile_x >= 0 && final_y - projectile_y < 0)
        res = 270 + res;
    if (final_x - projectile_x >= 0 && final_y - projectile_y >= 0)
        res = 90 - res;
    sfSprite_setRotation(projectile->sprite, res);
}

void move_one_projectile(defender_t *defender, projectile_t *projectile)
{
    sfVector2f move;

    move.x = projectile->move.x * defender->elapsed_microsecond / 1000000;
    move.y = projectile->move.y * defender->elapsed_microsecond / 1000000;
    projectile->hitbox.left += move.x;
    projectile->hitbox.top += move.y;
    sfSprite_move(projectile->sprite, move);
}

void move_projectiles(defender_t *defender, projectile_t *projectile)
{
    while (projectile) {
        move_one_projectile(defender, projectile);
        projectile = check_for_projectile_action(defender, projectile);
    }
}
