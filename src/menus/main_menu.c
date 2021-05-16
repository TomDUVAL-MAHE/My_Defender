/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** main_menu.c
*/

#include "defender.h"

int init_main_menu(main_menu_t *menu)
{
    sfFloatRect rect;

    menu->displayed = false;
    set_sprite(menu);
    rect = sfText_getLocalBounds(menu->title);
    sfText_setPosition(menu->title, (sfVector2f){1920 / 2 - rect.width / 2 - \
        rect.left / 2, 150});
    return (0);
}

void check_main_menu_button_hover(defender_t *defender, int mouse_x, \
int mouse_y)
{
    if (defender->settings.displayed == false \
    && defender->help.displayed == false) {
        button_is_hover(&defender->main_menu.start_btn, mouse_x, mouse_y);
        button_is_hover(&defender->main_menu.exit_btn, mouse_x, mouse_y);
        button_is_hover(&defender->main_menu.score_btn, mouse_x, mouse_y);
        button_is_hover(&defender->main_menu.settings_btn, mouse_x, mouse_y);
        button_is_hover(&defender->main_menu.tutorial_btn, mouse_x, mouse_y);
    }
    if (defender->help.displayed == true)
        button_is_hover(&defender->help.btns[0], mouse_x, mouse_y);
    if (defender->score.displayed == true)
        button_is_hover(&defender->score.btns[0], mouse_x, mouse_y);
    if (defender->settings.displayed == true)
        for (int i = 0; i < 5; i++)
            button_is_hover(&defender->settings.btns[i], mouse_x, mouse_y);
}

void check_main_menu_button_pressed(defender_t *defender)
{
    if (defender->settings.displayed == false \
    && defender->help.displayed == false \
    && defender->score.displayed == false) {
        button_is_clicked(&defender->main_menu.start_btn, defender);
        button_is_clicked(&defender->main_menu.exit_btn, defender);
        button_is_clicked(&defender->main_menu.score_btn, defender);
        button_is_clicked(&defender->main_menu.settings_btn, defender);
        button_is_clicked(&defender->main_menu.tutorial_btn, defender);
    }
    if (defender->help.displayed == true)
        button_is_clicked(&defender->help.btns[0], defender);
    if (defender->score.displayed == true)
        button_is_clicked(&defender->score.btns[0], defender);
    if (defender->settings.displayed == true)
        for (int i = 0; i < 5; i++)
            button_is_clicked(&defender->settings.btns[i], defender);
}

void menu_event_management(sfRenderWindow *window, sfEvent event, \
defender_t *defender)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            detect_key(defender, event);
        if (event.type == sfEvtMouseMoved)
            check_main_menu_button_hover(defender, event.mouseMove.x, \
            event.mouseMove.y);
        if (event.type == sfEvtMouseButtonPressed) {
            check_main_menu_button_pressed(defender);
        }
    }
}

void main_menu_button_manager(defender_t *defender, main_menu_t *menu, \
sfClock *clock)
{
    sfTime time = sfClock_getElapsedTime(clock);

    if (defender->settings.displayed == false \
    && defender->help.displayed == false) {
        one_button_manager(&menu->start_btn, time);
        one_button_manager(&menu->exit_btn, time);
        one_button_manager(&menu->score_btn, time);
        one_button_manager(&menu->settings_btn, time);
        one_button_manager(&menu->tutorial_btn, time);
    } else {
        if (defender->settings.displayed == true)
            one_button_manager(&defender->settings.btns[4], time);
        if (defender->help.displayed == true)
            one_button_manager(&defender->help.btns[0], time);
    }
}
