/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** skill_tree_draw.c
*/

#include "defender.h"

void draw_skill_tree(defender_t *defender)
{
    sfRenderWindow_drawSprite(defender->window.window, \
    defender->game.skills_menu.sprite, NULL);
    for (int i = 0; i < 11; i++) {
        draw_button(defender->window.window, \
        &(defender->game.skills_menu.btns[i]));
    }
}
