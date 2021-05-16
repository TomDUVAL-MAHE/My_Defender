/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** button.c
*/

#include "defender.h"

button_t init_button(sfVector2f vectors[2], char *path_basic, \
char *path_pressed, void (*call_back)(defender_t *defender))
{
    button_t button;
    sfVector2u texture_size;

    button.pressed = false;
    button.hover = false;
    button.rect.left = vectors[0].x;
    button.rect.top = vectors[0].y;
    button.rect.width = vectors[1].x;
    button.rect.height = vectors[1].y;
    button.texture_basic = sfTexture_createFromFile(path_basic, NULL);
    button.texture_pressed = sfTexture_createFromFile(path_pressed, NULL);
    button.sprite = sfSprite_create();
    texture_size = sfTexture_getSize(button.texture_basic);
    sfSprite_setTexture(button.sprite, button.texture_basic, sfTrue);
    sfSprite_setPosition(button.sprite, vectors[0]);
    sfSprite_setScale(button.sprite, (sfVector2f) {vectors[1].x / \
        texture_size.x, vectors[1].y / texture_size.y});
    button.call_back = call_back;
    return (button);
}

bool button_is_hover(button_t *button, int mouse_x, int mouse_y)
{
    if (sfIntRect_contains(&(button->rect), mouse_x, mouse_y)) {
        button->hover = true;
        return (true);
    } else {
        button->hover = false;
        return (false);
    }
}

bool button_is_clicked(button_t *button, defender_t *defender)
{
    if (button->hover == true) {
        button->pressed = true;
        button->time = sfClock_getElapsedTime(defender->clock);
        sfSprite_setTexture(button->sprite, button->texture_pressed, sfTrue);
        if (button->call_back != NULL)
            button->call_back(defender);
        return (true);
    } else {
        return (false);
    }
}

void one_button_manager(button_t *button, sfTime time)
{
    if (button->time.microseconds + 100000 <= time.microseconds) {
        button->pressed = false;
        sfSprite_setTexture(button->sprite, button->texture_basic, sfTrue);
    }
}

void draw_button(sfRenderWindow *window, button_t *button)
{
    sfRectangleShape *rect;

    sfRenderWindow_drawSprite(window, button->sprite, NULL);
    if (button->hover == true) {
        rect = sfRectangleShape_create();
        sfRectangleShape_setFillColor(rect, \
        sfColor_fromRGBA(255, 255, 255, 50));
        sfRectangleShape_setPosition(rect, \
        (sfVector2f) {button->rect.left, button->rect.top});
        sfRectangleShape_setSize(rect, \
        (sfVector2f) {button->rect.width, button->rect.height});
        sfRenderWindow_drawRectangleShape(window, rect, NULL);
        sfRectangleShape_destroy(rect);
    }
}
