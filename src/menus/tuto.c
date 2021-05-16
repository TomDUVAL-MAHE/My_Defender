/*
** EPITECH PROJECT, 2021
** tuto.c
** File description:
** for my_defender.c
*/

#include "defender.h"

void help_appears(defender_t *defender)
{
    defender->help.displayed = true;
    defender->main_menu.tutorial_btn.hover = false;
    defender->main_menu.tutorial_btn.pressed = false;
}

void help_disappears(defender_t *defender)
{
    defender->help.displayed = false;
    defender->help.btns[0].hover = false;
    defender->help.btns[0].pressed = false;
}

void set_sprite_for_help(my_mini_menu_t *help)
{
    help->btns[0] = init_button((sfVector2f[2]){{1660, 120}, {75, 75}}, \
    "assets/pictures/BTN/Close.png", "assets/pictures/BTN_Active/Close.png", \
    &help_disappears);
    help->texture = sfTexture_createFromFile("assets/How_To_play.png", NULL);
}

int init_help_menu(my_mini_menu_t *help)
{
    help->displayed = false;
    help->btns = malloc(sizeof(button_t) * 1);
    if (help->btns == NULL)
        return (-1);
    set_sprite_for_help(help);
    help->sprite = sfSprite_create();
    sfSprite_setTexture(help->sprite, help->texture, sfTrue);
    sfSprite_setPosition(help->sprite, (sfVector2f) {100, 100});
    return (0);
}

void draw_help(defender_t *defender)
{
    sfRenderWindow_drawSprite(defender->window.window, \
    defender->help.sprite, NULL);
    draw_button(defender->window.window, &(defender->help.btns[0]));
}
