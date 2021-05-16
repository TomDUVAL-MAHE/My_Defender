/*
** EPITECH PROJECT, 2021
** init main
** File description:
** for my_defender
*/

#include "defender.h"

void set_sprite(main_menu_t *menu)
{
    menu->start_btn = init_button((sfVector2f[2]){{760, 550}, {400, 118}}, \
    "assets/pictures/BTN/Start.png", "assets/pictures/BTN/Start.png", \
    &make_game_start);
    menu->exit_btn = init_button((sfVector2f[2]){{760, 790}, {400, 118}}, \
    "assets/pictures/BTN/Exit.png", "assets/pictures/BTN/Exit.png", \
    &make_close_window);
    menu->score_btn = init_button((sfVector2f[2]){{780, 680}, {100, 100}}, \
    "assets/pictures/BTN/Score.png", "assets/pictures/BTN_Active/Score.png", \
    &score_appears);
    menu->settings_btn = init_button((sfVector2f[2]){{910, 680}, {100, 100}}, \
    "assets/pictures/BTN/Settings.png", \
    "assets/pictures/BTN_Active/Settings.png", &make_settings_appears);
    menu->tutorial_btn = init_button((sfVector2f[2]){{1040, 680}, {100, 100}}, \
    "assets/pictures/BTN/Tutorial.png", \
    "assets/pictures/BTN_Active/Tutorial.png", &help_appears);
    menu->title = init_text((sfVector2f){600, 150}, 200, "ECLYPSE", TEXT_COLOR);
}
