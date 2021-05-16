/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** pause.c
*/

#include "defender.h"

void make_pause(defender_t *defender)
{
    defender->game.pause_menu.displayed = true;
    defender->game.tower_menu.displayed = false;
    defender->game.pause_menu.btns[0].hover = false;
    defender->game.pause_menu.btns[0].pressed = false;
    defender->elapsed_microsecond = 0;
    return;
}

void make_pause_menu_disappears(defender_t *defender)
{
    defender->game.pause_menu.displayed = false;

    defender->game.tower_menu.displayed = true;
    defender->game.pause_btn.hover = false;
    defender->game.pause_btn.pressed = false;
    defender->actual_time = sfClock_getElapsedTime(defender->clock);
    get_time(defender);
    return;
}

void draw_pause_menu(defender_t *defender)
{
    sfRenderWindow_drawSprite(defender->window.window, \
    defender->game.pause_menu.sprite, NULL);
    for (int i = 0; i < 4; i++)
        draw_button(defender->window.window, \
        &(defender->game.pause_menu.btns[i]));
}

void select_sprite_for_pause(my_mini_menu_t *pause_menu)
{
    pause_menu->btns[0] = init_button((sfVector2f[2]){{760, 315}, {400, 100}}, \
    "assets/pictures/BTN/Resume.png", "assets/pictures/BTN/Resume.png", \
    &make_pause_menu_disappears);
    pause_menu->btns[1] = init_button((sfVector2f[2]){{760, 465}, {400, 100}}, \
    "assets/pictures/BTN/Options.png", "assets/pictures/BTN/Options.png", \
    &make_settings_appears);
    pause_menu->btns[2] = init_button((sfVector2f[2]){{760, 615}, {400, 100}}, \
    "assets/pictures/BTN/Menu.png", "assets/pictures/BTN/Menu.png", \
    &return_to_main_menu);
    pause_menu->btns[3] = init_button((sfVector2f[2]){{760, 765}, {400, 100}}, \
    "assets/pictures/BTN/Quit.png", "assets/pictures/BTN/Quit.png", \
    &make_close_window);
    pause_menu->texture = \
    sfTexture_createFromFile("assets/pictures/Window.png", NULL);
}

int set_pause_menu(my_mini_menu_t *pause_menu)
{
    pause_menu->displayed = false;
    pause_menu->btns = malloc(sizeof(button_t) * 4);
    if (pause_menu->btns == NULL)
        return (-1);
    select_sprite_for_pause(pause_menu);
    pause_menu->sprite = sfSprite_create();
    sfSprite_setTexture(pause_menu->sprite, pause_menu->texture, sfTrue);
    sfSprite_setPosition(pause_menu->sprite, (sfVector2f){560, 80});
    sfSprite_setScale(pause_menu->sprite, (sfVector2f){1, 1});
    return (0);
}
