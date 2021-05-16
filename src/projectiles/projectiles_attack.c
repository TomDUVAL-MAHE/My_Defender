/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** projectile_attack.c
*/

#include "defender.h"

void projectile_explode(defender_t *defender, projectile_t *projectile, \
enemy_t *enemies)
{
    sfVector2f explo_pos;
    projectile_t *explode;

    explo_pos.x = projectile->hitbox.left + projectile->hitbox.width / 2;
    explo_pos.y = \
    projectile->hitbox.top + projectile->hitbox.height / 2;
    explode = add_projectile(&(defender->game.projectiles), 4, \
    explo_pos, explo_pos);
    while (enemies) {
        if (sfFloatRect_intersects(&(explode->hitbox), \
            &(enemies->hitbox), NULL) == sfTrue)
            enemies->life -= explode->damage;
        enemies = enemies->next_enemy;
    }
    explode->damage = 0;
}

void arrived_at_destination(defender_t *defender, projectile_t *projectile)
{
    if (projectile->type != 3) {
        destroy_only_one_projectile(&(defender->game), projectile);
        return;
    }
    destroy_only_one_projectile(&(defender->game), projectile);
}

void projectile_attack(defender_t *defender, projectile_t *projectile, \
enemy_t *enemy)
{
    enemy->life -= projectile->damage * defender->game.atq_bonus;
    if (projectile->type == 2) {
        enemy->malus = true;
        enemy->speed_malus = 0.6;
        enemy->malus_cooldown = 2000000;
    }
    if (enemy->life <= 0) {
        get_energy_for_enemy_destroy(&(defender->game), enemy);
        destroy_only_one_enemy(&(defender->game), enemy);
    }
}
