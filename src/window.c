/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** window.c
*/

#include "defender.h"

void window_init(my_window_t *window, sfVector2f window_size)
{
    sfVideoMode mode = {window_size.x, window_size.y, 32};

    window->mode = mode;
    window->window = \
    sfRenderWindow_create(mode, "window", sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window->window, 60);
    window->background = background_create();
    window->clock = sfClock_create();
}

void make_close_window(defender_t *defender)
{
    sfRenderWindow_close(defender->window.window);
    defender->scene_id = -1;
}
