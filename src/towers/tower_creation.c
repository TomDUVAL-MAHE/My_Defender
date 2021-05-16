/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** tower_creation.c
*/

#include "defender.h"

void choose_type_for_tower(tower_t *new_tower, int type)
{
    if (type == 0)
        tower_type_base(new_tower);
    if (type == 1)
        tower_type_one(new_tower);
    if (type == 2)
        tower_type_two(new_tower);
    if (type == 3)
        tower_type_three(new_tower);
    if (type == 4)
        tower_type_four(new_tower);
}

void init_tower(defender_t *defender, tower_t *new_tower, int type, \
sfVector2f pos)
{
    new_tower->pos = pos;
    new_tower->clock = sfClock_create();
    new_tower->sprite = sfSprite_create();
    choose_type_for_tower(new_tower, type);
    new_tower->life += defender->game.life_bonus;
    new_tower->attack_cooldown = new_tower->attack_speed;
    sfSprite_setTexture(new_tower->sprite, new_tower->texture, sfTrue);
    sfSprite_setPosition(new_tower->sprite, (sfVector2f) \
    {new_tower->hitbox.left + new_tower->hitbox.width / 2, \
        new_tower->hitbox.top + new_tower->hitbox.height / 2});
    sfSprite_setScale(new_tower->sprite, (sfVector2f) \
    {new_tower->rect_anim.width / new_tower->hitbox.width, \
        new_tower->rect_anim.height / new_tower->hitbox.height});
    new_tower->next = NULL;
}

int tower_create(defender_t *defender, tower_t **tower, int type, \
sfVector2f pos)
{
    tower_t *new_tower;

    if (*tower != NULL && (*tower)->next != NULL) {
        return (tower_create(defender, &((*tower)->next), type, pos));
    } else {
        new_tower = malloc(sizeof(tower_t));
        if (new_tower == NULL)
            return (-1);
        init_tower(defender, new_tower, type, pos);
        if (*tower)
            (*tower)->next = new_tower;
        else
            *tower = new_tower;
        return (0);
    }
}
