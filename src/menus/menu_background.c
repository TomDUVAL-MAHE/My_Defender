/*
** EPITECH PROJECT, 2021
** background for menu
** File description:
** for my_defender
*/
#include "defender.h"

void background_drawing(sfRenderWindow *window, my_background_t *background)
{
    sfClock *count = 0;

    for (int i = 0; i != 4; i++) {
        count = background[i].clock;
        if (background[i].rect.left >= 1920)
            background[i].rect.left = 0;
        background[i].rect.left = background[i].rect.left + i;
        sfSprite_setTextureRect(background[i].sprite, background[i].rect);
        if (count <= background[i].clock)
            sfRenderWindow_drawSprite(window, background[i].sprite, NULL);
    }
}

void fill_background(my_background_t *background)
{
    for (int i = 0; i < 4; i++) {
        background[i].sprite = sfSprite_create();
        background[i].rect.left = 0;
        background[i].rect.top = 0;
        background[i].rect.width = 1920;
        background[i].rect.height = 1080;
        background[i].clock = sfClock_create();
    }
}

my_background_t *background_create(void)
{
    my_background_t *background;

    background = malloc(sizeof(my_background_t) * 4);
    if (!background)
        return (NULL);
    fill_background(background);
    background[3].texture = \
    sfTexture_createFromFile("assets/pictures/Stars_Small_1.png", NULL);
    background[2].texture = \
    sfTexture_createFromFile("assets/pictures/Stars_Big_1_1_PC.png", NULL);
    background[1].texture = \
    sfTexture_createFromFile("assets/pictures/fond3.png", NULL);
    background[0].texture = \
    sfTexture_createFromFile("assets/pictures/fond3.png", NULL);
    for (int i = 0; i < 4; i++)
        sfSprite_setTexture(background[i].sprite, \
        background[i].texture, sfTrue);
    return (background);
}
