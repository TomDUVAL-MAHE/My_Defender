/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** main_menu_draw.c
*/

#include "defender.h"

void draw_main_menu(sfRenderWindow *window, main_menu_t *menu, \
defender_t *defender)
{
    sfRenderWindow_drawText(window, menu->title, NULL);
    draw_button(window, &(menu->start_btn));
    draw_button(window, &(menu->exit_btn));
    draw_button(window, &(menu->score_btn));
    draw_button(window, &(menu->settings_btn));
    draw_button(window, &(menu->tutorial_btn));
    if (defender->settings.displayed == true){
        draw_settings_menu(defender);
    }
    if (defender->help.displayed == true){
        draw_help(defender);
    }
    if (defender->score.displayed == true){
        draw_score(defender);
    }
}
