/*
** EPITECH PROJECT, 2021
** destroy
** File description:
** for my_defender
*/

#include "defender.h"

void destroy_button(button_t button)
{
    sfSprite_destroy(button.sprite);
    sfTexture_destroy(button.texture_basic);
    sfTexture_destroy(button.texture_pressed);
}

void destroy_mini_menu(my_mini_menu_t settings, int nb)
{
    sfSprite_destroy(settings.sprite);
    sfTexture_destroy(settings.texture);
    for (int i = 0; i < nb; i++)
        destroy_button(settings.btns[i]);
    free(settings.btns);
}

void destroy_main_menu(main_menu_t main_menu)
{
    destroy_button(main_menu.start_btn);
    destroy_button(main_menu.exit_btn);
    destroy_button(main_menu.score_btn);
    destroy_button(main_menu.tutorial_btn);
    destroy_button(main_menu.settings_btn);
    sfText_destroy(main_menu.title);
}

void destroy_sounds(music_t sounds)
{
    sfMusic_destroy(sounds.sound_background);
    sfMusic_destroy(sounds.sound_posing);
    sfMusic_destroy(sounds.sound_selling);
}

void destroy_defender(defender_t *defender)
{
    sfClock_destroy(defender->clock);
    sfClock_destroy(defender->window.clock);
    destroy_background(defender->window.background);
    destroy_mini_menu(defender->settings, 5);
    destroy_main_menu(defender->main_menu);
    destroy_sounds(defender->sounds);
}
