/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** enemies_creation.c
*/

#include "enemies.h"

void create_enemy_sprite(enemy_t *enemy, char *path)
{
    enemy->texture = sfTexture_createFromFile(path, NULL);
    enemy->sprite = sfSprite_create();
    sfSprite_setTexture(enemy->sprite, enemy->texture, sfTrue);
    sfSprite_setPosition(enemy->sprite, (sfVector2f) {enemy->hitbox.left \
        + enemy->hitbox.width / 2, enemy->hitbox.top + enemy->hitbox.height \
        / 2});
    sfSprite_setOrigin(enemy->sprite, (sfVector2f) {enemy->anim_rect.width \
        / 2, enemy->anim_rect.height / 2});
    sfSprite_setScale(enemy->sprite, (sfVector2f) {(float) \
        {enemy->hitbox.width} / enemy->anim_rect.width, (float) \
        {enemy->hitbox.height} / enemy->anim_rect.height});
    sfSprite_setTextureRect(enemy->sprite, enemy->anim_rect);
}

void set_enemy_spe(enemy_t *enemy, sfVector2f size[2], float speed, int damage)
{
    enemy->speed_multiplier = speed;
    enemy->hitbox.width = size[0].x;
    enemy->hitbox.height = size[0].y;
    enemy->life = (int) {5000 / speed};
    if (enemy->type == 4)
        enemy->life *= 20;
    enemy->anim_rect.left = 0;
    enemy->anim_rect.top = 0;
    enemy->anim_rect.width = size[1].x;
    enemy->anim_rect.height = size[1].y;
    enemy->attack_damage = damage;
}

void init_enemy_type(enemy_t *enmy, int type)
{
    switch (type) {
    case 1:
        set_enemy_spe(enmy, (sfVector2f[2]) {{75, 75}, {200, 110}}, 1.0, 10);
        create_enemy_sprite(enmy, "assets/pictures/enemies/Enemy_1.png");
        break;
    case 2:
        set_enemy_spe(enmy, (sfVector2f[2]) {{50, 50}, {200, 168}}, 2.0, 6);
        create_enemy_sprite(enmy, "assets/pictures/enemies/Enemy_2.png");
        break;
    case 3:
        set_enemy_spe(enmy, (sfVector2f[2]) {{100, 100}, {200, 134}}, 0.66, 14);
        create_enemy_sprite(enmy, "assets/pictures/enemies/Enemy_3.png");
        break;
    case 4:
        set_enemy_spe(enmy, (sfVector2f[2]) {{200, 200}, {200, 67}}, 0.40, 350);
        create_enemy_sprite(enmy, "assets/pictures/enemies/boss.png");
        break;
    }
}

void init_enemy(enemy_t *enemy, int type, sfVector2f pos)
{
    enemy->type = type;
    enemy->hitbox.left = pos.x;
    enemy->hitbox.top = pos.y;
    enemy->anim_speed = 100000;
    enemy->anim_cooldown = enemy->anim_speed;
    enemy->clock = sfClock_create();
    init_enemy_type(enemy, type);
    enemy->attack_speed = 1000000 * 1.0;
    enemy->attack_cooldown = enemy->attack_speed;
    enemy->move = (sfVector2f) {0, 0};
    enemy->malus = false;
    enemy->malus_cooldown = 0;
    enemy->speed_malus = 1.0;
    enemy->nearest_tower = NULL;
    enemy->next_enemy = NULL;
}

int add_enemy(enemy_t **enemy, int type, sfVector2f pos)
{
    enemy_t *new_enemy;

    if (*enemy != NULL && (*enemy)->next_enemy != NULL) {
        return (add_enemy(&((*enemy)->next_enemy), type, pos));
    } else {
        new_enemy = malloc(sizeof(enemy_t));
        if (new_enemy == NULL)
            return (-1);
        init_enemy(new_enemy, type, pos);
        if (*enemy)
            (*enemy)->next_enemy = new_enemy;
        else
            *enemy = new_enemy;
        return (0);
    }
}
