/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** enemies_moves.c
*/

#include "enemies.h"

void rotate_enemy(enemy_t *enemy, tower_t *tower)
{
    if (tower == NULL)
        return;
    set_goot_rotation(enemy, tower);
}

void which_tower_is_the_nearest(defender_t *defender, enemy_t *enemy)
{
    float x = enemy->hitbox.left + enemy->hitbox.width / 2;
    float y = enemy->hitbox.top + enemy->hitbox.height / 2;
    float distance = 2147483647.0;
    float a_d;
    tower_t *tower = defender->game.towers;

    enemy->nearest_tower = NULL;
    while (tower) {
        a_d = sqrt(pow(tower->hitbox.left + enemy->hitbox.width / 2 - x, 2) + \
        pow(tower->hitbox.top + tower->hitbox.height / 2 - y, 2));
        if (a_d < distance) {
            enemy->nearest_tower = tower;
            distance = a_d;
        }
        tower = tower->next;
    }
    get_new_time(defender, enemy, x, y);
}

void enemy_attack(defender_t *defender, enemy_t *enemy)
{
    if (enemy->nearest_tower == NULL)
        return;
    if (enemy->attack_cooldown <= 0) {
        enemy->nearest_tower->life -= enemy->attack_damage;
        enemy->attack_cooldown = enemy->attack_speed;
    }
    enemy->attack_cooldown -= defender->elapsed_microsecond;
    if (enemy->nearest_tower->life <= 0) {
        destroy_only_one_tower(&(defender->game), enemy->nearest_tower);
    }
}

void reduce_malus(defender_t *defender, enemy_t *enemy)
{
    if (enemy->malus == true) {
        if (enemy->malus_cooldown <= 0) {
            enemy->malus = false;
            enemy->speed_malus = 1.0;
        }
        enemy->malus -= defender->elapsed_microsecond;
    }
}

void move_ennemies(defender_t *defender, enemy_t *enemy)
{
    while (enemy) {
        which_tower_is_the_nearest(defender, enemy);
        rotate_enemy(enemy, enemy->nearest_tower);
        if (enemy->nearest_tower && sfFloatRect_intersects(&(enemy->hitbox), \
        &(enemy->nearest_tower->hitbox), NULL) == sfFalse) {
            enemy->hitbox.left += enemy->move.x;
            enemy->hitbox.top += enemy->move.y;
            sfSprite_move(enemy->sprite, enemy->move);
        } else {
            enemy_attack(defender, enemy);
        }
        reduce_malus(defender, enemy);
        enemy = enemy->next_enemy;
    }
}
