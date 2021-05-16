/*
** EPITECH PROJECT, 2021
** function for manag music
** File description:
** for my_defender
*/

#include "defender.h"

void create_music(music_t *sounds)
{
    sounds->sound_background = \
    sfMusic_createFromFile("assets/Celestial.ogg");
    sfMusic_setLoop(sounds->sound_background, sfTrue);
}

void destroy_music(music_t *sounds)
{
    sfMusic_destroy(sounds->sound_background);
}
