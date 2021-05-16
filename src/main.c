/*
** EPITECH PROJECT, 2020
** Defender
** File description:
** main.c
*/
#include "defender.h"

void destroy_background(my_background_t *background)
{
    for (int i = 0; i < 4; i++) {
        sfClock_destroy(background[i].clock);
        sfSprite_destroy(background[i].sprite);
        sfTexture_destroy(background[i].texture);
    }
    free(background);
}

void destroy_game(game_t game)
{
    sfText_destroy(game.text_score);
    sfText_destroy(game.text_coin);
    sfSprite_destroy(game.sprite_energy);
    sfTexture_destroy(game.text_energy);
    destroy_button(game.pause_btn);
    destroy_button(game.skills_btn);
    destroy_mini_menu(game.tower_menu, 5);
    destroy_mini_menu(game.pause_menu, 4);
    destroy_mini_menu(game.skills_menu, 11);
    destroy_all_enemies(&(game.enemies));
    destroy_all_towers(&(game.towers));
    destroy_all_towers(&(game.temp));
    destroy_all_projectiles(&(game.projectiles));
}

void end_game(defender_t *defender)
{
    destroy_defender(defender);
}

void give_help_for_bambino(void)
{
    my_putstr("\nHello you!\n\nYou were chosen to defend the earth ");
    my_putstr("and humanize it from alien attack!\n");
    my_putstr("To do this you have to defend the space base with ");
    my_putstr("turrets that run on energy.\nBut beware the energy is not ");
    my_putstr("unlimited! It's up to you to find it!\n\n");
    my_putstr("TYPE OF TURRETS :\n\tLaser turrets:\n\t\tAttack step by step,");
    my_putstr("attack single enemy, have a large range and does medium damage");
    my_putstr(".\n\tEnergy thrower:\n\t\tYes with a techno alien we ");
    my_putstr("can do flamme in space! This turret make continuous ");
    my_putstr("attack, slow enemy, does little damage and have a little ");
    my_putstr("range.\n\tRocket launcher:\n\t\tThis turret make heavy");
    my_putstr(" dammage for all enemys who can be in the explosion. It have");
    my_putstr(" a medium range, slow attack and make a zone damage.\n\t");
    my_putstr("Magnetic Orbiter Universal Light Induction (or M.O.U.L.I.):");
    my_putstr("\n\t\tThis turret make no dammage but it");
    my_putstr("give you energy from time to time.\n\n");
    my_putstr("You can sell our turrets but it don't give you all of the");
    my_putstr(" energy spent.\n");
    my_putstr("Your base give you a little bit of energy sometimes\n");
    my_putstr("\nGood Luck and try to don't die !\n\n");
}

int main(int ac, char **av)
{
    defender_t defender;

    srand((unsigned int) ((size_t)&defender));
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h') {
        give_help_for_bambino();
        return (84);
    }
    if (ac != 1)
        return (84);
    if (init_defender_struct(&defender) == EXIT_ID)
        return (84);
    scene_manager(&defender);
}
