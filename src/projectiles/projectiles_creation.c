/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** projectiles_creation.c
*/

#include "defender.h"

void create_projectile_sprite(projectile_t *projectile, char *path)
{
    projectile->texture = sfTexture_createFromFile(path, NULL);
    projectile->sprite = sfSprite_create();
    sfSprite_setTexture(projectile->sprite, projectile->texture, sfTrue);
    sfSprite_setPosition(projectile->sprite, (sfVector2f) \
    {projectile->hitbox.left + projectile->hitbox.width\
        / 2, projectile->hitbox.top +\
        projectile->hitbox.height / 2});
    sfSprite_setOrigin(projectile->sprite, (sfVector2f) \
    {projectile->anim_rect.width / 2, \
        projectile->anim_rect.height / 2});
    sfSprite_setScale(projectile->sprite, (sfVector2f) \
    {(float) {projectile->hitbox.width} \
        / projectile->anim_rect.width, (float) \
        {projectile->hitbox.height} / \
        projectile->anim_rect.height});
    sfSprite_setTextureRect(projectile->sprite, projectile->anim_rect);
}

void init_general_projectile(projectile_t *projectile, int type, \
sfVector2f pos, sfVector2f destination)
{
    projectile->type = type;
    projectile->departure = pos;
    projectile->destination = destination;
    projectile->hitbox.left = pos.x;
    projectile->hitbox.top = pos.y;
    projectile->anim_rect.left = 0;
    projectile->anim_rect.top = 0;
    init_projectile_type(projectile, type);
    projectile->anim_cooldown = projectile->anim_speed;
    projectile->texture_size = sfTexture_getSize(projectile->texture);
    projectile->hitbox.left -= projectile->hitbox.width / 2;
    projectile->hitbox.top -= projectile->hitbox.height / 2;
    calcul_move(projectile);
    rotate_projectile(projectile);
    projectile->next = NULL;
}

projectile_t *add_projectile(projectile_t **projectile, int type, \
sfVector2f pos, sfVector2f destination)
{
    projectile_t *new_projectile;

    if (*projectile != NULL && (*projectile)->next != NULL) {
        return (add_projectile(&((*projectile)->next), type, pos, destination));
    } else {
        new_projectile = malloc(sizeof(projectile_t));
        if (new_projectile == NULL)
            return (NULL);
        init_general_projectile(new_projectile, type, pos, destination);
        if (*projectile)
            (*projectile)->next = new_projectile;
        else
            *projectile = new_projectile;
        return (new_projectile);
    }
}
