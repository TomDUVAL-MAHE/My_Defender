/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** sell_tower
*/

#include "defender.h"

void active_sell_mode(defender_t *defender)
{
    defender->game.sell_mode = true;
    defender->game.tower_menu.displayed = false;
}

void desactive_sell_mode(defender_t *defender)
{
    defender->game.sell_mode = false;
    defender->game.tower_menu.displayed = true;
}

tower_t *which_tower(tower_t *towers, int x, int y)
{
    while (towers) {
        if (sfFloatRect_contains(&(towers->hitbox), x, y) == sfTrue)
            return (towers);
        towers = towers->next;
    }
    return (NULL);
}

void sell_tower(defender_t *defender, sfEvent event)
{
    tower_t *tower = which_tower(defender->game.towers, \
    event.mouseButton.x, event.mouseButton.y);

    if (tower == NULL || tower->id_tower == 0)
        return;
    if (defender->sound == true) {
        sfMusic_stop(defender->sounds.sound_selling);
        sfMusic_play(defender->sounds.sound_selling);
    }
    defender->game.coin += tower->cost * tower->life / 100 / 2;
    sfText_setString(defender->game.text_coin, \
    change_int_into_str(defender->game.coin));
    destroy_only_one_tower(&(defender->game), tower);
}
