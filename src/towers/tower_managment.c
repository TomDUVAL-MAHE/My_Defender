/*
** EPITECH PROJECT, 2021
** for manag tower
** File description:
** for my_defender
*/

#include "defender.h"

void nearest_enemy(tower_t *tower, enemy_t *enemy)
{
    int x = tower->hitbox.left + tower->hitbox.width / 2;
    int y = tower->hitbox.top + tower->hitbox.height / 2;
    float distance = 2147483647.0;
    float actual_distance;

    tower->nearest_enemy = NULL;
    while (enemy) {
        actual_distance = sqrt(pow(enemy->hitbox.left + enemy->hitbox.width \
        / 2 - x, 2) + pow(enemy->hitbox.top + enemy->hitbox.height / 2- y, 2));
        if (actual_distance < distance) {
            tower->nearest_enemy = enemy;
            distance = actual_distance;
        }
        enemy = enemy->next_enemy;
    }
}

bool is_in_area_range(tower_t *tower, enemy_t *enemy)
{
    float length = 0;
    float tower_x = tower->hitbox.left + tower->hitbox.width / 2;
    float tower_y = tower->hitbox.top + tower->hitbox.height / 2;

    if (enemy == NULL)
        return (false);
    length = sqrtf(pow(enemy->hitbox.left - tower_x, 2) + \
    pow(enemy->hitbox.top - tower_y, 2));
    if (length <= tower->range)
        return (true);
    if (is_in_area_range_two(tower, enemy, tower_x, tower_y) == true)
        return (true);
    return (false);
}

void rotate_tower(tower_t *tower, enemy_t *enemy)
{
    double to_x = (double) {tower->hitbox.left} + (double) \
    {tower->hitbox.width} / 2.0;
    double to_y = (double) {tower->hitbox.top} + (double) \
    {tower->hitbox.height} / 2.0;
    double en_x = (double) {enemy->hitbox.left} + (double) \
    {enemy->hitbox.width} / 2.0;
    double en_y = (double) {enemy->hitbox.top} + (double) \
    {enemy->hitbox.height} / 2.0;
    double res = acos((sqrt(pow(to_x - to_x, 2.0) + pow(en_y - to_y, 2.0))) / \
    (sqrt(pow(en_x - to_x, 2.0) + pow(en_y - to_y, 2.0)))) * 180 / M_PI;

    if (en_x - to_x < 0 && en_y - to_y < 0)
        res = 0 - res;
    if (en_x - to_x < 0 && en_y - to_y >= 0)
        res = 180 + res;
    if (en_x - to_x >= 0 && en_y - to_y < 0)
        res = 0 + res;
    if (en_x - to_x >= 0 && en_y - to_y >= 0)
        res = 180 - res;
    sfSprite_setRotation(tower->sprite, res);
}

void attack_enemy(defender_t *defender, tower_t *tower)
{
    float middle_tower_x = tower->hitbox.left + tower->hitbox.width / 2;
    float middle_tower_y = tower->hitbox.top + tower->hitbox.height / 2;
    float middle_enemy_x = tower->nearest_enemy->hitbox.left + \
    tower->nearest_enemy->hitbox.width / 2;
    float middle_enemy_y = tower->nearest_enemy->hitbox.top + \
    tower->nearest_enemy->hitbox.height / 2;

    if (tower->id_tower != 0 && tower->id_tower != 4)
        rotate_tower(tower, tower->nearest_enemy);
    if (tower->attack_cooldown <= 0) {
        if (tower->id_tower != 0 && tower->id_tower != 4) {
            add_projectile(&(defender->game.projectiles), tower->id_tower, \
            (sfVector2f) {middle_tower_x, middle_tower_y}, \
            (sfVector2f) {middle_enemy_x, middle_enemy_y});
        }
        tower->attack_cooldown = tower->attack_speed;
    }
    tower->attack_cooldown -= defender->elapsed_microsecond;
}

void tower_managment(defender_t *defender, tower_t *tower, enemy_t *enemies)
{
    while (tower) {
        if (tower->id_tower == 0 || tower->id_tower == 4)
            get_energy_for_tower(defender, tower);
        nearest_enemy(tower, enemies);
        if (is_in_area_range(tower, tower->nearest_enemy))
            attack_enemy(defender, tower);
        tower = tower->next;
    }
}
