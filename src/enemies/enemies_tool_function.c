/*
** EPITECH PROJECT, 2021
** tool function for enemy
** File description:
** for my_defender
*/

#include "defender.h"

void set_goot_rotation(enemy_t *enemy, tower_t *tower)
{
    double en_x = (double) {enemy->hitbox.left} + (double) \
    {enemy->hitbox.width} / 2.0;
    double en_y = (double) {enemy->hitbox.top} + (double) \
    {enemy->hitbox.height} / 2.0;
    double to_x = (double) {tower->hitbox.left} + (double) \
    {tower->hitbox.width} / 2.0;
    double to_y = (double) {tower->hitbox.top} + (double) \
    {tower->hitbox.height} / 2.0;
    double res = acos((sqrt(pow(en_x - en_x, 2.0) + pow(to_y - en_y, 2.0))) / \
    (sqrt(pow(to_x - en_x, 2.0) + pow(to_y - en_y, 2.0)))) * 180 / M_PI;

    if (to_x - en_x < 0 && to_y - en_y < 0)
        res = 270 - res;
    if (to_x - en_x < 0 && to_y - en_y >= 0)
        res = 90 + res;
    if (to_x - en_x >= 0 && to_y - en_y < 0)
        res = 270 + res;
    if (to_x - en_x >= 0 && to_y - en_y >= 0)
        res = 90 - res;
    sfSprite_setRotation(enemy->sprite, res);
}

void get_new_time(defender_t *defender, enemy_t *enemy, float x, float y)
{
    if (enemy->nearest_tower == NULL) {
        enemy->move = (sfVector2f) {0, 0};
        return;
    }
    enemy->move.x = (enemy->nearest_tower->hitbox.left +     \
    enemy->hitbox.width / 2 - x) * enemy->speed_multiplier * \
    enemy->speed_malus * defender->elapsed_microsecond / 3000000;
    enemy->move.y = (enemy->nearest_tower->hitbox.top + enemy->hitbox.height / \
    2 - y) * enemy->speed_multiplier * enemy->speed_malus * \
    defender->elapsed_microsecond / 3000000;
}
