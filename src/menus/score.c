/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** score
*/

#include "defender.h"

void score_appears(defender_t *defender)
{
    defender->score.displayed = true;
    defender->main_menu.score_btn.hover = false;
    defender->main_menu.score_btn.pressed = false;
}

void score_disappears(defender_t *defender)
{
    defender->score.displayed = false;
    defender->score.btns[0].hover = false;
    defender->score.btns[0].pressed = false;
    sfSprite_setTexture(defender->score.btns[0].sprite, \
    defender->score.btns[0].texture_basic, sfTrue);
}

void set_sprite_for_score(my_mini_menu_t *score)
{
    score->btns[0] = init_button((sfVector2f[2]){{1240, 110}, {80, 80}}, \
    "assets/pictures/BTN/Close.png", "assets/pictures/BTN_Active/Close.png", \
    &score_disappears);
    score->texture = sfTexture_createFromFile("assets/pictures/Window.png", \
    NULL);
}

int init_score_menu(my_mini_menu_t *score)
{
    score->displayed = false;
    score->btns = malloc(sizeof(button_t) * 1);
    if (score->btns == NULL)
        return (-1);
    set_sprite_for_score(score);
    score->sprite = sfSprite_create();
    sfSprite_setTexture(score->sprite, score->texture, sfTrue);
    sfSprite_setPosition(score->sprite, (sfVector2f) {560, 80});
    return (0);
}

void draw_score(defender_t *defender)
{
    sfText *text_one = init_text((sfVector2f) {600, 400}, 45, \
    "Your last score\nduring this session :", TEXT_COLOR);
    sfText *text_two = init_text((sfVector2f) {70, 15}, 60, \
    change_int_into_str(defender->game.score), TEXT_COLOR);
    sfFloatRect rect = sfText_getLocalBounds(text_two);
    sfText_setPosition(text_two, \
    (sfVector2f) {960 - rect.width / 2, 600 - rect.height / 2});
    sfRenderWindow_drawSprite(defender->window.window, \
    defender->score.sprite, NULL);
    sfRenderWindow_drawText(defender->window.window, text_one, NULL);
    sfRenderWindow_drawText(defender->window.window, text_two, NULL);
    draw_button(defender->window.window, &(defender->score.btns[0]));
    sfText_destroy(text_two);
    sfText_destroy(text_one);
}