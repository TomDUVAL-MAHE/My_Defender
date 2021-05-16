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
    sfMusic_createFromFile("assets/sounds/Music_war_space.ogg");
    sfMusic_setLoop(sounds->sound_background, sfTrue);
    sounds->sound_posing = sfMusic_createFromFile("assets/sounds/pos.ogg");
    sounds->sound_selling = sfMusic_createFromFile("assets/sounds/sell.ogg");
}

void destroy_music(music_t *sounds)
{
    sfMusic_destroy(sounds->sound_background);
    sfMusic_destroy(sounds->sound_posing);
    sfMusic_destroy(sounds->sound_selling);
}
