/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** game_menu.c
*/

#include "defender.h"

void check_game_menu_button_hover(defender_t *defender, int mouse_x, \
int mouse_y)
{
    if (defender->game.tower_menu.displayed == true) {
        button_is_hover(&defender->game.pause_btn, mouse_x, mouse_y);
        button_is_hover(&defender->game.skills_btn, mouse_x, mouse_y);
        for (int i = 0; i < 5; i++)
            button_is_hover(&defender->game.tower_menu.btns[i], \
            mouse_x, mouse_y);
    }
    if (defender->game.pause_menu.displayed == true && \
        defender->settings.displayed == false)
        for (int i = 0; i < 4; i++)
            button_is_hover(&defender->game.pause_menu.btns[i], \
            mouse_x, mouse_y);
    if (defender->settings.displayed == true)
        for (int i = 0; i < 5; i++)
            button_is_hover(&defender->settings.btns[i], mouse_x, mouse_y);
    if (defender->game.skills_menu.displayed == true)
        for (int i = 0; i < 11; i++)
            check_skill_tree_button_hover(&defender->game.skills_menu.btns[i], \
            mouse_x, mouse_y);
}

void check_game_menu_button_pressed(defender_t *defender)
{
    if (defender->game.tower_menu.displayed == true) {
        button_is_clicked(&defender->game.pause_btn, defender);
        button_is_clicked(&defender->game.skills_btn, defender);
        for (int i = 0; i < 5; i++)
            button_is_clicked(&defender->game.tower_menu.btns[i], defender);
    }
    if (defender->game.pause_menu.displayed == true && \
        defender->settings.displayed == false)
        for (int i = 0; i < 4; i++)
            button_is_clicked(&defender->game.pause_menu.btns[i], defender);
    if (defender->settings.displayed == true)
        for (int i = 0; i < 5; i++)
            button_is_clicked(&defender->settings.btns[i], defender);
    if (defender->game.skills_menu.displayed == true)
        check_skill_tree_buton_pressed(defender);
}

void draw_tower_menu(sfRenderWindow *window, my_mini_menu_t *menu)
{
    sfRenderWindow_drawSprite(window, menu->sprite, NULL);
    for (int i = 0; i < 5; i++)
        draw_button(window, &(menu->btns[i]));
}

void game_menu_button_manager(defender_t *defender, game_t *game_scene, \
sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);

    if (defender->settings.displayed == false) {
        one_button_manager(&game_scene->pause_btn, time);
        one_button_manager(&game_scene->skills_btn, time);
    }
}

void draw_game_menu(sfRenderWindow *window, game_t *game_scene, \
defender_t *defender)
{
    if (defender->game.skills_menu.displayed == true)
        draw_skill_tree(defender);
    if (game_scene->tower_menu.displayed == true) {
        game_menu_button_manager(defender, &(defender->game), defender->clock);
        draw_button(window, &(game_scene->pause_btn));
        draw_button(window, &(game_scene->skills_btn));
        draw_tower_menu(defender->window.window, &(game_scene->tower_menu));
    }
    if (defender->game.pause_menu.displayed == true)
        draw_pause_menu(defender);
    if (defender->settings.displayed == true)
        draw_settings_menu(defender);
}
