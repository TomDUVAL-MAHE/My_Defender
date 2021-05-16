/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** projectiles_display.c
*/

#include "defender.h"

void projectiles_animations(defender_t *defender, projectile_t *projectile, \
bool *reset_anim)
{
    if (projectile->anim_cooldown <= 0) {
        projectile->anim_rect.left += projectile->anim_rect.width;
        projectile->anim_cooldown = projectile->anim_speed;
        *reset_anim = (projectile->anim_rect.left >= (int) \
        {projectile->texture_size.x - projectile->anim_rect.width} ? true : \
        false);
        (projectile->anim_rect.left >= (int) {projectile->texture_size.x - \
            projectile->anim_rect.width} ? projectile->anim_rect.left = 0 : 0);
        sfSprite_setTextureRect(projectile->sprite, projectile->anim_rect);
    }
    projectile->anim_cooldown -= defender->elapsed_microsecond;
}

void creation_of_explosion_if_must(projectile_t *projectile)
{
    if (projectile->type == 4) {
        create_projectile_sprite(projectile, \
        "assets/pictures/shoot_tower/shoot_missile_exp.png");
    }
}

void draw_projectiles(sfRenderWindow *window, defender_t *defender, \
projectile_t *projectile)
{
    bool reset_anim;
    projectile_t *temp = NULL;

    while (projectile) {
        reset_anim = false;
        projectiles_animations(defender, projectile, &reset_anim);
        if (projectile->type == 4 && reset_anim == true) {
            temp = projectile;
            projectile = projectile->next;
            destroy_only_one_projectile(&(defender->game), temp);
        } else {
            creation_of_explosion_if_must(projectile);
            sfRenderWindow_drawSprite(window, projectile->sprite, NULL);
            projectile = projectile->next;
        }
    }
}
