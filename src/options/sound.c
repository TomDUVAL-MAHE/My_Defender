/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** sound.c
*/

#include "defender.h"

void make_sound_on(defender_t *defender)
{
    defender->sound = true;
    defender->settings.btns[0].pressed = true;
    sfSprite_setTexture(defender->settings.btns[0].sprite, \
    defender->settings.btns[0].texture_pressed, sfTrue);
    defender->settings.btns[1].pressed = false;
    sfSprite_setTexture(defender->settings.btns[1].sprite, \
    defender->settings.btns[1].texture_basic, sfTrue);
}

void make_sound_off(defender_t *defender)
{
    defender->sound = false;
    defender->settings.btns[0].pressed = false;
    sfSprite_setTexture(defender->settings.btns[0].sprite, \
    defender->settings.btns[0].texture_basic, sfTrue);
    defender->settings.btns[1].pressed = true;
    sfSprite_setTexture(defender->settings.btns[1].sprite, \
    defender->settings.btns[1].texture_pressed, sfTrue);
}
