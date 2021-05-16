/*
** EPITECH PROJECT, 2021
** tool function for skill tree
** File description:
** for my_defender
*/

#include "defender.h"

void do_a_damage_upgrade(defender_t *defender)
{
    int i = 0;
    int cost = 200;

    while (defender->game.skills_menu.btns[i].pressed && i <= 4) {
        i++;
    }
    if (i == 0)
        return;
    cost = cost * pow(2, i);
    if (defender->game.coin < cost) {
        defender->game.skills_menu.btns[i - 1].pressed = false;
        sfSprite_setTexture(defender->game.skills_menu.btns[i - 1].sprite, \
        defender->game.skills_menu.btns[i - 1].texture_basic, sfTrue);
        return;
    }
    defender->game.coin -= cost;
    set_new_text(&(defender->game));
    upgrade_attack_of_tower(defender, 0.30);
}

void do_a_life_upgrade(defender_t *defender)
{
    int i = 5;
    int cost = 200;

    while (defender->game.skills_menu.btns[i].pressed && i <= 9) {
        i++;
    }
    if (i == 4)
        return;
    cost = cost * pow(2, i - 5);
    if (defender->game.coin < cost) {
        defender->game.skills_menu.btns[i - 1].pressed = false;
        sfSprite_setTexture(defender->game.skills_menu.btns[i - 1].sprite, \
        defender->game.skills_menu.btns[i - 1].texture_basic, sfTrue);
        return;
    }
    defender->game.coin -= cost;
    set_new_text(&(defender->game));
    upgrade_life_of_tower(defender, 50);
}

void check_skill_tree_button_hover(button_t *button, int mouse_x, int mouse_y)
{
    for (int i = 0; i < 10; i++) {
        if (button[i].pressed == false) {
            button_is_hover(&(button[i]), mouse_x, mouse_y);
        } else {
            button[i].hover = false;
        }
    }
    button_is_hover(&(button[10]), mouse_x, mouse_y);
}

void check_grouped_skill_button(defender_t *defender, int first, int last)
{
    button_t *button = defender->game.skills_menu.btns;

    for (int i = first; i <= last; i++) {
        if (i == first && button_is_clicked(&(button[i]), defender) == true) {
            return;
        }
        if (i > first && button[i - 1].pressed == true) {
            button_is_clicked(&(button[i]), defender);
        }
    }
}

void check_skill_tree_buton_pressed(defender_t *defender)
{
    check_grouped_skill_button(defender, 0, 4);
    check_grouped_skill_button(defender, 5, 9);
    button_is_clicked(&(defender->game.skills_menu.btns[10]), defender);
}
