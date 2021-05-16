/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** settings_menu.c
*/

#include "defender.h"

void set_sprite_setting_menu(my_mini_menu_t *settings)
{
    settings->btns[0] = init_button((sfVector2f[2]){{835, 440}, {100, 100}}, \
    "assets/pictures/BTN/Sound.png", \
    "assets/pictures/BTN_Active/Sound.png", &make_sound_on);
    settings->btns[1] = init_button((sfVector2f[2]){{1035, 440}, {100, 100}}, \
    "assets/pictures/BTN/no_Sound.png", \
    "assets/pictures/BTN_Active/no_Sound.png", &make_sound_off);
    settings->btns[2] = init_button((sfVector2f[2]){{835, 640}, {100, 100}}, \
    "assets/pictures/BTN/Music.png", "assets/pictures/BTN_Active/Music.png", \
    &make_music_on);
    settings->btns[3] = init_button((sfVector2f[2]){{1035, 640}, \
        {100, 100}}, "assets/pictures/BTN/no_Music.png", \
    "assets/pictures/BTN_Active/no_Music.png", &make_music_off);
    settings->btns[4] = init_button((sfVector2f[2]){{1240, 110}, {80, 80}}, \
    "assets/pictures/BTN/Close.png", "assets/pictures/BTN_Active/Close.png", \
    &make_settings_disappears);
    settings->texture = sfTexture_createFromFile("assets/pictures/Window.png", \
    NULL);
}

int init_settings_menu(my_mini_menu_t *settings)
{
    settings->displayed = false;
    settings->btns = malloc(sizeof(button_t) * 5);
    if (settings->btns == NULL)
        return (-1);
    set_sprite_setting_menu(settings);
    settings->sprite = sfSprite_create();
    sfSprite_setTexture(settings->sprite, settings->texture, sfTrue);
    sfSprite_setPosition(settings->sprite, (sfVector2f){560, 80});
    sfSprite_setScale(settings->sprite, (sfVector2f){1, 1});
    return (0);
}

void draw_settings_menu(defender_t *defender)
{
    sfRenderWindow_drawSprite(defender->window.window, \
    defender->settings.sprite, NULL);
    for (int i = 0; i < 5; i++)
        draw_button(defender->window.window, &(defender->settings.btns[i]));
}

void make_settings_appears(defender_t *defender)
{
    defender->settings.displayed = true;
    if (defender->scene_id == MAIN_MENU_ID) {
        defender->main_menu.settings_btn.hover = false;
        defender->main_menu.settings_btn.pressed = false;
        return;
    }
    if (defender->scene_id == GAME_ID) {
        defender->game.pause_menu.btns[1].hover = false;
        defender->game.pause_menu.btns[1].pressed = false;
    }
}

void make_settings_disappears(defender_t *defender)
{
    defender->settings.displayed = false;
    defender->settings.btns[4].hover = false;
    defender->settings.btns[4].pressed = false;
}
