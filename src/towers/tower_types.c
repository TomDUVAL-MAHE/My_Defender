/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** towers_types.c
*/

#include "defender.h"

void tower_type_base(tower_t *new_tower)
{
    tower_type_base_two(new_tower);
    sfSprite_setOrigin(new_tower->sprite, (sfVector2f) \
    {new_tower->hitbox.width / 2, new_tower->hitbox.height / 2});
    sfCircleShape_setOutlineThickness(new_tower->area_range, 2.00);
    sfSprite_setScale(new_tower->sprite, (sfVector2f) \
    {(float) {new_tower->hitbox.width} / new_tower->rect_anim.width, \
        (float) {new_tower->hitbox.height} / new_tower->rect_anim.height});
    sfCircleShape_setOutlineColor(new_tower->area_range, sfYellow);
    sfCircleShape_setFillColor(new_tower->area_range, \
    sfColor_fromRGBA(255, 255, 0, 25));
    sfCircleShape_setPosition(new_tower->area_range, (sfVector2f) \
    {new_tower->hitbox.left - new_tower->range + new_tower->hitbox.width / 2, \
        new_tower->hitbox.top - new_tower->range + \
        new_tower->hitbox.height / 2});
    sfCircleShape_setRadius(new_tower->area_range, new_tower->range);
}

void tower_type_one(tower_t *new_tower)
{
    tower_type_one_two(new_tower);
    new_tower->area_range = sfCircleShape_create();
    sfSprite_setOrigin(new_tower->sprite, \
    (sfVector2f) {new_tower->hitbox.width / 2, new_tower->hitbox.height / 2});
    sfCircleShape_setOutlineThickness(new_tower->area_range, 2.00);
    sfCircleShape_setOutlineColor(new_tower->area_range, sfYellow);
    sfCircleShape_setFillColor(new_tower->area_range, \
    sfColor_fromRGBA(255, 255, 0, 25));
    sfCircleShape_setPosition(new_tower->area_range, (sfVector2f) \
    {new_tower->hitbox.left - new_tower->range + new_tower->hitbox.width / 2, \
        new_tower->hitbox.top - new_tower->range + new_tower->hitbox.height \
        / 2});
    sfCircleShape_setRadius(new_tower->area_range, new_tower->range);
}

void tower_type_two(tower_t *new_tower)
{
    tower_type_two_two(new_tower);
    new_tower->area_range = sfCircleShape_create();
    sfSprite_setOrigin(new_tower->sprite, (sfVector2f) \
    {new_tower->hitbox.width / 2, new_tower->hitbox.height / 2});
    sfCircleShape_setOutlineThickness(new_tower->area_range, 2.00);
    sfCircleShape_setOutlineColor(new_tower->area_range, sfYellow);
    sfCircleShape_setFillColor(new_tower->area_range, \
    sfColor_fromRGBA(255, 255, 0, 25));
    sfCircleShape_setPosition(new_tower->area_range, \
    (sfVector2f) {new_tower->hitbox.left - new_tower->range + \
        new_tower->hitbox.width / 2, new_tower->hitbox.top - \
        new_tower->range + new_tower->hitbox.height / 2});
    sfCircleShape_setRadius(new_tower->area_range, new_tower->range);
}

void tower_type_three(tower_t *new_tower)
{
    tower_type_three_two(new_tower);
    sfSprite_setOrigin(new_tower->sprite, \
    (sfVector2f) {new_tower->hitbox.width / 2, new_tower->hitbox.height / 2});
    sfCircleShape_setOutlineThickness(new_tower->area_range, 2.00);
    sfCircleShape_setOutlineColor(new_tower->area_range, sfYellow);
    sfCircleShape_setFillColor(new_tower->area_range, \
    sfColor_fromRGBA(255, 255, 0, 25));
    sfCircleShape_setPosition(new_tower->area_range, (sfVector2f) \
    {new_tower->hitbox.left - new_tower->range + new_tower->hitbox.width / 2, \
        new_tower->hitbox.top - new_tower->range + new_tower->hitbox.height \
        / 2});
    sfCircleShape_setRadius(new_tower->area_range, new_tower->range);
}

void tower_type_four(tower_t *new_tower)
{
    tower_type_four_two(new_tower);
    sfSprite_setOrigin(new_tower->sprite, \
    (sfVector2f) {new_tower->rect_anim.width / 2, \
        new_tower->rect_anim.height / 2});
    sfCircleShape_setOutlineThickness(new_tower->area_range, 2.00);
    sfCircleShape_setOutlineColor(new_tower->area_range, sfYellow);
    sfCircleShape_setFillColor(new_tower->area_range, \
    sfColor_fromRGBA(255, 255, 0, 25));
    sfCircleShape_setPosition(new_tower->area_range, (sfVector2f) \
    {new_tower->hitbox.left - new_tower->range + new_tower->hitbox.width / 2, \
        new_tower->hitbox.top - new_tower->range + new_tower->hitbox.height \
        / 2});
    sfCircleShape_setRadius(new_tower->area_range, new_tower->range);
}

