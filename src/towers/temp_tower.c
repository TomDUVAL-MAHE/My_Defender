/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** temp_tower.c
*/

#include "defender.h"

void temp_display(sfRenderWindow *window, game_t *game)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    if (game->temp != NULL) {
        game->temp->hitbox.left = mouse.x - game->temp->hitbox.width / 2;
        game->temp->hitbox.top = mouse.y - game->temp->hitbox.height / 2;
        sfSprite_setPosition(game->temp->sprite, (sfVector2f) {mouse.x, \
            mouse.y});
        sfCircleShape_setPosition(game->temp->area_range, (sfVector2f) {mouse.x\
            - game->temp->range, mouse.y - game->temp->range});
        sfRenderWindow_drawSprite(window, game->temp->sprite, NULL);
        sfRenderWindow_drawCircleShape(window, game->temp->area_range, NULL);
    }
    show_tower_hitbox(window, game->temp);
}
