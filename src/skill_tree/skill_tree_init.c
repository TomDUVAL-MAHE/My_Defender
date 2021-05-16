/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** skill_tree_init.c
*/

#include "defender.h"

void make_skills_appears(defender_t *defender)
{
    defender->game.skills_menu.displayed = true;
    defender->game.tower_menu.displayed = false;
    defender->game.skills_btn.hover = false;
    defender->game.skills_btn.pressed = false;
}

void make_skills_disappears(defender_t *defender)
{
    defender->game.skills_menu.displayed = false;
    defender->game.tower_menu.displayed = true;
    defender->game.skills_menu.btns[10].hover = false;
    defender->game.skills_menu.btns[10].pressed = false;
}

void set_buttons_part_two(my_mini_menu_t *skills_tree)
{
    skills_tree->btns[6] = init_button((sfVector2f[2]){{600, 390}, \
        {100, 100}}, "assets/pictures/Skill_tree/II.png", \
    "assets/pictures/Skill_tree/II_p.png", &do_a_life_upgrade);
    skills_tree->btns[7] = init_button((sfVector2f[2]){{860, 390}, \
        {100, 100}}, "assets/pictures/Skill_tree/III.png", \
    "assets/pictures/Skill_tree/III_p.png", &do_a_life_upgrade);
    skills_tree->btns[8] = init_button((sfVector2f[2]){{1120, 390}, \
        {100, 100}}, "assets/pictures/Skill_tree/IV.png", \
    "assets/pictures/Skill_tree/IV_p.png", &do_a_life_upgrade);
    skills_tree->btns[9] = init_button((sfVector2f[2]){{1380, 390}, \
        {100, 100}}, "assets/pictures/Skill_tree/V.png", \
    "assets/pictures/Skill_tree/V_p.png", &do_a_life_upgrade);
    skills_tree->btns[10] = init_button((sfVector2f[2]){{1660, 120}, \
        {75, 75}}, "assets/pictures/BTN/Close.png", \
    "assets/pictures/BTN/Close.png", &make_skills_disappears);
}

void set_buttons_part_one(my_mini_menu_t *skills_tree)
{
    skills_tree->btns[0] = init_button((sfVector2f[2]){{340, 720}, \
        {100, 100}}, "assets/pictures/Skill_tree/I.png", \
    "assets/pictures/Skill_tree/I_p.png", &do_a_damage_upgrade);
    skills_tree->btns[1] = init_button((sfVector2f[2]){{600, 720}, \
        {100, 100}}, "assets/pictures/Skill_tree/II.png", \
    "assets/pictures/Skill_tree/II_p.png", &do_a_damage_upgrade);
    skills_tree->btns[2] = init_button((sfVector2f[2]){{860, 720}, \
        {100, 100}}, "assets/pictures/Skill_tree/III.png", \
    "assets/pictures/Skill_tree/III_p.png", &do_a_damage_upgrade);
    skills_tree->btns[3] = init_button((sfVector2f[2]){{1120, 720}, \
        {100, 100}}, "assets/pictures/Skill_tree/IV.png", \
    "assets/pictures/Skill_tree/IV_p.png", &do_a_damage_upgrade);
    skills_tree->btns[4] = init_button((sfVector2f[2]){{1380, 720}, \
        {100, 100}}, "assets/pictures/Skill_tree/V.png", \
    "assets/pictures/Skill_tree/V_p.png", &do_a_damage_upgrade);
    skills_tree->btns[5] = init_button((sfVector2f[2]){{340, 390}, \
        {100, 100}}, "assets/pictures/Skill_tree/I.png", \
    "assets/pictures/Skill_tree/I_p.png", &do_a_life_upgrade);
    set_buttons_part_two(skills_tree);
}

int init_skill_tree(my_mini_menu_t *skills_tree)
{
    skills_tree->displayed = false;
    skills_tree->area = (sfIntRect) {100, 100, 1720, 980};
    skills_tree->texture = \
    sfTexture_createFromFile("assets/pictures/Skill_tree/Skill_Window.png", \
    NULL);
    skills_tree->sprite = sfSprite_create();
    sfSprite_setTexture(skills_tree->sprite, skills_tree->texture, sfTrue);
    sfSprite_setPosition(skills_tree->sprite, (sfVector2f) {100, 100});
    skills_tree->btns = malloc(sizeof(button_t) * 11);
    if (skills_tree->btns == NULL)
        return (-1);
    set_buttons_part_one(skills_tree);
    return (0);
}
