/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** tower_display
*/

#include "defender.h"

void tower_display(sfRenderWindow *window, defender_t *defender, tower_t *tower)
{
    if (defender->game.temp || defender->game.sell_mode == true)
        show_tower_hitbox(defender->window.window, defender->game.towers);
    while (tower) {
        if (tower->id_tower == 0)
            sfSprite_rotate(tower->sprite, 0.25);
        sfSprite_setTextureRect(tower->sprite, tower->rect_anim);
        sfRenderWindow_drawSprite(window, tower->sprite, NULL);
        tower = tower->next;
    }
}
