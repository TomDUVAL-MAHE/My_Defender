/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** event.c
*/

#include "defender.h"

void detect_key(defender_t *defender, sfEvent event)
{
    if (event.key.code == sfKeyEscape)
        if (defender->scene_id == GAME_ID)
            make_pause(defender);
}

void event_management(defender_t *defender, sfRenderWindow *window, \
sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            detect_key(defender, event);
    }
}

void create_a_tower_if_posible(defender_t *defender, sfEvent event)
{
    tower_t *tower = defender->game.towers;
    tower_t *temp = defender->game.temp;

    if (defender->game.coin < temp->cost)
        return;
    while (tower) {
        if (sfFloatRect_intersects(&(tower->hitbox), &(temp->hitbox), NULL)\
            == sfTrue)
            return;
        tower = tower->next;
    }
    if (defender->sound == true) {
        sfMusic_stop(defender->sounds.sound_posing);
        sfMusic_play(defender->sounds.sound_posing);
    }
    defender->game.coin -= temp->cost;
    set_new_text(&(defender->game));
    tower_create(defender, &(defender->game.towers), \
    defender->game.temp->id_tower, \
    (sfVector2f) {event.mouseButton.x -defender->game.temp->hitbox.width / 2, \
        event.mouseButton.y - defender->game.temp->hitbox.height / 2});
}

void check_click(defender_t *defender, sfEvent event)
{
    if (defender->game.sell_mode == true) {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue)
            sell_tower(defender, event);
        button_is_hover(&(defender->game.tower_menu.btns[4]), \
        event.mouseButton.x, event.mouseButton.y);
        desactive_sell_mode(defender);
        return;
    }
    if (defender->game.temp == NULL) {
        check_game_menu_button_pressed(defender);
    } else {
        if (sfMouse_isButtonPressed(sfMouseLeft) == sfTrue) {
            create_a_tower_if_posible(defender, event);
        }
        for (int i = 0; i < 3; i++)
            button_is_hover(&(defender->game.tower_menu.btns[i]), \
            event.mouseButton.x, event.mouseButton.y);
        defender->game.tower_menu.displayed = true;
        destroy_all_towers(&(defender->game.temp));
    }
}
