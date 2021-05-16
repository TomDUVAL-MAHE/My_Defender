/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** music.c
*/

#include "defender.h"

void make_music_on(defender_t *defender)
{
    defender->music = true;
    defender->settings.btns[2].pressed = true;
    sfSprite_setTexture(defender->settings.btns[2].sprite, \
    defender->settings.btns[2].texture_pressed, sfTrue);
    defender->settings.btns[3].pressed = false;
    sfSprite_setTexture(defender->settings.btns[3].sprite, \
    defender->settings.btns[3].texture_basic, sfTrue);
    sfMusic_play(defender->sounds.sound_background);
}

void make_music_off(defender_t *defender)
{
    defender->music = false;
    defender->settings.btns[2].pressed = false;
    sfSprite_setTexture(defender->settings.btns[2].sprite, \
    defender->settings.btns[2].texture_basic, sfTrue);
    defender->settings.btns[3].pressed = true;
    sfSprite_setTexture(defender->settings.btns[3].sprite, \
    defender->settings.btns[3].texture_pressed, sfTrue);
    sfMusic_stop(defender->sounds.sound_background);
}
