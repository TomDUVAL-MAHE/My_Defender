/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** projectiles_type.c
*/

#include "defender.h"

void init_projectile_one(projectile_t *projectile)
{
    projectile->speed_multiplier = 1.0;
    projectile->hitbox.width = 30;
    projectile->hitbox.height = 30;
    projectile->anim_rect.width = 102;
    projectile->anim_rect.height = 56;
    projectile->anim_speed = 100000;
    projectile->pierce = false;
    projectile->damage = 2000;
    projectile->range = 400.0;
    create_projectile_sprite(projectile, \
    "assets/pictures/shoot_tower/shoot_simple.png");
}

void init_projectile_two(projectile_t *projectile)
{
    projectile->speed_multiplier = 1.0;
    projectile->hitbox.width = 60;
    projectile->hitbox.height = 60;
    projectile->anim_rect.width = 96;
    projectile->anim_rect.height = 64;
    projectile->anim_speed = 50000;
    projectile->pierce = true;
    projectile->damage = 1;
    projectile->range = 200.0;
    create_projectile_sprite(projectile, \
    "assets/pictures/shoot_tower/shoot_flamme.png");
}

void init_projectile_three(projectile_t *projectile)
{
    projectile->speed_multiplier = 2.0;
    projectile->hitbox.width = 30;
    projectile->hitbox.height = 30;
    projectile->anim_rect.width = 51;
    projectile->anim_rect.height = 38;
    projectile->anim_speed = 100000;
    projectile->pierce = false;
    projectile->damage = 0;
    projectile->range = 300.0;
    create_projectile_sprite(projectile, \
    "assets/pictures/shoot_tower/shoot_missile.png");
}

void init_projectile_four(projectile_t *projectile)
{
    projectile->speed_multiplier = 0.0;
    projectile->hitbox.width = 130;
    projectile->hitbox.height = 130;
    projectile->anim_rect.width = 102;
    projectile->anim_rect.height = 114;
    projectile->anim_speed = 100000;
    projectile->pierce = true;
    projectile->damage = 4000;
    projectile->range = 130;
    create_projectile_sprite(projectile, \
    "assets/pictures/shoot_tower/shoot_missile_exp.png");
}

void init_projectile_type(projectile_t *projectile, int type)
{
    switch (type) {
    case 1:
        init_projectile_one(projectile);
        break;
    case 2:
        init_projectile_two(projectile);
        break;
    case 3:
        init_projectile_three(projectile);
        break;
    case 4:
        init_projectile_four(projectile);
        break;
    }
}
