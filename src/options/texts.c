/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** texts.c
*/

#include "defender.h"

void draw_coin(sfRenderWindow *window, sfText *text)
{
    sfFloatRect rect = sfText_getLocalBounds(text);
    sfText_setPosition(text, \
    (sfVector2f) {1740 - rect.width, 10});
    sfRenderWindow_drawText(window, text, NULL);
}

int nbr_len(int nbr)
{
    int i = 0;

    if (nbr < 0) {
        nbr *= -1;
    }
    while (nbr > 9) {
        nbr /= 10;
        i++;
    }
    return (i);
}

char *change_int_into_str(int nbr)
{
    int len = nbr_len(nbr);
    char *number = malloc(sizeof(char) * (len + 1));
    int i = 0;

    while (i <= len) {
        number[len - i] = nbr % 10 + '0';
        nbr /= 10;
        i++;
    }
    number[len + 1] = '\0';
    return (number);
}

sfText *init_text(sfVector2f pos, unsigned int size, char *str, sfColor color)
{
    sfText *text;
    sfFont *font;

    font = sfFont_createFromFile("assets/fonts/ethnocentric.ttf");
    text = sfText_create();
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setString(text, str);
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, color);
    sfText_setOutlineThickness(text, 4.0);
    sfText_setOutlineColor(text, sfColor_fromRGB(72, 118, 197));
    return (text);
}
