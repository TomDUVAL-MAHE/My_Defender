/*
** EPITECH PROJECT, 2021
** tower type managment
** File description:
** for my_defender
*/

#include "defender.h"

void tower_type_base_two(tower_t *new_tower)
{
    new_tower->texture = \
    sfTexture_createFromFile("./assets/pictures/tower/base.png", NULL);
    new_tower->id_tower = 0;
    new_tower->attack_speed = 20000000;
    new_tower->life = 1000;
    new_tower->range = 0;
    new_tower->cost = 0;
    new_tower->rect_anim.left = 0;
    new_tower->rect_anim.top = 0;
    new_tower->rect_anim.width = 183;
    new_tower->rect_anim.height = 183;
    new_tower->hitbox.left = new_tower->pos.x;
    new_tower->hitbox.top = new_tower->pos.y;
    new_tower->hitbox.width = 183;
    new_tower->hitbox.height = 183;
    new_tower->area_range = sfCircleShape_create();
}

void tower_type_one_two(tower_t *new_tower)
{
    new_tower->texture = \
    sfTexture_createFromFile("./assets/pictures/tower/type_one.png", NULL);
    new_tower->id_tower = 1;
    new_tower->attack_speed = 750000;
    new_tower->cost = 40;
    new_tower->life = 100;
    new_tower->range = 400;
    new_tower->rect_anim.left = 0;
    new_tower->rect_anim.top = 0;
    new_tower->rect_anim.width = 54;
    new_tower->rect_anim.height = 93;
    new_tower->hitbox.left = new_tower->pos.x;
    new_tower->hitbox.top = new_tower->pos.y;
    new_tower->hitbox.width = 60;
    new_tower->hitbox.height = 100;
}

void tower_type_two_two(tower_t *new_tower)
{
    new_tower->texture = \
    sfTexture_createFromFile("./assets/pictures/tower/type_two.png", NULL);
    new_tower->id_tower = 2;
    new_tower->attack_speed = 100000;
    new_tower->life = 100;
    new_tower->cost = 75;
    new_tower->range = 200;
    new_tower->rect_anim.left = 0;
    new_tower->rect_anim.top = 0;
    new_tower->rect_anim.width = 54;
    new_tower->rect_anim.height = 93;
    new_tower->hitbox.left = new_tower->pos.x;
    new_tower->hitbox.top = new_tower->pos.y;
    new_tower->hitbox.width = 60;
    new_tower->hitbox.height = 100;
}

void tower_type_three_two(tower_t *new_tower)
{
    new_tower->texture = \
    sfTexture_createFromFile("./assets/pictures/tower/type_three.png", NULL);
    new_tower->id_tower = 3;
    new_tower->attack_speed = 1300000;
    new_tower->life = 100;
    new_tower->range = 300;
    new_tower->cost = 100;
    new_tower->rect_anim.left = 0;
    new_tower->rect_anim.top = 0;
    new_tower->rect_anim.width = 94;
    new_tower->rect_anim.height = 87;
    new_tower->hitbox.left = new_tower->pos.x;
    new_tower->hitbox.top = new_tower->pos.y;
    new_tower->hitbox.width = 100;
    new_tower->hitbox.height = 90;
    new_tower->area_range = sfCircleShape_create();
}

void tower_type_four_two(tower_t *new_tower)
{
    new_tower->texture = \
    sfTexture_createFromFile("./assets/pictures/tower/minning.png", NULL);
    new_tower->id_tower = 4;
    new_tower->attack_speed = 5000000;
    new_tower->life = 100;
    new_tower->range = 0;
    new_tower->cost = 30;
    new_tower->rect_anim.left = 0;
    new_tower->rect_anim.top = 0;
    new_tower->rect_anim.width = 89;
    new_tower->rect_anim.height = 73;
    new_tower->hitbox.left = new_tower->pos.x;
    new_tower->hitbox.top = new_tower->pos.y;
    new_tower->hitbox.width = 90;
    new_tower->hitbox.height = 80;
    new_tower->area_range = sfCircleShape_create();
}
