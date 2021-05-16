/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** defender_struct.c
*/

#include "defender.h"

int init_defender_struct(defender_t *defender)
{
    defender->clock = sfClock_create();
    window_init(&(defender->window), (sfVector2f){1920, 1080});
    init_settings_menu(&(defender->settings));
    init_main_menu(&(defender->main_menu));
    init_help_menu(&(defender->help));
    init_score_menu(&(defender->score));
    create_music(&(defender->sounds));
    make_sound_on(defender);
    make_music_on(defender);
    defender->scene_id = MAIN_MENU_ID;
    defender->elapsed_microsecond = 0;
    defender->last_score = 0;
    defender->loose = false;
    return (0);
}
