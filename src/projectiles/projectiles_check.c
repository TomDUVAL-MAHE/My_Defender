/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** projectiles_check.c
*/

#include "defender.h"

enemy_t *check_colisions(projectile_t *projectile, enemy_t *enemy)
{
    while (enemy) {
        if (sfFloatRect_intersects(&(projectile->hitbox), &(enemy->hitbox), \
        NULL) == sfTrue) {
            return (enemy);
        }
        enemy = enemy->next_enemy;
    }
    return (NULL);
}

bool check_destination(projectile_t *projectile)
{
    float depart_x = projectile->departure.x;
    float depart_y = projectile->departure.y;
    float mid_proj_x = projectile->hitbox.left + projectile->hitbox.width / 2;
    float mid_proj_y = projectile->hitbox.top + projectile->hitbox.height / 2;
    float length = sqrtf(pow(depart_x - mid_proj_x, 2) + pow(depart_y -\
    mid_proj_y, 2));

    if (length >= projectile->range)
        return (true);
    return (false);
}

projectile_t *check_for_projectile_action(defender_t *defender, \
projectile_t *projectile)
{
    enemy_t *colide = check_colisions(projectile, defender->game.enemies);
    projectile_t *next;
    bool arrived = check_destination(projectile);

    if (colide != NULL) {
        if (projectile->type == 3)
            projectile_explode(defender, projectile, defender->game.enemies);
        projectile_attack(defender, projectile, colide);
        if (projectile->pierce == false) {
            next = projectile->next;
            destroy_only_one_projectile(&(defender->game), projectile);
            return (next);
        }
    }
    if (arrived == true) {
        next = projectile->next;
        destroy_only_one_projectile(&(defender->game), projectile);
        return (next);
    }
    return (projectile->next);
}
