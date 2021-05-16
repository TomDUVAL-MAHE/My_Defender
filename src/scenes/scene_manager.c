/*
** EPITECH PROJECT, 2021
** Defender
** File description:
** scene_display.c
*/

#include "defender.h"
#include "enemies.h"

int main_menu_display(defender_t *defender)
{
    while (sfRenderWindow_isOpen(defender->window.window) && \
    defender->scene_id == MAIN_MENU_ID) {
        menu_event_management(defender->window.window, defender->window.event, \
        defender);
        sfRenderWindow_clear(defender->window.window, sfBlack);
        background_drawing(defender->window.window, \
        defender->window.background);
        main_menu_button_manager(defender, &(defender->main_menu), \
        defender->clock);
        draw_main_menu(defender->window.window, &(defender->main_menu), \
        defender);
        sfRenderWindow_display(defender->window.window);
    }
    return (0);
}

void drawing_all_sprite(defender_t *defender)
{
    background_drawing(defender->window.window, defender->window.background);
    draw_projectiles(defender->window.window, defender, \
    defender->game.projectiles);
    draw_enemies(defender->window.window, defender, defender->game.enemies);
    tower_display(defender->window.window, defender, defender->game.towers);
    temp_display(defender->window.window, &(defender->game));
    sfRenderWindow_drawSprite(defender->window.window, \
    defender->game.sprite_energy, NULL);
    draw_game_menu(defender->window.window, &(defender->game), defender);
    sfRenderWindow_drawText(defender->window.window, \
    defender->game.text_score, NULL);
    draw_coin(defender->window.window, defender->game.text_coin);
    sfRenderWindow_display(defender->window.window);
}

void game_manager(defender_t *defender)
{
    get_time(defender);
    enemy_spawn_manager(defender);
    tower_managment(defender, defender->game.towers, \
    defender->game.enemies);
    move_ennemies(defender, defender->game.enemies);
    move_projectiles(defender, defender->game.projectiles);
}

int game_display(defender_t *defender)
{
    init_game_part(defender, &(defender->game));
    tower_create(defender, &(defender->game.towers), 0, \
    (sfVector2f){869, 449});
    defender->game.text_score = init_text((sfVector2f) {200, 15}, 50, \
    change_int_into_str(defender->game.score), TEXT_COLOR);
    defender->game.text_coin = init_text((sfVector2f) {1550, 15}, 50, \
    change_int_into_str(defender->game.coin), TEXT_COLOR);
    while (sfRenderWindow_isOpen(defender->window.window) && \
    defender->scene_id == GAME_ID && defender->loose == false) {
        game_event_management(defender->window.window, defender->window.event, \
        defender);
        sfRenderWindow_clear(defender->window.window, sfBlack);
        if (defender->game.pause_menu.displayed == false)
            game_manager(defender);
        if (does_continue(defender) == false)
            break;
        drawing_all_sprite(defender);
    }
    destroy_game(defender->game);
    return (0);
}

void scene_manager(defender_t *defender)
{
    if (sfRenderWindow_isOpen(defender->window.window) == sfFalse)
        defender->scene_id = EXIT_ID;
    switch (defender->scene_id) {
    case EXIT_ID:
        end_game(defender);
        break;
    case MAIN_MENU_ID:
        main_menu_display(defender);
        scene_manager(defender);
        break;
    case GAME_ID:
        game_display(defender);
        scene_manager(defender);
        break;
    }
}
