/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** game.c
*/

#include "defender.h"

void get_button(my_mini_menu_t *tower_menu)
{
    tower_menu->btns[0] = init_button((sfVector2f[2]){{610, 890}, {100, 100}}, \
    "assets/pictures/BTN/shoptype1.png", "assets/pictures/BTN/shoptype1.png", \
    &add_tower_one);
    tower_menu->btns[1] = init_button((sfVector2f[2]){{760, 890}, {100, 100}}, \
    "assets/pictures/BTN/shoptype2.png", "assets/pictures/BTN/shoptype2.png", \
    &add_tower_two);
    tower_menu->btns[2] = init_button((sfVector2f[2]){{910, 890}, {100, 100}}, \
    "assets/pictures/BTN/shoptype3.png", "assets/pictures/BTN/shoptype3.png", \
    add_tower_three);
    tower_menu->btns[3] = init_button((sfVector2f[2]){{1060, 890}, \
        {100, 100}}, "assets/pictures/BTN/minning_energy.png", \
    "assets/pictures/BTN/minning_energy.png", &add_tower_four);
    tower_menu->btns[4] = init_button((sfVector2f[2]){{1210, 890}, \
        {100, 100}}, "assets/pictures/BTN/selling_tower.png", \
    "assets/pictures/BTN/selling_tower.png", &active_sell_mode);
}

int set_towers_menu(my_mini_menu_t *tower_menu)
{
    tower_menu->displayed = true;
    tower_menu->area = (sfIntRect) {560, 850, 800, 200};
    tower_menu->texture = \
    sfTexture_createFromFile("assets/pictures/Window.png", NULL);
    tower_menu->sprite = sfSprite_create();
    sfSprite_setTexture(tower_menu->sprite, tower_menu->texture, sfTrue);
    sfSprite_setPosition(tower_menu->sprite, (sfVector2f) {560, 850});
    sfSprite_setScale(tower_menu->sprite, (sfVector2f) {1, 200.0 / 919.0});
    tower_menu->btns = malloc(sizeof(button_t) * 5);
    if (tower_menu->btns == NULL)
        return (-1);
    get_button(tower_menu);
    return (0);
}

void select_sprite_for_init(game_t *game)
{
    game->pause_btn = init_button((sfVector2f[2]){{10, 10}, {50, 50}},  \
    "assets/pictures/BTN/Pause.png", "assets/pictures/BTN_Active/Pause.png", \
    &make_pause);
    game->skills_btn = init_button((sfVector2f[2]){{1860, 10}, {50, 50}}, \
    "assets/pictures/BTN/Shop.png", "assets/pictures/BTN_Active/Shop.png", \
    &make_skills_appears);
}

int init_game_part(defender_t *defender, game_t *game)
{
    game->life_bonus = 0;
    game->atq_bonus = 1.0;
    game->text_energy = \
    sfTexture_createFromFile("./assets/pictures/energy.png", NULL);
    game->sprite_energy = sfSprite_create();
    sfSprite_setTexture(game->sprite_energy, game->text_energy, sfTrue);
    sfSprite_setPosition(game->sprite_energy, (sfVector2f) {1750, 20});
    defender->actual_time = sfClock_getElapsedTime(defender->clock);
    defender->last_time = defender->actual_time;
    select_sprite_for_init(game);
    set_towers_menu(&(game->tower_menu));
    set_pause_menu(&(game->pause_menu));
    init_skill_tree(&(game->skills_menu));
    init_round(&(game->round));
    game->coin = 60;
    make_changment_for_game(game);
    defender->loose = false;
    return (0);
}

void game_event_management(sfRenderWindow *window, sfEvent event, \
defender_t *defender)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed)
            detect_key(defender, event);
        if (event.type == sfEvtMouseMoved)
            check_game_menu_button_hover(defender, event.mouseMove.x, \
            event.mouseMove.y);
        if (event.type == sfEvtMouseButtonPressed)
            check_click(defender, event);
    }
}
